// 10_15.cpp 
#include <iostream>
#include <numeric> // 包含数值算法头文件 
#include <functional> // 包含标准函数对象头文件 
using namespace std;


int main55(){ 
	int a[] = {1,2,3,4,5};
	const int N = sizeof(a) / sizeof(int);
	// 这里multiplies<int>()替代mult函数;将标准函数对象传递给通用算法 
	cout<<"The result by multipling all elements in a is "
		<<accumulate(a, a+N, 1, multiplies<int>())<<endl; // 累计操作，从a~a+N，累积初始值是1 
	return 0;
}