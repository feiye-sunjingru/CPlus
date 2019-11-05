// 10_16.cpp 
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
using namespace std; 

// ����STL�Ķ�Ԫν�ʺ�������ʵ�ֽ����鰴�մӴ�С��˳������Ĺ���

int main56(){
	int intArr[] = {30,90,10,40,70,50,20,80};
	const int N = sizeof(intArr)/sizeof(int);
	vector<int>a(intArr, intArr+N);
	cout<<"before sorting:"<<endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout,"\t"));
	cout<<endl;
	
	sort(a.begin(), a.end(), greater<int>()); // greater STL�������� �Ӵ�С 
	
	cout<<"after sorting:"<<endl;
	copy(a.begin(),a.end(),ostream_iterator<int>(cout,"\t"));
	cout<<endl;
	return 0; 
} 