// 6_19.cpp
#include <iostream>
#include <cassert>

#include "point.h"

 
using namespace std;


class ArrayOfPoints{  // 动态数组类
	public:
		ArrayOfPoints(int size):size(size){
			points = new Point[size]; 
		} 
		~ArrayOfPoints(){
			cout<<"Deleting..."<<endl;
			delete[] points;
		}
		Point& element(int index){  // 必须返回引用，才能真正修改内部 
			assert(index>=0 && index<size);  // 手动做异常判断 
			return points[index];
		} 
	private:
		Point *points; // 指向动态数组首地址 
		int size;
};

int main(){
	int count;
	cout<<"Please enter the count of points:";
	cin>>count;
	ArrayOfPoints points(count);
	points.element(0).move(5, 0);
	points.element(1).move(15, 20);
	cout<< points.element(1).getX()<<endl;
	return 0;
}
 