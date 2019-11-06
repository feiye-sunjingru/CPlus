// account.cpp
#include <string>
#include <iostream>
#include "date.h"
#include "account.h"

// AccountRecord���ʵ��
AccountRecord::AccountRecord(const Date &date,const Account* account,double amount,double balance,const string &desc):\
	date(date), account(account), amount(amount), balance(balance), desc(desc){} 

void AccountRecord::show()const{
	cout<<"\t�˻���"<<account->getId()<<"\t amount��"<<amount<<"\t�˻���"<<balance<<"\t desc:"<<desc<<endl; 
}

// Account���ʵ�� 
double Account::total = 0;
RecordMap Account::recordMap; 

Account::Account(const string& id, double balance): id(id), balance(balance){}

double Account::getTotal(){
	cout<<"\t���˻��ܶ�:"<<total<<endl;
	return total;
}

void Account::show(){
	cout<<"\t�˺�:"<<getId()<<"  ���:"<<getBalance()<<endl;
}

void Account::record(const Date &date, double amount, const string &desc){
    amount = floor(amount * 100 + 0.5) / 100; //����С�������λ
    balance += amount;
    total += amount;
    date.show();
    cout << "\t�˺�:" << id << "\tamount:" << amount << "\t�˻���" << balance << "\t desc:" << desc << endl;
}

void Account::error(const string &msg)const{
    throw AccountException(this, msg);
}

void Account::query(const Date &begin, const Date &end){
    if (begin <= end){
        RecordMap::iterator iter1 = recordMap.lower_bound(begin);
        RecordMap::iterator iter2 = recordMap.upper_bound(end);
        for (RecordMap::iterator iter = iter1;iter != iter2;++iter){
        	iter->second.show();
        }   
    }
}

// SavingsAccount�����Ա����
SavingsAccount::SavingsAccount(Date& date, const string& id, double balance, double rate)
	:Account(id, balance), rate(rate),lastDate(date){
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
	cout<<"\t�˺�"<<id<<"�����ɹ�!"<<endl;
}

void SavingsAccount::deposit(Date& date, double amount, const string& desc){
	record(date, amount, desc);
    acc.change(date, getBalance());
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
	cout<<"\t"<<id<<"\t����:"<<amount<<"\t���:"<<balance<<"\t"<<desc<<endl;
}

void SavingsAccount::withdraw(Date& date, double amount, const string& desc){
	if (amount > getBalance()){
        error("not enough money");
    }else{
    	record(date, -amount, desc);
    	acc.change(date, getBalance());
    }
 	
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
    cout<<"\t"<<id<<"\tȡ��:"<<amount<<"\t���:"<<balance<<"\t"<<desc<<endl;
} 

void SavingsAccount::settle(Date& tmpdate){  // ��������Ϣ,����һ�겻�� 
	 if (date.getMonth() == 1){        //ÿ���1�¼���һ����Ϣ
        double interest = acc.getSum(date)*rate / (date - Date(date.getYear() - 1, 1, 1));
        if (interest != 0){
        	record(date, interest, "interest");	
        }  
        acc.reset(date, getBalance());
    }
} 

void SavingsAccount::show(){
    Account::show();
}

// CreditAccount���ÿ���
CreditAccount::CreditAccount(Date& date, const string& id, double balance, double fee, double rate, double credit)
	:Account(id, balance), fee(fee), rate(rate), credit(credit), lastDate(date){
	cout<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl;
    cout<<"\t�˺�"<<id<<"�����ɹ�!"<<endl;	
}

void CreditAccount::deposit(Date& date, double amount, const string& desc){
	record(date, amount, desc);
    acc.change(date, getDebt());
    date.show();
    cout<<"\t"<<id<<"\t���ÿ�����:"<<amount<<"\t��"<<balance<<
		"\t�����ö��:"<<credit<<"\t"<<desc<<endl;
}

void CreditAccount::withdraw(Date& date, double amount, const string& desc){
	settle(date);
    if(credit<=0 || amount>credit){
        date.show();
        cout<<"\t"<<id<<"\t���ÿ����ö�Ȳ���!"<<endl;
    }else{
        record(date, -amount, desc);
        acc.change(date, getDebt());
        date.show();
        cout<<"\t"<<id<<"\t���ÿ����:"<<amount<<"\t��"<<balance<<
			"\t�����ö��:"<<credit<<endl;
        total -= amount;
    }
}

void CreditAccount::settle(Date& date){
	double interest = acc.getSum(date)*rate;
    if (interest != 0){
    	record(date, interest, "interest");
    } 
    if (date.getMonth() == 1){
    	record(date, -fee, "annual fee");
    }  
    acc.reset(date, getDebt());
}

void CreditAccount::show(){
	Account::show();  // ���û������ʾ 
}