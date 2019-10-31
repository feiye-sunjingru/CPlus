// acount.cpp
#include <iostream>
#include <cmath> 
#include "account.h"
using namespace std;

double SavingsAccount::total = 0;
// SavingsAccount����س�Ա������ʵ��

SavingsAccount::SavingsAccount(const Date& date, string id, double rate):
	id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
	cout<<date.getYear()<<date.getMonth()<<date.getDay()<<"\t#"<<id<<" is created"<<endl;
}

// ��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵�� 
void SavingsAccount::record(const Date &date, double amount, const string &desc){
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount*100+0.5)/100; // ����С�������λ	
	balance += amount;
	total += amount;
	cout<<date.getYear()<<date.getMonth()<<date.getMonth()<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}

void SavingsAccount::deposite(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
} 

void SavingsAccount::withdraw(const Date &date, double amount, const string& desc){
	if(amount > getBalance()){
		cout<<"Error:not enough money"<<endl;
	}else{
		record(date, -amount, desc);
	}
}

void SavingsAccount::settle(const Date & date){
	accumulation += accumulate(date);
    double settle = (accumulation/365)*rate;
    cout<<id<<"������Ϣ:"<<settle<<endl;
    deposite(date,settle,"interest");
} 

void SavingsAccount::show() const{ //����˻���Ϣ
    cout<<"�ʺ�:"<<id<<endl<<"���:"<<balance<<endl;
}

double SavingsAccount::getTotal(){
	return total;
}