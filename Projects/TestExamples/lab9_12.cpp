// lab9_12.cpp 
#include "queue2.h"
#include <iostream>
using namespace std;

int main39(){
	int item;
	Queue<int>q;
	cout<<"����5��Ҫ�����Ԫ�أ�"<<endl;
	for(int i=0; i<5; i++){
		cin>> item;
		q.push(item);
	}
	
	for(int i=0; i<5; i++){
		cout<<"ȡ��Ԫ�أ�"<<q.pop()<<endl;
	}
	return 0;
}