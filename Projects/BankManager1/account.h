#ifndef __ACCOUNT_H__  // 避免重复包含 
#define __ACCOUNT_H__
#include <string> 
#include "date.h" 
using namespace std;

class SavingsAccount{ // 储蓄账户类 
	public:
		void record(const Date &date, double amount, const string &desc);  // desc为各笔账目增加说明文字 
		void error(string msg) const;  // 报告错误 
	 	double accumulate (const Date& date){
	 		return balance*lastDate.distance(date);
	 	}
		SavingsAccount(const Date &date, string id, double rate);
		const string& getId() {
			return id;
		}
		double getBalance() const{
			return balance;
		}
		double getRate() const{
			return rate;
		}
		void show() const;
		void deposite(const Date& date, double amount, const string& desc);
		void withdraw(const Date& date, double amount, const string& desc);
		void settle(const Date& date);  // 账户结算 
		static double getTotal();
	private:
		string id;  // 账号，可能以0开头 
		double balance;  // 余额 
		double rate; // 存款的年利率 
		Date lastDate; // 上次变更余额的时期 
		double accumulation; // 余额按日累加之和 
		static double total;  // 全体账户共享，所有账户的总金额 
}; 
#endif
