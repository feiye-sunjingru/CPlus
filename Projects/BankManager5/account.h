// account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <map>
#include "accumulator.h"
#include "date.h"
using namespace std;

class Account; // ǰ������ 

class AccountRecord{ // ��Ŀ��¼ 
public:
	AccountRecord(const Date &date, const Account* account, double amount, double balance, const string &desc);
	void show()const; //�����ǰ��¼
private:
	Date date; // ����
	const Account* account; // �˻� 
	double amount; //���
	double balance; //���
	string desc; //����
}; 

typedef multimap<Date, AccountRecord> RecordMap;

class Account{ //�˻���
public:
	const string& getId() {return id;}
	const double getBalance() {return balance;}
	static double getTotal() {return total;}
	//�����ֽ�dateΪ���ڣ�amountΪ��descΪ����˵��
	virtual void deposit(Date& date, double amount, const string& desc)=0;
	//ȡ���ֽ�dateΪ���ڣ�amountΪ��descΪ����˵��
	virtual void withdraw(Date& date, double amount, const string& desc)=0;
	//���㣬ÿ�½���һ�Σ�dateΪ��������
	virtual void settle(Date& date)=0;
	//��ʾ�˻���Ϣ
	virtual void show(ostream &out)const;; // �麯����̬�� 
	//��ѯָ��ʱ���ڵ���Ŀ��¼
	static void query(const Date &begin, const Date &end);
protected:
	//����������õĹ��캯��
	Account(const string& id, double balance);
	//��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date &date, double amount, const string &desc);
	//���������Ϣ
	void error(const string &msg)const;
private:
	string id; //�˻�
	double balance; // �˻���� 
	static double total;  // �����˻����ܽ�� 
	static RecordMap recordMap; // ��Ŀ��¼ 
};

inline ostream& operator <<(ostream &out, const Account&account){
	account.show(out);
	return out;
}

class SavingsAccount:public Account{  // �����˻�
public:
	SavingsAccount(Date& date, const string& id, double balance, double rate);
	const double getRate() {return rate;}
	//�����ֽ�
	virtual void deposit(Date& date, double amount, const string& desc);
	//ȡ���ֽ�
	virtual void withdraw(Date& date, double amount, const string& desc);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	virtual void settle(Date& date);
	virtual void show();
	double accumulation=0;
    const double accumulate(Date& date); // ���ۼ� 
private:
	Accumulator acc; //����������Ϣ���ۼ���
	double rate;    //����	
};

class CreditAccount:public Account{  // ���ÿ��˻�
public:
	CreditAccount(Date& date, const string& id, double balance, double fee, double rate, double credit);
	//Date& getLastDate(){return lastDate;}
	const double getFee() {return fee;}
	const double getRate() {return rate;}
	const double getCredit() {return credit;}
	double getAvailableCredit(){ //��ÿ������ö��
        if (getBalance() < 0){
        	return credit + getBalance();
        }else{
        	return credit;
        }            
    }
    //�����ֽ�
	virtual void deposit(Date& date, double amount, const string& desc);
	//ȡ���ֽ�
	virtual void withdraw(Date& date, double amount, const string& desc);
	//������Ϣ����ѣ�ÿ��1�յ���һ�θú���
	virtual void settle(Date& date);
	virtual void show();
private:
	Accumulator acc; //����������Ϣ���ۼ���
	double fee; // ���ÿ����
	double rate; // Ƿ���������
	double credit; // ���ö�� 
	double getDebt(Date& date){// ���Ƿ��� 
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