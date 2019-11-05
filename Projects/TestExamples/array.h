// array.h
#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <cassert>

template <class T>
class Array {
private:
	T* list; //任何类型
	int size;
public:
	Array(int sz = 50);
	Array(T* array, int n);
	Array(const Array <T> & a); 
	~Array();
	Array<T>& operator = (const Array <T> & rhs); // 重载“=”
	T& operator [](int i); // 重载“[]”,为什么返回引用
	const T& operator[](int i)const; // 重载“[]”常函数，前面是常引用，后面是常值输入
	operator T* (); // 重载到T*类型的转换
	operator const T* () const;
	int getSize(); // 取数组的大小
	void resize(int sz); // 修改数组的大小 
	
	// 增加排序算法
	T* insertSort();
	T* selectSort();
	T* bubbleSort(); 
};

// 构造函数 
template <class T> 
Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];  // 定义个数组，数组每个元素是T类型
}

template <class T> 
Array<T>::Array(T* array, int n){
	assert(n >= 0);
	size = n;
	list = new T[size];
	for(int i=0; i<n; i++){
		list[i] = array[i];
	} 
}

// 拷贝构造函数 
template <class T> 
Array<T>::Array(const Array<T> &a) {
	size = a.size;
	list = new T[size]; // 深层复制
	for (int i = 0; i < size; i++) {
		list[i] = a.list[i]; 
	}
}

// 析构函数 
template <class T> Array<T>::~Array() {
	delete[] list;
}

// 重载=运算符 
template <class T>  Array<T>&  Array<T> :: operator = (const Array <T> & rhs) {
	if (rhs != this) {  // 是不是同一个地址 
		if (rhs.size != size) { // 元素个数大小是否相同 
			delete[]list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}

// 重载下标运算符，增加了判断越界的功能 
template <class T>
T&Array<T>::operator[](int n){
	assert(n>=0 && n<size); // 检查下标是否越界
	return list[n]; //返回下标为n的数组元素 
} 

template <class T>
const T&Array<T>::operator[](int n)const{  // 输入是常值 
	assert(n>=0 && n<size); // 检查下标是否越界
	return list[n]; //返回下标为n的数组元素 
} 

// 重载指针转换运算符，将Array类的对象名转换为T类型的指针
template <class T>
Array<T>::operator T*(){
	return list;  // 返回当前对象中私有数组的首地址	
} 

// 取当前数组的大小
template <class T>
int Array<T>::getSize(){
	return size;
} 

// 将数组大小修改为sz
template <class T>
void Array<T>::resize(int sz){
	assert(sz >= 0); // 检查sz是否非负
	if(sz == size) return;
	T* newList = new T[sz];
	int n = (sz<size)?sz:size; // 将sz与size较小的一个赋值给n
	// 将原有数组中前n个元素复制到新数组中
	for(int i=0; i<n; i++){
		newList[i] = list[i];
	} 
	delete[] list; // 删除原数组
	list = newList; // 使得list指向新数组
	size = sz; // 更新size 	 
} 

template <class T>
void mySwap(T&x, T&y){
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
T* Array<T>:: insertSort(){
	for(int i=1; i<size; i++){
        int key = list[i];
        int j = i-1;
        while((j>=0) && (key<list[j])){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
    return list;
}

template <class T>
T* Array<T>::selectSort(){  // 从小到大排序 
	for(int i=0; i<size-1; i++){
		int leaseIndex = i;
		for(int j=i+1; j<size; j++){ // 找出一次遍历中最小的值 
			if(list[j]<list[leaseIndex]){
				leaseIndex = j;
			}
		}
		mySwap(list[i], list[leaseIndex]); 
	}
	return list;
} 

template <class T>
T* Array<T>::bubbleSort(){  // 从小到大排序 
	int i = size-1;
	while(i > 0){
		int lastExchangeIndex = 0;  // 最后一次发生交换的下标，避免后面的有序序列还要比较 
		for(int j=0; j<i; j++){ // 一次遍历中两两比较 
			if(list[j+1] < list[j]){ 
				mySwap(list[j], list[j+1]);
				lastExchangeIndex = j;
			}
		}
		i = lastExchangeIndex;
	}
	return list;
}

#endif
