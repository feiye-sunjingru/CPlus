// main.cpp
#include <iostream>
#include "date.h"
#include "account.h"
using namespace std;

int main(){
	Date date(2008, 11, 1);
	// ���������˻�
	SavingsAccount accounts[] = {
		SavingsAccount(date, "S3725217", 0.015),
		SavingsAccount(date, "02342342", 0.015)
	};
	const int n = sizeof(accounts)/sizeof(SavingsAccount); // �˻����� 
	
	// 11�·ݵļ�����Ŀ
	accounts[0].deposite(Date(2018,11,5),5000,"salary");
    accounts[1].deposite(Date(2018,11,25),10000,"sell stock 0323");
    // 12�·ݵļ�����Ŀ 
    accounts[0].deposite(Date(2018,12,5),5000,"salary");
    accounts[1].withdraw(Date(2018,12,20),4000,"buy a laptop");
    
    // ���������˻�������������˻���Ϣ
	cout<<endl;
	for(int i=0; i<n; i++){
		accounts[i].settle(Date(2019,1,1));
		accounts[i].show();
		cout<<endl;
	} 
	cout<<"Total:*"<<SavingsAccount::getTotal()<<endl;
	
	return 0;
}
