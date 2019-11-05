// 10_13.cpp 
#include <iostream>
#include <numeric> // 包含数值算法头文件 
using namespace std;

// 定义一个普通函数
int mult(int x, int y){
	return x*y;
} 

int main53(){ 
	int a[] = {1,2,3,4,5};
	const int N = sizeof(a) / sizeof(int);
	cout<<"The result by multipling all elements in a is "
		<<accumulate(a, a+N, 1, mult)<<endl; // 累计操作，从a~a+N，累积初始值是1 
	return 0;
}