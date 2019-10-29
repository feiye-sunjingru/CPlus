// 文件3，主函数，5_10.cpp
# include "Point.h"
# include <iostream> 
using namespace std;

int main(){
	Point a(4,5);  // 第一个对象a 
	cout<<"Point A:"<<a.getX()<<","<<a.getY()<<endl;
	Point::showCount();
	
	Point b(a);  // Q1:用a初始化b，第1次调用拷贝构造函数 
	cout<<b.getX()<<endl;
	cout<<"****************************"<<endl;
	b.showCount(); 
	cout<<"****************************"<<endl;
	return 0;
} 
