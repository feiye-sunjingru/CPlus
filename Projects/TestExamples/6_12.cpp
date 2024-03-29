// 6_11.cpp
# include <iostream>
using namespace std; 

int getMax(int a, int b){
	return a>=b?a:b;
} 

int getMin(int a, int b){
	return a<=b?a:b;
} 

int getSum(int a, int b){
	return a+b;
} 

int compute(int a, int b, int(*funcName)(int,int)){
	return funcName(a, b);
}

int main16(){
	cout<<compute(3, 4, &getSum)<<endl; // 直接用getSum也是传地址，只是这样更清晰 
	cout<<compute(3, 4, &getMax)<<endl;
	cout<<compute(3, 4, &getMin)<<endl;
}