// 6_22.cpp
#include "point.h"
#include <iostream>

using namespace std;

int main21(){
	int count;
	cout<<"Please enter the count of points:";
	cin>>count;
	ArrayOfPoints pointsArray1(count); // 创建对象数组
	pointsArray1.element(0).move(5,10);
	pointsArray1.element(1).move(15,20);
	
	ArrayOfPoints pointsArray2(pointsArray1); // 创建副本
	
	cout<<"Copy of pointsArray1:"<<endl;
	cout<<"Point_0 of array2:"<<pointsArray2.element(0).getX()<<","
		<<pointsArray2.element(0).getY()<<endl;
	cout<<"Point_1 of array2:"<<pointsArray2.element(1).getX()<<","
		<<pointsArray2.element(1).getY()<<endl; 

	pointsArray1.element(0).move(25,30);
	pointsArray1.element(1).move(35,40);	
	cout<<"After the moving of pointsArray1:"<<endl;
		cout<<"Point_0 of array2:"<<pointsArray2.element(0).getX()<<","
		<<pointsArray2.element(0).getY()<<endl;
	cout<<"Point_1 of array2:"<<pointsArray2.element(1).getX()<<","
		<<pointsArray2.element(1).getY()<<endl; 
		
	return 0; 
} 
