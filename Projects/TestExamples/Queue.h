// Queue.h 
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <cassert>

template <class T, int SIZE=50>
class Queue{
private:
	int front, rear, count; // 队头指针、队尾指针、元素个数 
	T list[SIZE]; // 队列元素数组 
public:
	Queue(); // 构造函数，初始化队头、队尾、元素个数
	void insert(const T&item); // 新元素入队
	T remove(); // 元素出队 
	void clear(); // 清空队列
	
	const T& getFront() const; // 访问队头元素
	// 测试队列状态
	int getLength() const; // 求队列长度
	bool isEmpty() const; // 判断队列是否为空
	bool isFull() const; // 判断队列是否满 
};

 
template <class T, int SIZE>
Queue<T, SIZE>::Queue():front(0),rear(0),count(0){
}

template <class T, int SIZE>
void Queue<T, SIZE>::insert(const T&item){
	assert(count!=SIZE);
	list[rear] = item; // 向队尾插入元素 
	count++;
	rear = (rear+1)%SIZE; // 队尾指针+1，用取余运算实现循环队列 
}

template <class T, int SIZE>
T Queue<T, SIZE>::remove(){
	assert(count!=0);
	int temp = front;
	count--;
	front = (front+1)%SIZE;
	return list[temp];
} 

template <class T, int SIZE>
void Queue<T, SIZE>::clear(){
	front = 0;
	rear = 0;
	count = 0;
}

template <class T, int SIZE>
const T& Queue<T, SIZE>::getFront() const{
	return list[front];
}

template <class T, int SIZE>
int Queue<T, SIZE>:: getLength() const{
	return count;
}

template <class T, int SIZE>
bool Queue<T, SIZE>:: isEmpty() const{
	return count==0;
}

template <class T, int SIZE>
bool Queue<T, SIZE>:: isFull() const{
	return count==SIZE;
}