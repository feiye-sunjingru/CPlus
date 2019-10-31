// main.cpp
#include <iostream>
#include "date.h"
#include "account.h"
using namespace std;

int main(){
	Date date(2008, 11, 1);
	// 建立几个账户
	SavingsAccount accounts[] = {
		SavingsAccount(date, "S3725217", 0.015),
		SavingsAccount(date, "02342342", 0.015)
	};
	const int n = sizeof(accounts)/sizeof(SavingsAccount); // 账户总数 
	
	// 11月份的几笔账目
	accounts[0].deposite(Date(2018,11,5),5000,"salary");
    accounts[1].deposite(Date(2018,11,25),10000,"sell stock 0323");
    // 12月份的几笔账目 
    accounts[0].deposite(Date(2018,12,5),5000,"salary");
    accounts[1].withdraw(Date(2018,12,20),4000,"buy a laptop");
    
    // 结算所有账户，并输出各个账户信息
	cout<<endl;
	for(int i=0; i<n; i++){
		accounts[i].settle(Date(2019,1,1));
		accounts[i].show();
		cout<<endl;
	} 
	cout<<"Total:*"<<SavingsAccount::getTotal()<<endl;
	
	return 0;
}
