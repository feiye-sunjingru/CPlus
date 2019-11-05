// 10_17.cpp
#include <iostream>
#include <algorithm> 
#include <vector>
#include <iterator>
using namespace std;

int main57(){
	int intArr[] = {30, 90, 10, 40, 70, 50, 20, 80};
	const int N = sizeof(intArr)/sizeof(int);
	vector<int>a(intArr, intArr+N); // 把intArr的元素放到a里 
	
	// bind2nd绑定适配器，变成1元谓词。find_if 
	vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 40));
	if(p == a.end()){
		cout<<"no element greater than 40"<<endl;
	}else{
		cout<<"first element greater than 40 is:"<<*p<<endl;
	}
	return 0;
} 