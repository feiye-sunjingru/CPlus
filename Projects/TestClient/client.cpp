// client.cpp 实现类
# include "Client.h"
# include <iostream>

using namespace std;

Client::Client(){
	cout<<"构造了一个Client!"<<endl;
}

Client::~Client(){
	cout<<"析构了一个Client!"<<endl;
}

void Client::ChangeServerName(char tmp){
	Client::ServerName = tmp;
	Client::ClientNum++;	
	cout<<"设置了一个Client!"<<endl;	
}

void Client::show(){
	cout<<"ServerName:"<<ServerName<<", ClientNum:"<<ClientNum<<endl; 
}