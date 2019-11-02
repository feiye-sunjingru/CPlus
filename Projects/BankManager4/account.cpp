// account.cpp
#include <string>
#include <iostream>
#include "date.h"
#include "account.h"


// Account���ʵ�� 
double Account::total = 0;

Account::Account(const string& id, double balance): id(id), balance(balance){}

double Account::getTotal(){
	cout<<"\t���˻��ܶ�:"<<total<<endl;
	return total;
}

void Account::show(){
	cout<<"\t�˺�:"<<getId()<<"  ���:"<<getBalance()<<endl;
}

// SavingsAccount�����Ա����
SavingsAccount::SavingsAccount(Date& date, const string& id, double balance, double rate)
	:Account(id, balance), rate(rate),lastDate(date){
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
	cout<<"\t�˺�"<<id<<"�����ɹ�!"<<endl;
}

const double SavingsAccount::accumulate(Date& date){
	return (date-lastDate)*balance;  // �ϴε����balance*ʱ�� 
}

void SavingsAccount::deposit(Date& date, double amount, const string& desc){
	accumulation+=accumulate(date);
	balance+=amount;
	lastDate = date;
	total+=amount;
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
	cout<<"\t"<<id<<"\t����:"<<amount<<"\t���:"<<balance<<"\t"<<desc<<endl;
}

void SavingsAccount::withdraw(Date& date, double amount, const string& desc){
	accumulation+=accumulate(date);
	balance-=amount;
	lastDate = date;
	total-=amount;
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
    cout<<"\t"<<id<<"\tȡ��:"<<amount<<"\t���:"<<balance<<"\t"<<desc<<endl;
} 

void SavingsAccount::settle(Date& tmpdate){  // ��������Ϣ,����һ�겻�� 
	double settle = 0;
	double tmpAccumulation = accumulation;
	if(tmpdate.getYear()>lastDate.getYear()){ // ���� 
		int years = tmpdate.getYear()-lastDate.getYear();
		for(int i=1; i<=years; i++){
			int days = tmpdate.isLeepYear()?366:365;
 			accumulation += accumulate(tmpdate);  // ����ǰ���ڵ��ۼ�ֵ 
   			settle = accumulation/days*rate;
   			accumulation += settle;
   			tmpdate.setYear(tmpdate.getYear()+1);
		} 
	} 
	cout<<tmpdate.getYear()<<"/"<<tmpdate.getMonth()<<"/"<<tmpdate.getDay()<<endl;
    cout<<"\t"<<id<<"\t������Ϣ:"<<(accumulation-tmpAccumulation)<<endl;
    deposit(tmpdate,settle,"");
} 

void SavingsAccount::show(){
    Account::show();
}

// CreditAccount���ÿ���
CreditAccount::CreditAccount(Date& date, const string& id, double balance, double fee, double rate, double credit)
	:Account(id, balance), fee(fee), rate(rate), credit(credit), lastDate(date){
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
    cout<<"\t�˺�"<<id<<"�����ɹ�!"<<endl;	
}

void CreditAccount::deposit(Date& date, double amount, const string& desc){
	settle(date);
    balance += amount;
    if((credit+amount) <= 10000){
        credit = credit + amount;
    }else{
        credit = 10000; // �����಻����10000 
    }
    total += amount;
    date.show();
    cout<<"\t"<<id<<"\t���ÿ�����:"<<amount<<"\t��"<<balance<<
		"\t�����ö��:"<<credit<<"\t"<<desc<<endl;
}

void CreditAccount::withdraw(Date& date, double amount, const string& desc){
	settle(date);
    if(credit<=0 || amount>credit){
        date.show();
        cout<<"\t"<<id<<"\t���ÿ����ö�Ȳ���!"<<endl;
    }else{
        balance -= amount;
        credit -= amount;
        date.show();
        cout<<"\t"<<id<<"\t���ÿ����:"<<amount<<"\t��"<<balance<<
			"\t�����ö��:"<<credit<<endl;
        total -= amount;
    }
}

void CreditAccount::settle(Date& date){
	double settle=0;
	if(date.getTotalDays()>lastDate.getTotalDays()) {
		int disYear = lastDate.getDisYears(date);
		int disMonth = lastDate.getDisMonths(date);
		settle += disYear * fee;
		settle -= disMonth * balance * rate;
	}
	balance -= settle;
    lastDate = date;
    total -= settle;
}

double CreditAccount::getDebt(Date& date) {
	settle(date);
	return balance;
}

void CreditAccount::show(){
	Account::show();  // ���û������ʾ 
}