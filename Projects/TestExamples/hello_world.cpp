// hello_world.cpp
# include <iostream>
using namespace std;  // 预定义对象命名防止冲突，有std命名空间

void PrintWord(){
	cout<<"Word"<<endl;
}

int main12(int argc, char * argv[]){
	int *nums = (int *)malloc(sizeof(int)*3);
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	cout<<"nums:"<<nums[0]<<endl;  // 输出流、插入符、行结束 
	
	cout<<"HappyDay"<<endl;
	PrintWord();
	cout<<"The size of intis:\t\t"<<sizeof(int)<<endl; // 多少字节 
	return 0;
}
