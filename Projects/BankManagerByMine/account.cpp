// account.cpp
#include "account.h" 

double Account::total = 0;

SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate)
	:Account(date, id), rate(rate), acc(date, 0){} // value=0
	
void SavingsAccount::deposit(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
	acc.change(date, getBalance()); // change的时候增加一次value 
}

void SavingsAccount::withdraw(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
}

void SavingsAccount::settle(const Date& tmpdate){  // 按年算利息,假设一年不变 
	//double interest = acc.getSum(tmpdate)*rate / tmpdate.distance(Date(tmpdate.getYear()-1,1,1));
	double interest = acc.getSum(tmpdate)*rate / (tmpdate-Date(tmpdate.getYear()-1,1,1));

	if(interest != 0){
		record(tmpdate, interest, "interest"); 
	}
	acc.reset(tmpdate, getBalance()); // 存一次加一次天数*value 
}

CreditAccount::CreditAccount(const Date& date, const string& id, double fee, double rate, double credit)
	:Account(date, id), fee(fee), rate(rate), credit(credit), acc(date, 0){}
	
void CreditAccount::deposit(const Date& date, double amount, const string& desc){
	record(date, amount, desc);
	acc.change(date, getCredit());
} 

void CreditAccount::withdraw(const Date& date, double amount, const string& desc){
	if(amount-getBalance() > credit){  // 不能超过额度 
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
	Account::show();  // 调用基类的显示 
	cout<<"\tAvailable credit:"<<getCredit();
}