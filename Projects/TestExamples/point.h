// point.h 
#include <iostream>
#include <cmath> 
#include <cassert>
using namespace std;
	
class Point{
	public:
		Point(int xx=0, int yy=0){
			x = xx;
			y = yy;
			count++; 
			cout<<"Default Constructor called."<<endl;
		}
		Point(const Point &p){ // 先完成参数传递
			x = p.x;
			y = p.y;
			count++;
			cout<<"Calling the copy constructor"<<endl;		
		} // =delete指示编译器不生成默认复制构造函数 

		~Point(){
			count--;
			cout<<"Destrcutor called."<<endl;
		}
		
		int getX()const{
			return x;
		}
		
		int getY()const{
			return y;
		}
		
		void move(int myx, int myy){
			x = myx;
			y = myy;
		}
		
		void showCount() const{
			cout<<"Object count="<<count<<endl;
		}
		
		friend float dist(const Point& a, const Point& b);
	
	private:
		int x, y;
		static int count; // 静态数据成员声明，用于记录点的个数 
}; 	

class ArrayOfPoints{  // 动态数组类
	public:
		ArrayOfPoints(int size):size(size){
			points = new Point[size]; 
		} 
		ArrayOfPoints(const ArrayOfPoints& v){
			size = v.size;
			points = new Point[size];
			for(int i=0; i< size; i++){
				points[i] = v.points[i];
			}
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