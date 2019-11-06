// account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <map>
#include "accumulator.h"
#include "date.h"
using namespace std;

class Account; // 前置声明 

class AccountRecord{ // 账目记录 
public:
	AccountRecord(const Date &date, const Account* account, double amount, double balance, const string &desc);
	void show()const; //输出当前记录
private:
	Date date; // 日期
	const Account* account; // 账户 
	double amount; //金额
	double balance; //余额
	string desc; //描述
}; 

typedef multimap<Date, AccountRecord> RecordMap;

class Account{ //账户类
public:
	const string& getId() {return id;}
	const double getBalance() {return balance;}
	static double getTotal() {return total;}
	//存入现金，date为日期，amount为金额，desc为款项说明
	virtual void deposit(Date& date, double amount, const string& desc)=0;
	//取出现金，date为日期，amount为金额，desc为款项说明
	virtual void withdraw(Date& date, double amount, const string& desc)=0;
	//结算，每月结算一次，date为结算日期
	virtual void settle(Date& date)=0;
	//显示账户信息
	virtual void show(ostream &out)const;; // 虚函数动态绑定 
	//查询指定时间内的账目记录
	static void query(const Date &begin, const Date &end);
protected:
	//供派生类调用的构造函数
	Account(const string& id, double balance);
	//记录一笔账，date为日期，amount为金额，desc为说明
	void record(const Date &date, double amount, const string &desc);
	//报告错误信息
	void error(const string &msg)const;
private:
	string id; //账户
	double balance; // 账户余额 
	static double total;  // 所有账户的总金额 
	static RecordMap recordMap; // 账目记录 
};

inline ostream& operator <<(ostream &out, const Account&account){
	account.show(out);
	return out;
}

class SavingsAccount:public Account{  // 储蓄账户
public:
	SavingsAccount(Date& date, const string& id, double balance, double rate);
	const double getRate() {return rate;}
	//存入现金
	virtual void deposit(Date& date, double amount, const string& desc);
	//取出现金
	virtual void withdraw(Date& date, double amount, const string& desc);
	//结算利息，每年1月1日调用一次该函数
	virtual void settle(Date& date);
	virtual void show();
	double accumulation=0;
    const double accumulate(Date& date); // 做累加 
private:
	Accumulator acc; //辅助计算利息的累加器
	double rate;    //利率	
};

class CreditAccount:public Account{  // 信用卡账户
public:
	CreditAccount(Date& date, const string& id, double balance, double fee, double rate, double credit);
	//Date& getLastDate(){return lastDate;}
	const double getFee() {return fee;}
	const double getRate() {return rate;}
	const double getCredit() {return credit;}
	double getAvailableCredit(){ //获得可用信用额度
        if (getBalance() < 0){
        	return credit + getBalance();
        }else{
        	return credit;
        }            
    }
    //存入现金
	virtual void deposit(Date& date, double amount, const string& desc);
	//取出现金
	virtual void withdraw(Date& date, double amount, const string& desc);
	//结算利息和年费，每月1日调用一次该函数
	virtual void settle(Date& date);
	virtual void show();
private:
	Accumulator acc; //辅助计算利息的累加器
	double fee; // 信用卡年费
	double rate; // 欠款的日利率
	double credit; // 可用额度 
	double getDebt(Date& date){// 获得欠款额 
		double balance = getBalance();
        return (balance < 0 ? balance : 0);
	} 
};


class AccountException: public runtime_error{
public:
	AccountException(const Account* account, const string &msg): runtime_error(msg), account(account)
	const Account* getAccount()const{
		return account;
	}
private:
	const Account* account;
};

#endif
