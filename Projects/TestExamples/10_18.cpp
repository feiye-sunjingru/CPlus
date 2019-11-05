// 10_18.cpp 
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

bool g(int x, int y){
	return x>y;
}

int main58(){
	int intArr[] = {30,90,10,40,70,50,20,80};
	const int N = sizeof(intArr)/sizeof(int);
	vector<int> a(intArr, intArr+N);
	
	vector<int>::iterator p;
	// 函数指针适配器，ptr_fun处理函数对象 
	p = find_if(a.begin(), a.end(), bind2nd(ptr_fun(g), 40));
	if(p == a.end()){
		cout<<"no element greater than 40"<<endl;
	}else{
		cout<<"first element greater than 40 is:"<<*p<<endl;
	}
	// 针对1元谓词，第一个不大于15的元素 
	p = find_if(a.begin(), a.end(), not1(bind2nd(greater<int>(), 15)));
	if(p == a.end()){
		cout<<"no element is not greater than 15"<<endl;
	}else{
		cout<<"first element that is not greater than 15 is:"<<*p<<endl;
	}
	// 针对2元谓词 
	p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()), 15));
	if(p == a.end()){
		cout<<"no element is not greater than 15"<<endl;
	}else{
		cout<<"first element that is not greater than 15 is:"<<*p<<endl;
	}
	return 0;
}