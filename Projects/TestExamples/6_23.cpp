// 6_23.cpp
#include "point.h"
#include <iostream>

using namespace std;

class IntNum{
	public:
		IntNum(int x=0):xptr(new int(x)){ // 构造函数 
			cout<<"Calling constructor..."<<endl; 
		}
		IntNum(const IntNum& n):xptr(new int(*n.xptr)){  // 复制构造函数 
			cout<<"Calling copy constructor..."<<endl; 
		}
		
		IntNum(IntNum &&n):xptr(n.xptr){ // 移动构造函数，浅层复制 
			n.xptr = nullptr;  // 空指针 delete空指针不会发生任何析构 
			cout<<"Calling move constructor..."<<endl; 
		} 
		
		~IntNum(){  // 析构函数
			delete xptr;
			cout<<"Destructing"<<endl; 
		}
		int getInt(){
			return *xptr;  // 返回值 
		}
	private:
		int *xptr;
};

// 关于函数返回值优化拷贝构造函数
IntNum getNum(){
	IntNum a; // 默认构造函数
	return a; // 复制构造函数 
} 

int main22(){
	cout<<getNum().getInt()<<endl;
	return 0;
}