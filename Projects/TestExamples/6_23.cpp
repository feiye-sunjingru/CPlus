// 6_23.cpp
#include "point.h"
#include <iostream>

using namespace std;

class IntNum{
	public:
		IntNum(int x=0):xptr(new int(x)){ // ���캯�� 
			cout<<"Calling constructor..."<<endl; 
		}
		IntNum(const IntNum& n):xptr(new int(*n.xptr)){  // ���ƹ��캯�� 
			cout<<"Calling copy constructor..."<<endl; 
		}
		
		IntNum(IntNum &&n):xptr(n.xptr){ // �ƶ����캯����ǳ�㸴�� 
			n.xptr = nullptr;  // ��ָ�� delete��ָ�벻�ᷢ���κ����� 
			cout<<"Calling move constructor..."<<endl; 
		} 
		
		~IntNum(){  // ��������
			delete xptr;
			cout<<"Destructing"<<endl; 
		}
		int getInt(){
			return *xptr;  // ����ֵ 
		}
	private:
		int *xptr;
};

// ���ں�������ֵ�Ż��������캯��
IntNum getNum(){
	IntNum a; // Ĭ�Ϲ��캯��
	return a; // ���ƹ��캯�� 
} 

int main22(){
	cout<<getNum().getInt()<<endl;
	return 0;
}