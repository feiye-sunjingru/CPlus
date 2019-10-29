// 6_19.cpp
#include <iostream>
#include <cassert>

#include "point.h"

 
using namespace std;


class ArrayOfPoints{  // ��̬������
	public:
		ArrayOfPoints(int size):size(size){
			points = new Point[size]; 
		} 
		~ArrayOfPoints(){
			cout<<"Deleting..."<<endl;
			delete[] points;
		}
		Point& element(int index){  // ���뷵�����ã����������޸��ڲ� 
			assert(index>=0 && index<size);  // �ֶ����쳣�ж� 
			return points[index];
		} 
	private:
		Point *points; // ָ��̬�����׵�ַ 
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
 