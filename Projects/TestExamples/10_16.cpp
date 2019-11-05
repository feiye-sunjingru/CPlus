// 10_16.cpp 
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
using namespace std; 

// 利用STL的二元谓词函数对象实现将数组按照从大到小的顺序排序的功能

int main56(){
	int intArr[] = {30,90,10,40,70,50,20,80};
	const int N = sizeof(intArr)/sizeof(int);
	vector<int>a(intArr, intArr+N);
	cout<<"before sorting:"<<endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout,"\t"));
	cout<<endl;
	
	sort(a.begin(), a.end(), greater<int>()); // greater STL函数对象 从大到小 
	
	cout<<"after sorting:"<<endl;
	copy(a.begin(),a.end(),ostream_iterator<int>(cout,"\t"));
	cout<<endl;
	return 0; 
} 