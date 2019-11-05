// lab10_1.cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

int main41(){
	const int N = 5;
	vector<int>s(N); // 容器 
	for(int i=0; i<N; i++){
		cin>>s[i];
	}
	// 算法 迭代器 函数对象（输出相反数） 
	transform(s.begin(), s.end(), ostream_iterator<int>(cout,""), negate<int>());
	cout<<endl;
	return 0;
}