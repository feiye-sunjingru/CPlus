// lab9_13.cpp
#include <iostream> 
#include "array.h"
using namespace std;

int main40(){
	int a[5] = {3,6,1,8,2};
	double d[4] = {4.1, 3.2, 5.6, 1.9};
	char c[3] = {'g', 'c', 'A'};
	
	Array<int> iArray(a, 5);
	iArray.insertSort();
	cout<<"a ²åÈëÅÅÐòºó£º"<<endl;
	for(int i=0; i<iArray.getSize(); i++) cout<<iArray[i]<<endl;
	
	Array<double> dArray(d, 4);
	dArray.selectSort();
	cout<<"d Ñ¡ÔñÅÅÐòºó£º"<<endl;
	for(int i=0; i<dArray.getSize(); i++) cout<<dArray[i]<<endl;
	
	Array<char> cArray(c, 3);
	cArray.bubbleSort();
	cout<<"c Ã°ÅÝÅÅÐòºó£º"<<endl;
	for(int i=0; i<cArray.getSize(); i++) cout<<cArray[i]<<endl;
	return 0;
}