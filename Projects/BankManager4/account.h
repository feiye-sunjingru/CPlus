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
	virtual void deposit(const Date& date, double amount, const string& desc)=0;
	virtual void withdraw(const Date& date, double amount, const string& desc)=0;
	virtual void settle(const Date& date)=0; // ����
	virtual void show(); // �麯����̬�� 
protected:
	string id;
	double balance; // �˻���� 
	static double total;  // �����˻����ܽ�� 
};

class SavingsAccount:public Account{  // �����˻�
public:
	SavingsAccount(const Date& date, const string& id, double balance, double rate);
	const Date& getLastDate(){return lastDate;}
	const double getRate() {return rate;}
	virtual void deposit(const Date& date, double amount, const string& desc);
	virtual void withdraw(const Date& date, double amount, const string& desc);
	virtual void settle(const Date& date);
	virtual void show();
	double accumulation=0;
    const double accumulate(const Date& date); // ���ۼ� 
protected:
	Date lastDate;
	double rate;    //����	
};

class CreditAccount:public Account{  // ���ÿ��˻�
public:
	CreditAccount(const Date& date, const string& id, double balance, double fee, double rate, double credit);
	const Date& getLastDate(){return lastDate;}
	const double getFee() {return fee;}
	const double getRate() {return rate;}
	const double getCredit() {return credit;}
	virtual void deposit(const Date& date, double amount, const string& desc);
	virtual void withdraw(const Date& date, double amount, const string& desc);
	virtual void settle(const Date& date);
	virtual void show();
	double getDebt(Date date) const; // Ƿ����� 
protected:
	Date lastDate;
	double fee; // ���
	double rate; // ����
	double credit; // ���ö�� 
};
#endif
