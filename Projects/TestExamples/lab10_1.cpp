// lab10_1.cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

int main41(){
	const int N = 5;
	vector<int>s(N); // ���� 
	for(int i=0; i<N; i++){
		cin>>s[i];
	}
	// �㷨 ������ ������������෴���� 
	transform(s.begin(), s.end(), ostream_iterator<int>(cout,""), negate<int>());
	cout<<endl;
	return 0;
}