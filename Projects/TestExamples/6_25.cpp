// 6_25.cpp
#include <string>
#include <iostream>
using namespace std;

void print(int **a){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
}

void transpose(int **arr){ // 动态数组实现，静态数组是直接对应{} 
	for(int i=0; i<3; i++){
		for(int j=i; j<3; j++){
			swap(*(*(arr+i)+j), *(*(arr+j)+i));			
		}
	}
}

int main24(){
	int **a;
	a = new int* [3];
	for(int i=0; i<3; i++){
		a[i] = new int[3];
	}
	cout<<"输入9个整数作为矩阵元素值"<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>*(*(a+i)+j);
		}
	}
	//int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; *(*(a+i)+j)
	cout<<"初始矩阵:"<<endl;
	print(a);
	transpose(a);
	cout<<"转置后:"<<endl;
	print(a);
	delete[] a;
	return 0;	
}
