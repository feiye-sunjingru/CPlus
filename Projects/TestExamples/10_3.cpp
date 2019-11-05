// 10_3.cpp
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

// �����������������n��T���͵��������򣬽����ͨ�������������result���
template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result){
	// ͨ��������������������ݴ�����������s��
	vector<T>s;
	for(; first!=last; ++first){
		s.push_back(*first);  // ����s push_back 
	} 
	// ��s��������sort�����Ĳ���������������ʵ�����
	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result); // ��s����ͨ�����������������͵���� 
} 

int main43(){
	// ��s�����������������
	double a[5] = {1.2,2.4,0.8,3.3,3.2};
	mySort<double>(a, a+5, ostream_iterator<double>(cout, " "));
	cout<<endl;
	// �ӱ�׼����������ɸ��������������Ľ�����
	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(),
		ostream_iterator<int>(cout, " "));  // ������\n���� 
	cout<<endl;
	return 0; 
} 