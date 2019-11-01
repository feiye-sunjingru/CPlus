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
		void show(){ // ��ʾ�˻���Ϣ
			cout << id << "\tBalance:" << balance;
		}
		void record(const Date& date, double amount, const string& desc){
			amount = (amount+0.5)/100; // ����С�������λ
			balance += amount;
		  	total += amount;
			date.show();
			cout <<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<< endl;
		}
		
		virtual void deposit(const Date& date, double amount, const string& desc)=0; // ֻҪ��ȷ�ϵĶ������id
		virtual void withdraw(const Date& date, double amount, const string& desc)=0;
		virtual void settle(const Date& date)=0; // ����
		static double getTotal(){
			return total;
		}

	private:
		Date date;
		string id;
		double balance; // �˻���� 
		static double total;
};

class SavingsAccount:public Account{  // �����˻� 
	public:
		SavingsAccount(const Date& date, const string& id, double rate);
		double getRate() const{return rate;}
		virtual void deposit(const Date& date, double amount, const string& desc); // ֻҪ��ȷ�ϵĶ������id
		virtual void withdraw(const Date& date, double amount, const string& desc);
		virtual void settle(const Date& date); // ����
	private:
		double rate;
		Accumulator acc;
};

class CreditAccount:public Account{  // ���ÿ��˻� 
	public:
		CreditAccount(const Date& date, const string& id, double fee, double rate, double credit);
		double getFee(){return fee;}
		double getRate(){return rate;}
		double getCredit(){return credit;}
		virtual void deposit(const Date& date, double amount, const string& desc); // ֻҪ��ȷ�ϵĶ������id
		virtual void withdraw(const Date& date, double amount, const string& desc);
		virtual void settle(const Date& date); // ����
		void show(); 
	private: 
		double fee; // ���
		double rate; // ����
		double credit; // ���ö�� 
		Accumulator acc;
};

#endif