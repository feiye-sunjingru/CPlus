// 3_3.cpp 
# include <iostream>
# include <cmath>
using namespace std;

const float TINY_VALUE=1e-10;

double power2(double x, int n){  // 常用功能 
	double value = 1.0;
	while(n--){
		value *= x;
	}
	return value;
}

// 判断n是否是回文数
bool symm(unsigned n){
	unsigned i = n;
	unsigned m = 0;
	while(i >= 0){ // 判断反转后是否相等 
		m = m * 10 + i % 10; 
		i = i / 10; // 最高位 
	} 
	return m==n; 
} 

/*double tsinx(double x){
	double g = 0.0;
	double t = x;
	int n = 1;
	do{
		g += t;
		n++;
		t = -t * x * x /(2*n - 1)/(2*n - 2);
	}while(fabs(t) >= TINY_VALUE);
	
	return g;
}*/

double arctan(double x){
	double sqr = x * x;
	double e = x;
	double r = 0;
	int i = 1;
	while(e/i > 1e-15){
		double f = e/i;
		r = (i%4 == 1)? r+f: r-f;
		e = e * sqr;
		i += 2; 
	}
	return r;
}

// 投骰子、计算和数、输出和数 
int rollDice(){
	int die1 = 1 + rand()%6; // 1~6 
	int die2 = 1 + rand()%6;
	int sum = die1 + die2;
	cout<<"player rolled "<<die1<<"+"<<
		die2<<"="<<sum<<endl;
	return sum; 
} 

// 以递归的方式计算组合的个数 
int comm(int n, int k){
	if(k > n){
		return 0;
	}else if(n==k || k==0){
		return 1;
	}else{
		return comm(n-1,k)+comm(n-1,k-1);
	}
} 

// 交换两个值 
void swap(int& a, int& b){ // 使用引用别名 
	int t = a;
	a = b;
	b = t;	
} 

const double PI = 3.14159265358979;
// 内联函数，直接拿语句替代函数，避免参数来回调用；
// 虽然声明了inline，编译器还是会再次进行判断，是否真正内联  
inline double calArea(double radius){  
	return PI*radius*radius;
} 

int main2(){
	double powValue;
	powValue = power2(5,2);
	cout<<"5 to the power 2 is:"<<powValue<<endl;
	return 0;
}
