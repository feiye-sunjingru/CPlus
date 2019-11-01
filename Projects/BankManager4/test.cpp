// test.cpp
#include <iostream>
#include <string>
#include "date.h"
#include "account.h"
using namespace std;

int main(){
    Date d01(2008,11,5),d02(2008,12,5),d11(2008,11,25);
	Date d12(2008,12,20),d2(2009,1,1),dc1(2008,11,15),dc2(2008,12,1);
    Account *ptr;           //定义基类指针
    cout<<"--------------------------------"<<"1001"<<
		"------------------------------"<<endl;
    SavingsAccount s0(d01,"1001",0,0.015);
    ptr=&s0;                //基类指针调用
    ptr->deposit(d01, 5000, "d01 save");
    ptr->deposit(d02, 5500, "d02 save");
    ptr->settle(d2);
    d2.show();
    ptr->show();
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------"<<"1002"<<"------------------------------"<<endl;
    SavingsAccount s1(d01,"1002",0,0.015);
    ptr=&s1;
    ptr->deposit(d11, 10000, "d11 save");
    ptr->withdraw(d12, 4000, "d12 fetch");
    ptr->settle(d2);
    d2.show();
    ptr->show();
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------"<<"1003"<<"------------------------------"<<endl;
    CreditAccount c0(d01,"1003",0,10000,0.0005,50);
    ptr=&c0;
    ptr->deposit(dc1, 2000, "dc1 fetch");
    ptr->withdraw(dc2, 2000, "dc2 fetch");
    ptr->withdraw(dc2, -c0.getDebt(dc2), "dc2 fetch");    //结算利息
    ptr->settle(d2);
    d2.show();
    ptr->show();
    cout<<"------------------------------------------------------------------"<<endl;
    d2.show();
    ptr->getTotal();
    cout<<"------------------------------------------------------------------"<<endl;
}
