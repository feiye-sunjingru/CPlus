// acount.cpp
#include <iostream>
#include <cmath> 
#include "account.h"
using namespace std;

double SavingsAccount::total = 0;
// SavingsAccount类相关成员函数的实现

SavingsAccount::SavingsAccount(const Date& date, string id, double rate):
	id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
	cout<<date.getYear()<<date.getMonth()<<date.getDay()<<"\t#"<<id<<" is created"<<endl;
}

// 记录一笔账，date为日期，amount为金额，desc为说明 
void SavingsAccount::record(const Date &date, double amount, const string &desc){
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount*100+0.5)/100; // 保留小数点后两位	
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
    cout<<id<<"结算利息:"<<settle<<endl;
    deposite(date,settle,"interest");
} 

void SavingsAccount::show() const{ //输出账户信息
    cout<<"帐号:"<<id<<endl<<"余额:"<<balance<<endl;
}

double SavingsAccount::getTotal(){
	return total;
}