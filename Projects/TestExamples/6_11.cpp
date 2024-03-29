// 6_11.cpp
# include <iostream>
using namespace std; 

const int N = 6;
// 指向常量的指针做形参（只用首地址），来节省空间，提高效率 
void print(const int*p, int n); 

int main15(){
	int array[N];
	for(int i=0; i<N; i++){
		cin>>array[i];
	}
	print(array, N);
	return 0;
}

void print(const int *p, int n){
	cout<<"{"<<*p;
	for(int i=1; i<n; i++){
		cout<<","<<*(p+i);
	}
	cout<<"}"<<endl;
}
