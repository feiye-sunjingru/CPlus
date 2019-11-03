// stack.h
#ifndef _STACK_H_
#define _STACK_H_
#include <cassert>

template <class T, int SIZE=50> // 类模板里可以有常量初始化 
class Stack{
private:
	T list[SIZE];
	int top; // 栈顶 
public:
	Stack();
	void push(const T&item); // 压栈 
	T pop(); // 出栈 
	void clear(); // 清空栈 
	const T&peek() const; // 读栈顶 
	bool isEmpty() const;
	bool isFull() const; 
};

// 模板的实现
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
	return list[top]; // 返回栈顶元素 
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