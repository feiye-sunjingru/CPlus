// 10_15.cpp 
#include <iostream>
#include <numeric> // ������ֵ�㷨ͷ�ļ� 
#include <functional> // ������׼��������ͷ�ļ� 
using namespace std;


int main55(){ 
	int a[] = {1,2,3,4,5};
	const int N = sizeof(a) / sizeof(int);
	// ����multiplies<int>()���mult����;����׼�������󴫵ݸ�ͨ���㷨 
	cout<<"The result by multipling all elements in a is "
		<<accumulate(a, a+N, 1, multiplies<int>())<<endl; // �ۼƲ�������a~a+N���ۻ���ʼֵ��1 
	return 0;
}