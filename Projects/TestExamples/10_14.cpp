// 10_14.cpp 
#include <iostream>
#include <numeric> // ������ֵ�㷨ͷ�ļ� 
using namespace std;

class MultClass{  // ���� MultClass
public:
	// ���������operator()
	int operator()(int x, int y)const{
		return x*y;
	} 
};

int main54(){ 
	int a[] = {1,2,3,4,5};
	const int N = sizeof(a) / sizeof(int);
	// ����MultClass()���mult���� 
	cout<<"The result by multipling all elements in a is "
		<<accumulate(a, a+N, 1, MultClass())<<endl; // �ۼƲ�������a~a+N���ۻ���ʼֵ��1 
	return 0;
}