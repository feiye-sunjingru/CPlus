// hello_world.cpp
# include <iostream>
using namespace std;  // Ԥ�������������ֹ��ͻ����std�����ռ�

void PrintWord(){
	cout<<"Word"<<endl;
}

int main12(int argc, char * argv[]){
	int *nums = (int *)malloc(sizeof(int)*3);
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	cout<<"nums:"<<nums[0]<<endl;  // ���������������н��� 
	
	cout<<"HappyDay"<<endl;
	PrintWord();
	cout<<"The size of intis:\t\t"<<sizeof(int)<<endl; // �����ֽ� 
	return 0;
}
