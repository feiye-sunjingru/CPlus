// �ļ�3����������5_10.cpp
# include "Point.h"
# include <iostream> 
using namespace std;

int main(){
	Point a(4,5);  // ��һ������a 
	cout<<"Point A:"<<a.getX()<<","<<a.getY()<<endl;
	Point::showCount();
	
	Point b(a);  // Q1:��a��ʼ��b����1�ε��ÿ������캯�� 
	cout<<b.getX()<<endl;
	cout<<"****************************"<<endl;
	b.showCount(); 
	cout<<"****************************"<<endl;
	return 0;
} 
