// main.cpp
#include <iostream>
#include "date.h"
using namespace std;

int main2(int argc, char *argv[]){
	Date date1(2019,10,31); 
	Date date2(2019,11,1);
	cout<<date2-date1<<endl;
	cout<<"Hello C-Free!"<<endl;
	return 0;
}
