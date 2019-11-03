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
	Array(const Array <T> & a); 
	~Array();
	Array<T>& operator = (const Array <T> & rhs); // 重载“=”
	T& operator [](int i); // 重载“[]”,为什么返回引用
	const T& operator[](int i)const; // 重载“[]”常函数，前面是常引用，后面是常值输入
	operator T* (); // 重载到T*类型的转换
	operator const T* () const;
	int getSize(); // 取数组的大小
	void resize(int sz); // 修改数组的大小 
};

// 构造函数 
template <class T> 
Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];  // 定义个数组，数组每个元素是T类型
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
template <class T> 
Array<T>::~Array() {
	delete[] list;
}

// 重载=运算符 
template <class T>  
Array<T>&  Array<T> :: operator = (const Array <T> & rhs) {
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
T& Array<T>::operator[](int n){
	assert(n>=0 && n<size); // 检查下标是否越界
	return list[n]; //返回下标为n的数组元素 
} 

template <class T>
const T& Array<T>::operator[](int n)const{  // 输入是常值 
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
#endif
