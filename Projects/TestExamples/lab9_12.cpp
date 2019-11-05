// lab9_12.cpp 
#include "queue2.h"
#include <iostream>
using namespace std;

int main39(){
	int item;
	Queue<int>q;
	cout<<"输入5个要插入的元素："<<endl;
	for(int i=0; i<5; i++){
		cin>> item;
		q.push(item);
	}
	
	for(int i=0; i<5; i++){
		cout<<"取出元素："<<q.pop()<<endl;
	}
	return 0;
}