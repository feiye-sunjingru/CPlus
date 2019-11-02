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
	virtual void settle(Date& date)=0; // ����
	virtual void show(); // �麯����̬�� 
protected:
	string id;
	double balance; // �˻���� 
	static double total;  // �����˻����ܽ�� 
};

class SavingsAccount:public Account{  // �����˻�
public:
	SavingsAccount(Date& date, const string& id, double balance, double rate);
	Date& getLastDate(){return lastDate;}
	const double getRate() {return rate;}
	virtual void deposit(Date& date, double amount, const string& desc);
	virtual void withdraw(Date& date, double amount, const string& desc);
	virtual void settle(Date& date);
	virtual void show();
	double accumulation=0;
    const double accumulate(Date& date); // ���ۼ� 
protected:
	Date lastDate;
	double rate;    //����	
};

class CreditAccount:public Account{  // ���ÿ��˻�
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
	double getDebt(Date& date); // Ƿ����� 
protected:
	Date lastDate;
	double fee; // ���
	double rate; // ����
	double credit; // ���ö�� 
};
#endif
