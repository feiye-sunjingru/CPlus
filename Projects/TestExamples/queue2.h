// queue2.h
#ifndef _QUEUE2_H_
#define _QUEUE2_H_
#include "LinkedList.h" 

template <class T>
class Queue: public LinkedList <T>
{
public:
	Queue(){
		LinkedList<T>();
	}
	void push(const T&item){
		LinkedList<T>::insertRear(item);
	}
	T pop(){
		return LinkedList<T>::deleteFront();
	}
};


#endif 