// account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__ 
#include <string>
#include "date.h"
#include "accumulator.h"

class Account{
	protected:
		// ����������õĹ��캯����idΪ�˻� 
		Account(const Date& date, const string& id);
		// ��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵�� 
		void record(const Date& date, double amount, const string& desc);
		// ���������Ϣ 
		void error(const string& msg) const; 
	public:
		const string& getId() const{ // �˻�id
			return id; 
		}  
		double getBalance() const{ // �˻���� 
			return balance;
		}
		// ��ʾ�˻���Ϣ 
		void show() const;
		static double getTotal(){ // �˻��ܽ��
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
		void deposit(const Date& date, double amount, const string& desc); // ������ 
		void withdraw(const Date& date, double amount, const string& desc); // ȡ���ֽ� 
		void settle(const Date& date); // ������㣬ÿ��1��1�յ���һ�θú��� 
	private:
		Accumulator acc;  // ����������Ϣ���ۼ��� 
		double rate; // ���������� 
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
		double getAvailableCredit() const{ // ���õ����ö��
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
