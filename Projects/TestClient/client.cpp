// client.cpp ʵ����
# include "Client.h"
# include <iostream>

using namespace std;

Client::Client(){
	cout<<"������һ��Client!"<<endl;
}

Client::~Client(){
	cout<<"������һ��Client!"<<endl;
}

void Client::ChangeServerName(char tmp){
	Client::ServerName = tmp;
	Client::ClientNum++;	
	cout<<"������һ��Client!"<<endl;	
}

void Client::show(){
	cout<<"ServerName:"<<ServerName<<", ClientNum:"<<ClientNum<<endl; 
}