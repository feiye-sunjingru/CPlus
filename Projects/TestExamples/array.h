// array.h
#ifndef _ARRAY_H_
#define _ARRAY_H_

template <class T>
class Array {
private:
	T* list; //�κ�����
	int size;
public:
	Array(int sz = 50);
	Array(const Array <T> & a); 
	~Array();
	Array<T>& operator = (const Array < T & rhs); // ���ء�=��
	T& operator [](int i); // ���ء�[]��,Ϊʲô��������
	const T& operator[](int i)const; // ���ء�[]����������ǰ���ǳ����ã������ǳ�ֵ����
	operator T* (); // ���ص�T*���͵�ת��
	operator const T* () const;
	int getSize() const; // ȡ����Ĵ�С
	void resize(int sz); // �޸�����Ĵ�С 
};

template <class T> Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];  // ��������飬����ÿ��Ԫ����T����
}

template <class T> Array<T>::Array(const Array<T> &a) {
	size = a.size;
	list = new T[size]; // ��㸴��
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
