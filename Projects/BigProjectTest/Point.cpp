// �ļ�2�����ʵ�֣�Point.cpp
# include "Point.h"
# include <iostream> 
# include <cmath>
using namespace std;

int Point::count = 0; // ��̬���ݳ�Ա�����������ʼ��

Point::Point(int x, int y):x(x), y(y){
	count++;
}

Point::Point(const Point &p):x(p.x),y(p.y){ // ����ɲ�������
	count++;	
}

Point::~Point(){
	count--;
}

void Point::showCount(){
	cout<<"Object count="<<count<<endl;
}

float dist(const Point& a, const Point& b){  // �ⲿ����˽�г�Ա������Ч�ʣ�û����get����ҪfriendȨ��
	double x = a.x - b.x;
	double y = a.y - b.y;
	return static_cast<float>(sqrt(x*x+y*y)); 
}