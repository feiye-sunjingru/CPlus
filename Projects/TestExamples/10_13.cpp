// 10_13.cpp 
#include <iostream>
#include <numeric> // ������ֵ�㷨ͷ�ļ� 
using namespace std;

// ����һ����ͨ����
int mult(int x, int y){
	return x*y;
} 

int main53(){ 
	int a[] = {1,2,3,4,5};
	const int N = sizeof(a) / sizeof(int);
	cout<<"The result by multipling all elements in a is "
		<<accumulate(a, a+N, 1, mult)<<endl; // �ۼƲ�������a~a+N���ۻ���ʼֵ��1 
	return 0;
}