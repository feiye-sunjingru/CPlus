// 4_2.cpp 
# include <iostream>
# include <cmath> 
#include "point.h"
using namespace std;

int Point::count = 0; // 静态数据成员必须在类外初始化
float dist(const Point& a, const Point& b){  // 外部访问私有成员（出于效率，没有用get）需要friend权限
	double x = a.x - b.x;
	double y = a.y - b.y;
	return static_cast<float>(sqrt(x*x+y*y)); 
}
void fun1(Point& p){
	cout<< p.getX()<<endl;
} 

/*注意：g++进行了编译优化直接使用了fun()的返回对象，拷贝构造函数没有被调用
  若要使用拷贝构造函数，需要：g++ -fno-elide-constructors testReturn.cpp*/
Point fun2(){
	Point a(1,2);
	return a;  // 返回到值，要完成复制构造 
} 

int main5(){
	Point a(4,5);  // 第一个对象a 
	Point *p1 = &a;  
	cout<<"****************************"<<endl;	
	Point b(a);  // Q1:用a初始化b，第1次调用拷贝构造函数 
	cout<<b.getX()<<endl;
	fun1(b); // Q2:对象b作为func1的实参，第2次调用拷贝复制函数 
	b = fun2();  // Q3:函数的返回值是类对象，函数返回时，调用构造函数 
	cout<<b.getX()<<endl;
	cout<<"****************************"<<endl;
	b.showCount(); 
	cout<<"****************************"<<endl;
	cout<<dist(a,b)<<endl;
	return 0;
}
