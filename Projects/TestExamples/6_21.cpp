// 6_21.cpp
#include <vector>
#include <iostream>

using namespace std;

// 基于范围的for循环配合auto实例 
int main20(){
	vector<int>v = {1,2,3};
	for(auto i=v.begin(); i!=v.end(); i++){
		cout<<*i<<endl;
	}
	for(auto e:v){
		cout<<e<<endl;
	}
	
}