// test.cpp
#include <iostream>
#include "client.h"
using namespace std;

char Client::ServerName = 'B'; 
int Client::ClientNum = 10000; 

int main(int argc, char *argv[]){
	Client cli;
	cli.show();

	cli.ChangeServerName('A');
	cli.show();
	return 0;
}
