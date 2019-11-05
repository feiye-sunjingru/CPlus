// 10_14.cpp 
#include <iostream>
#include <numeric> // 包含数值算法头文件 
using namespace std;

class MultClass{  // 定义 MultClass
public:
	// 重载运算符operator()
	int operator()(int x, int y)const{
		return x*y;
	} 
};

int main54(){ 
	int a[] = {1,2,3,4,5};
	const int N = sizeof(a) / sizeof(int);
	// 这里MultClass()替代mult函数 
	cout<<"The result by multipling all elements in a is "
		<<accumulate(a, a+N, 1, MultClass())<<endl; // 累计操作，从a~a+N，累积初始值是1 
	return 0;
}