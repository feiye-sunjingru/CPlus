// Queue.h 
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <cassert>

template <class T, int SIZE=50>
class Queue{
private:
	int front, rear, count; // ��ͷָ�롢��βָ�롢Ԫ�ظ��� 
	T list[SIZE]; // ����Ԫ������ 
public:
	Queue(); // ���캯������ʼ����ͷ����β��Ԫ�ظ���
	void insert(const T&item); // ��Ԫ�����
	T remove(); // Ԫ�س��� 
	void clear(); // ��ն���
	
	const T& getFront() const; // ���ʶ�ͷԪ��
	// ���Զ���״̬
	int getLength() const; // ����г���
	bool isEmpty() const; // �ж϶����Ƿ�Ϊ��
	bool isFull() const; // �ж϶����Ƿ��� 
};

 
template <class T, int SIZE>
Queue<T, SIZE>::Queue():front(0),rear(0),count(0){
}

template <class T, int SIZE>
void Queue<T, SIZE>::insert(const T&item){
	assert(count!=SIZE);
	list[rear] = item; // ���β����Ԫ�� 
	count++;
	rear = (rear+1)%SIZE; // ��βָ��+1����ȡ������ʵ��ѭ������ 
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