// array.h
#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <cassert>

template <class T>
class Array {
private:
	T* list; //�κ�����
	int size;
public:
	Array(int sz = 50);
	Array(const Array <T> & a); 
	~Array();
	Array<T>& operator = (const Array <T> & rhs); // ���ء�=��
	T& operator [](int i); // ���ء�[]��,Ϊʲô��������
	const T& operator[](int i)const; // ���ء�[]����������ǰ���ǳ����ã������ǳ�ֵ����
	operator T* (); // ���ص�T*���͵�ת��
	operator const T* () const;
	int getSize(); // ȡ����Ĵ�С
	void resize(int sz); // �޸�����Ĵ�С 
};

// ���캯�� 
template <class T> 
Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];  // ��������飬����ÿ��Ԫ����T����
}

// �������캯�� 
template <class T> 
Array<T>::Array(const Array<T> &a) {
	size = a.size;
	list = new T[size]; // ��㸴��
	for (int i = 0; i < size; i++) {
		list[i] = a.list[i]; 
	}
}

// �������� 
template <class T> 
Array<T>::~Array() {
	delete[] list;
}

// ����=����� 
template <class T>  
Array<T>&  Array<T> :: operator = (const Array <T> & rhs) {
	if (rhs != this) {  // �ǲ���ͬһ����ַ 
		if (rhs.size != size) { // Ԫ�ظ�����С�Ƿ���ͬ 
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

// �����±���������������ж�Խ��Ĺ��� 
template <class T>
T& Array<T>::operator[](int n){
	assert(n>=0 && n<size); // ����±��Ƿ�Խ��
	return list[n]; //�����±�Ϊn������Ԫ�� 
} 

template <class T>
const T& Array<T>::operator[](int n)const{  // �����ǳ�ֵ 
	assert(n>=0 && n<size); // ����±��Ƿ�Խ��
	return list[n]; //�����±�Ϊn������Ԫ�� 
} 

// ����ָ��ת�����������Array��Ķ�����ת��ΪT���͵�ָ��
template <class T>
Array<T>::operator T*(){
	return list;  // ���ص�ǰ������˽��������׵�ַ	
} 

// ȡ��ǰ����Ĵ�С
template <class T>
int Array<T>::getSize(){
	return size;
} 

// �������С�޸�Ϊsz
template <class T>
void Array<T>::resize(int sz){
	assert(sz >= 0); // ���sz�Ƿ�Ǹ�
	if(sz == size) return;
	T* newList = new T[sz];
	int n = (sz<size)?sz:size; // ��sz��size��С��һ����ֵ��n
	// ��ԭ��������ǰn��Ԫ�ظ��Ƶ���������
	for(int i=0; i<n; i++){
		newList[i] = list[i];
	} 
	delete[] list; // ɾ��ԭ����
	list = newList; // ʹ��listָ��������
	size = sz; // ����size 
	 
} 
#endif
