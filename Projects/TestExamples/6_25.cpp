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

void transpose(int **arr){ // ��̬����ʵ�֣���̬������ֱ�Ӷ�Ӧ{} 
	for(int i=0; i<3; i++){
		for(int j=i; j<3; j++){
			swap(*(*(arr+i)+j), *(*(arr+j)+i));			
		}
	}
}

int main(){
	int **a;
	a = new int* [3];
	for(int i=0; i<3; i++){
		a[i] = new int[3];
	}
	cout<<"����9��������Ϊ����Ԫ��ֵ"<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>*(*(a+i)+j);
		}
	}
	//int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; *(*(a+i)+j)
	cout<<"��ʼ����:"<<endl;
	print(a);
	transpose(a);
	cout<<"ת�ú�:"<<endl;
	print(a);
	delete[] a;
	return 0;	
}