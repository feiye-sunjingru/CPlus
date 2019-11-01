// account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__ 
#include <string>
#include "date.h"
#include "accumulator.h"

class Account{
	protected:
		// 供派生类调用的构造函数，id为账户 
		Account(const Date& date, const string& id);
		// 记录一笔账，date为日期，amount为金额，desc为说明 
		void record(const Date& date, double amount, const string& desc);
		// 报告错误信息 
		void error(const string& msg) const; 
	public:
		const string& getId() const{ // 账户id
			return id; 
		}  
		double getBalance() const{ // 账户余额 
			return balance;
		}
		// 显示账户信息 
		void show() const;
		static double getTotal(){ // 账户总金额
			return total;
		}   
	
	private:
		string id;
		double balance;
		static double total;  
};

class SavingsAccount: public Account{
	public:
		SavingsAccount(const Date& date, const string& id, double rate);
		double getRate() const{
			return rate;
		}
		void deposit(const Date& date, double amount, const string& desc); // 处理存款 
		void withdraw(const Date& date, double amount, const string& desc); // 取出现金 
		void settle(const Date& date); // 处理结算，每年1月1日调用一次该函数 
	private:
		Accumulator acc;  // 辅助计算利息的累加器 
		double rate; // 存款的年利率 
};

class CreditAccount:public Account{
	public:
		double getDebt() const{
			double balance = getBalance();
			return balance<0?balance:0; 
		} 
		CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);
		double getCredit() const{
			return credit;
		}
		double getRate() const{
			return rate;
		}
		double getFee() const{
			return fee;
		}
		double getAvailableCredit() const{ // 可用的信用额度
			if(getBalance()<0){
				return credit+getBalance();
			}else{
				return credit;
			}
		} 
		void deposit(const Date& date, double amount, const string& desc);
		void withdraw(const Date& date, double amount, const string& desc);
		void settle(const Date& date);
		void show() const;
	private:
		Accumulator acc;
		double credit;
		double rate;
		double fee;
};

#endif
