// lab9_3.cpp
#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;

void read(int*p, int n){
	for(int i=0; i<n; i++){
		cin>>p[i];
	}
}

int main37(){
	Array<int>a(10);
	read(a, 10);
	return 0;
}

