// 4_9.cpp 
# include <iostream>

using namespace std;

enum class Side{Right, Left};
enum class Thing{Wrong, Right}; // 不冲突

int main8(){
	Side s = Side::Right;
	Thing w = Thing::Wrong;
	//cout<<(s==w)<<endl; // 编译错误，无法比较不同的枚举类
	return 0;	
} 
