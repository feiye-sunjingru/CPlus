// account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "date.h"
#include "accumulator.h"

class Account{
	public:
		Account(const Date& date, const string& id)
			:date(date), id(id), balance(0){
			date.show();
			cout << "\t#" << id << "  created" << endl;
		}
		void error(const string& msg){
			cout << "Error(#" << id << "):" << msg << endl;
		}
		const string& getId(){return id;}
		const double getBalance(){return balance;}
		void show(){ // 显示账户信息
			cout << id << "\tBalance:" << balance;
		}
		void record(const Date& date, double amount, const string& desc){
			amount = (amount+0.5)/100; // 保留小数点后两位
			balance += amount;
		  	total += amount;
			date.show();
			cout <<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<< endl;
		}
		
		virtual void deposit(const Date& date, double amount, const string& desc)=0; // 只要是确认的对象就有id
		virtual void withdraw(const Date& date, double amount, const string& desc)=0;
		virtual void settle(const Date& date)=0; // 结算
		static double getTotal(){
			return total;
		}

	private:
		Date date;
		string id;
		double balance; // 账户余额 
		static double total;
};

class SavingsAccount:public Account{  // 储蓄账户 
	public:
		SavingsAccount(const Date& date, const string& id, double rate);
		double getRate() const{return rate;}
		virtual void deposit(const Date& date, double amount, const string& desc); // 只要是确认的对象就有id
		virtual void withdraw(const Date& date, double amount, const string& desc);
		virtual void settle(const Date& date); // 结算
	private:
		double rate;
		Accumulator acc;
};

class CreditAccount:public Account{  // 信用卡账户 
	public:
		CreditAccount(const Date& date, const string& id, double fee, double rate, double credit);
		double getFee(){return fee;}
		double getRate(){return rate;}
		double getCredit(){return credit;}
		virtual void deposit(const Date& date, double amount, const string& desc); // 只要是确认的对象就有id
		virtual void withdraw(const Date& date, double amount, const string& desc);
		virtual void settle(const Date& date); // 结算
		void show(); 
	private: 
		double fee; // 年费
		double rate; // 利率
		double credit; // 信用额度 
		Accumulator acc;
};

#endif