// lab9_11.cpp
#include "LinkedList.h"
using namespace std;

int main38(){
	LinkedList<int>A, B;
	int i, item;
	
	cout<<"�������������A��5��������";
	for(int i=0; i<5; i++){
		cin>>item;
		A.insertRear(item);
	}
	
	cout<<"�������������B��5��������";
	for(int i=0; i<5; i++){
		cin>>item;
		B.insertRear(item);
	}
	
	cout<<endl<<"��������A�е�Ԫ��Ϊ��";
	A.reset();
	while(!A.endOfList()){
		cout<<A.data()<<" ";
		A.next();
	} 
	cout<<endl<<"��������B�е�Ԫ��Ϊ��";
	B.reset();
	while(!B.endOfList()){
		A.insertRear(B.data()); // �ڱ��������ʱ��һ�߲���Aһ����� 
		cout<<B.data()<<" ";
		B.next();
	} 
	
	cout<<endl<<"��������B�е�Ԫ�غ�����A�е�Ԫ��Ϊ��";
    A.reset();
	while(!A.endOfList()){
		cout<<A.data()<<" ";
		A.next();
	} 
	
}
