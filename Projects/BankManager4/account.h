// account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include "date.h"
using namespace std;

class Account{
public:
	Account(const string& id, double balance);
	const string& getId() {return id;}
	const double getBalance() {return balance;}
	static double getTotal();
	virtual void deposit(Date& date, double amount, const string& desc)=0;
	virtual void withdraw(Date& date, double amount, const string& desc)=0;
	virtual void settle(Date& date)=0; // 结算
	virtual void show(); // 虚函数动态绑定 
protected:
	string id;
	double balance; // 账户余额 
	static double total;  // 所有账户的总金额 
};

class SavingsAccount:public Account{  // 储蓄账户
public:
	SavingsAccount(Date& date, const string& id, double balance, double rate);
	Date& getLastDate(){return lastDate;}
	const double getRate() {return rate;}
	virtual void deposit(Date& date, double amount, const string& desc);
	virtual void withdraw(Date& date, double amount, const string& desc);
	virtual void settle(Date& date);
	virtual void show();
	double accumulation=0;
    const double accumulate(Date& date); // 做累加 
protected:
	Date lastDate;
	double rate;    //利率	
};

class CreditAccount:public Account{  // 信用卡账户
public:
	CreditAccount(Date& date, const string& id, double balance, double fee, double rate, double credit);
	Date& getLastDate(){return lastDate;}
	const double getFee() {return fee;}
	const double getRate() {return rate;}
	const double getCredit() {return credit;}
	virtual void deposit(Date& date, double amount, const string& desc);
	virtual void withdraw(Date& date, double amount, const string& desc);
	virtual void settle(Date& date);
	virtual void show();
	double getDebt(Date& date); // 欠款多少 
protected:
	Date lastDate;
	double fee; // 年费
	double rate; // 利率
	double credit; // 可用额度 
};
#endif
