// stack.h
#ifndef _STACK_H_
#define _STACK_H_
#include <cassert>

template <class T, int SIZE=50> // ��ģ��������г�����ʼ�� 
class Stack{
private:
	T list[SIZE];
	int top; // ջ�� 
public:
	Stack();
	void push(const T&item); // ѹջ 
	T pop(); // ��ջ 
	void clear(); // ���ջ 
	const T&peek() const; // ��ջ�� 
	bool isEmpty() const;
	bool isFull() const; 
};

// ģ���ʵ��
template<class T, int SIZE>
Stack<T,SIZE>::Stack():top(-1){
} 

template<class T, int SIZE>
void Stack<T,SIZE>::push(const T&item){
	assert(!isFull());
	list[++top] = item;
}

template<class T, int SIZE>
T Stack<T,SIZE>::pop(){
	assert(!isEmpty());
	return list[top--];
}

template<class T, int SIZE>
void Stack<T,SIZE>::clear(){
	top = -1;
}

template<class T, int SIZE>
const T& Stack<T,SIZE>::peek() const{
	assert(!isEmpty());
	return list[top]; // ����ջ��Ԫ�� 
}

template<class T, int SIZE>
bool Stack<T,SIZE>::isEmpty() const{
	return top==-1; 
} 

template<class T, int SIZE>
bool Stack<T,SIZE>::isFull() const{
	return top==SIZE-1; 
} 

#endif