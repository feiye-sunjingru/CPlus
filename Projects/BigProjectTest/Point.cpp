// 文件2，类的实现，Point.cpp
# include "Point.h"
# include <iostream> 
# include <cmath>
using namespace std;

int Point::count = 0; // 静态数据成员必须在类外初始化

Point::Point(int x, int y):x(x), y(y){
	count++;
}

Point::Point(const Point &p):x(p.x),y(p.y){ // 先完成参数传递
	count++;	
}

Point::~Point(){
	count--;
}

void Point::showCount(){
	cout<<"Object count="<<count<<endl;
}

float dist(const Point& a, const Point& b){  // 外部访问私有成员（出于效率，没有用get）需要friend权限
	double x = a.x - b.x;
	double y = a.y - b.y;
	return static_cast<float>(sqrt(x*x+y*y)); 
}