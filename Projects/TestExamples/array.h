// array.h
#ifndef _ARRAY_H_
#define _ARRAY_H_

template <class T>
class Array {
private:
	T* list; //任何类型
	int size;
public:
	Array(int sz = 50);
	Array(const Array <T> & a); 
	~Array();
	Array<T>& operator = (const Array < T & rhs); // 重载“=”
	T& operator [](int i); // 重载“[]”,为什么返回引用
	const T& operator[](int i)const; // 重载“[]”常函数，前面是常引用，后面是常值输入
	operator T* (); // 重载到T*类型的转换
	operator const T* () const;
	int getSize() const; // 取数组的大小
	void resize(int sz); // 修改数组的大小 
};

template <class T> Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];  // 定义个数组，数组每个元素是T类型
}

template <class T> Array<T>::Array(const Array<T> &a) {
	size = a.size;
	list = new T[size]; // 深层复制
	for (int i = 0; i < size i++) {
		list[i] = a.list[i]; 
	}
}

template <class T> Array<T>::~Array() {
	delete[] list;
}

template <class T>  Array<T>&  Array<T> :: operator = (const Array <T> & rhs) {
	if (rhs != this) {
		if (rhs.size != size) {
			delte[]list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}
#endif
