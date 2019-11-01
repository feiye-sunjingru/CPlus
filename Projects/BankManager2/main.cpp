#include <iostream>
#include <string>
#include "account.h"
using namespace std; 
int main(){
	Date date(2008, 11, 1);
	// 建立几个账户
	//SavingsAccount sa1(date, "S3725217", 0.015);
	//SavingsAccount sa2(date, "02342342", 0.015);
	CreditAccount ca(date, "C5392394", 1000, 0.05, 50);
	//const int n = sizeof(accounts)/sizeof(SavingsAccount); // 账户总数 
	
	// 11月份的几笔账目
	//sa1.deposit(Date(2018,11,5),5000, "salary");
	ca.withdraw(Date(2018,11,15),2000, "buy a cell");
    //sa2.deposit(Date(2018,11,25),10000,"sell stock 0323");
    
    // 结算信用卡
	ca.settle(Date(2008,12,1)); 
    
    // 12月份的几笔账目 
    ca.deposit(Date(2018,12,1),2016,"repay the credit");
    //sa1.deposit(Date(2008, 12, 1), 5500, "salary");
    
    // 结算所有的账户并输出各个账户信息 
    //sa1.settle(Date(2009, 1, 1));
    //sa2.settle(Date(2009, 1, 1));
   	ca.settle(Date(2019,1,1));
   	ca.withdraw(Date(2019,3,1),2019,"fetch");
    // 输出各个账户信息
	cout<<endl;
	//sa1.show(); cout<<endl;
	//sa2.show(); cout<<endl;
	ca.show(); cout<<endl;
	cout<<"Total:*"<<Account::getTotal()<<endl;
	
	return 0;
}
