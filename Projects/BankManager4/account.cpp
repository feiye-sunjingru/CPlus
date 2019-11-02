// account.cpp
#include <string>
#include <iostream>
#include "date.h"
#include "account.h"


// Account类的实现 
double Account::total = 0;

Account::Account(const string& id, double balance): id(id), balance(balance){}

double Account::getTotal(){
	cout<<"\t各账户总额:"<<total<<endl;
	return total;
}

void Account::show(){
	cout<<"\t账号:"<<getId()<<"  余额:"<<getBalance()<<endl;
}

// SavingsAccount储蓄卡成员函数
SavingsAccount::SavingsAccount(Date& date, const string& id, double balance, double rate)
	:Account(id, balance), rate(rate),lastDate(date){
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
	cout<<"\t账号"<<id<<"创建成功!"<<endl;
}

const double SavingsAccount::accumulate(Date& date){
	return (date-lastDate)*balance;  // 上次到这次balance*时间 
}

void SavingsAccount::deposit(Date& date, double amount, const string& desc){
	accumulation+=accumulate(date);
	balance+=amount;
	lastDate = date;
	total+=amount;
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
	cout<<"\t"<<id<<"\t存入:"<<amount<<"\t余额:"<<balance<<"\t"<<desc<<endl;
}

void SavingsAccount::withdraw(Date& date, double amount, const string& desc){
	accumulation+=accumulate(date);
	balance-=amount;
	lastDate = date;
	total-=amount;
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
    cout<<"\t"<<id<<"\t取出:"<<amount<<"\t余额:"<<balance<<"\t"<<desc<<endl;
} 

void SavingsAccount::settle(Date& tmpdate){  // 按年算利息,假设一年不变 
	double settle = 0;
	double tmpAccumulation = accumulation;
	if(tmpdate.getYear()>lastDate.getYear()){ // 滚存 
		int years = tmpdate.getYear()-lastDate.getYear();
		for(int i=1; i<=years; i++){
			int days = tmpdate.isLeepYear()?366:365;
 			accumulation += accumulate(tmpdate);  // 到当前日期的累加值 
   			settle = accumulation/days*rate;
   			accumulation += settle;
   			tmpdate.setYear(tmpdate.getYear()+1);
		} 
	} 
	cout<<tmpdate.getYear()<<"/"<<tmpdate.getMonth()<<"/"<<tmpdate.getDay()<<endl;
    cout<<"\t"<<id<<"\t结算利息:"<<(accumulation-tmpAccumulation)<<endl;
    deposit(tmpdate,settle,"");
} 

void SavingsAccount::show(){
    Account::show();
}

// CreditAccount信用卡类
CreditAccount::CreditAccount(Date& date, const string& id, double balance, double fee, double rate, double credit)
	:Account(id, balance), fee(fee), rate(rate), credit(credit), lastDate(date){
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
    cout<<"\t账号"<<id<<"创建成功!"<<endl;	
}

void CreditAccount::deposit(Date& date, double amount, const string& desc){
	settle(date);
    balance += amount;
    if((credit+amount) <= 10000){
        credit = credit + amount;
    }else{
        credit = 10000; // 额度最多不超过10000 
    }
    total += amount;
    date.show();
    cout<<"\t"<<id<<"\t信用卡还款:"<<amount<<"\t余额："<<balance<<
		"\t还可用额度:"<<credit<<"\t"<<desc<<endl;
}

void CreditAccount::withdraw(Date& date, double amount, const string& desc){
	settle(date);
    if(credit<=0 || amount>credit){
        date.show();
        cout<<"\t"<<id<<"\t信用卡可用额度不足!"<<endl;
    }else{
        balance -= amount;
        credit -= amount;
        date.show();
        cout<<"\t"<<id<<"\t信用卡借款:"<<amount<<"\t余额："<<balance<<
			"\t还可用额度:"<<credit<<endl;
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
	Account::show();  // 调用基类的显示 
}