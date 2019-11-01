// account.cpp
#include "account.h" 

double Account::total = 0;

SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate)
	:Account(date, id), rate(rate), acc(date, 0){} // value=0
	
void SavingsAccount::deposit(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
	acc.change(date, getBalance()); // change��ʱ������һ��value 
}

void SavingsAccount::withdraw(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
}

void SavingsAccount::settle(const Date& tmpdate){  // ��������Ϣ,����һ�겻�� 
	//double interest = acc.getSum(tmpdate)*rate / tmpdate.distance(Date(tmpdate.getYear()-1,1,1));
	double interest = acc.getSum(tmpdate)*rate / (tmpdate-Date(tmpdate.getYear()-1,1,1));

	if(interest != 0){
		record(tmpdate, interest, "interest"); 
	}
	acc.reset(tmpdate, getBalance()); // ��һ�μ�һ������*value 
}

CreditAccount::CreditAccount(const Date& date, const string& id, double fee, double rate, double credit)
	:Account(date, id), fee(fee), rate(rate), credit(credit), acc(date, 0){}
	
void CreditAccount::deposit(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
	acc.change(date, getCredit());
} 

void CreditAccount::withdraw(const Date& date, double amount, const string& desc){
	if(amount-getBalance() > credit){  // ���ܳ������ 
		error("not enough credit"); 
	}else{
		record(date, -amount, desc);
		acc.change(date, getCredit());
	}
}

void CreditAccount::settle(const Date& date){
	double interest = acc.getSum(date) * rate;
	if(interest!=0){
		record(date, interest, "interest");
	}
	if(date.getMonth()==1){
		record(date, -fee, "annual fee");
	}
	acc.reset(date, getCredit());
}

void CreditAccount::show(){
	Account::show();  // ���û������ʾ 
	cout<<"\tAvailable credit:"<<getCredit();
}