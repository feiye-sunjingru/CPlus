// LinkedList.h 
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList{
private:
	Node<T> *front, *rear; // 表头和表尾指针
	Node<T> *prevPtr, *currPtr; // 记录表当前遍历位置的指针，由插入和删除操作更新
	int size; // 表中元素的个数
	int position; // 当前元素在表中的位置序号。由函数reset使用
	// 生成新结点，数据域为item，指针域为ptrNext
	Node<T>*newNode(const T&item, Node<T>*ptrNext=NULL); 
	void freeNode(Node<T>*p); // 释放结点
	// 将链表L复制到当前表（假设当前表为空），被复制构造函数，operator=调用
	void copy(const LinkedList<T>&L); 
	 
public:
	LinkedList(); // 构造函数
	LinkedList(const LinkedList<T> &L); // 复制构造函数
	~LinkedList(); // 析构函数
	LinkedList<T>& operator = (const LinkedList<T> &L); //重载赋值运算符
	
	int getSize() const; // 返回链表中元素个数
	bool isEmpty() const; // 链表是否为空
	
	void reset(int pos=0); // 初始化游标的位置
	void next(); // 使游标移动到下一结点
	bool endOfList(); // 游标是否到了链尾
	int currentPosition(); // 返回游标当前的位置
	
	void insertFront(const T& item); // 在表头插入结点 
	void insertRear(const T& item); // 在表尾插入结点
	void insertAt(const T&item); // 在当前结点之前插入结点
	void insertAfter(const T&item); // 在当前结点之后插入结点 

	T deleteFront(); // 删除头结点
	void deleteCurrent(); // 删除当前结点
	
	T& data(); // 返回对当前结点成员数据的引用
	const T& data() const; // 返回对当前结点成员数据的常引用
	
	// 清空链表：释放所有结点的内存空间。被析构函数、operator=调用
	void clear();

};

template <class T>
Node<T>* LinkedList<T>::newNode(const T&item, Node<T>*ptrNext){
	Node<T>*tempptr = new Node<T>(item, ptrNext);
	return tempptr;
}

template <class T>
void LinkedList<T>::freeNode(Node<T>*p){
	delete p;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T>&L){
	L.reset(); 
	
	for(int i=0; i<L.size(); i++){
		insertRear(L.data());  // 增加一个结点，size+1 
		L.next();
	}
} 
template <class T>
LinkedList<T>::LinkedList():size(0){
	front=rear=new Node<T>(0);
	currPtr=prevPtr=front;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L){
	LinkedList();
	copy(L);
	cout<<"调用复制构造函数"<<endl; 
}

template <class T>
LinkedList<T>::~LinkedList(){
	clear();
	delete front;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T> &L){
	clear();
	front->next= NULL;
	copy(L);
	cout<<"调用重载运算符="<<endl;
	return *this;
}

template <class T>
int LinkedList<T>::getSize() const{
	return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const{
	if(front==rear){
		return true;
	}
	return false;
}

template <class T>
void LinkedList<T>::reset(int pos){
	prevPtr = front;
	currPtr = front->nextNode();
	position = pos;
	for(int i=0; i<position; i++){
		next();  // LinkedList::next()
	}
}

template <class T>
void LinkedList<T>::next(){
	prevPtr = currPtr;
	currPtr = currPtr->nextNode();
}

template <class T>
bool LinkedList<T>::endOfList(){
	if(currPtr==NULL) return true;
	return false;
}

template <class T>
int LinkedList<T>::currentPosition(){
	Node<T>*tempptr = front->nextNode();
	position = 0;
	while(tempptr != currPtr){
		tempptr = tempptr->nextNode();
		position++;
	}
	return position;
}
template <class T>
void LinkedList<T>::insertFront(const T& item){ 
	prevPtr = currPtr;
	currPtr = newNode(item, front->nextNode());
	front->next = currPtr; 
	if(rear == front){
		rear = currPtr;
	}
	size++;
}

template <class T>
void LinkedList<T>::insertRear(const T& item){
	prevPtr = currPtr;
	currPtr = newNode(item, rear->nextNode());
	rear->next = currPtr;
	rear = currPtr;
	size++; 
} 

template <class T>
void LinkedList<T>::insertAt(const T&item){
	currPtr = newNode(item, prevPtr->nextNode());  // 新建结点时，curr要移动到新建结点上 
	prevPtr->next = currPtr;
}

template <class T>
void LinkedList<T>::insertAfter(const T&item){
	prevPtr = currPtr;
	Node<T>*tempptr = newNode(item, currPtr->nextNode());  // currPtr->nextNode()即 tempptr->next 
	currPtr->next = tempptr;
	if(currPtr == rear){
		rear = tempptr;
	}
	currPtr = tempptr;
	size++;
} 

template <class T>
T LinkedList<T>::deleteFront(){
	currPtr = front->nextNode();
	delete front;
	front = currPtr;
	size--;
	return front->data;
}

template <class T>
void LinkedList<T>::deleteCurrent(){ // 删除操作：currPtr往前挪 
	Node<T> *tempptr = currPtr;
	prevPtr->deleteAfter();
	delete currPtr;
	currPtr = prevPtr; 
	size--;
}

template <class T>
T& LinkedList<T>::data(){
	return currPtr->data; 
} 

template <class T>
const T& LinkedList<T>::data() const{
	return currPtr->data; 
} 

template <class T>
void LinkedList<T>::clear(){
	Node<T>*tempptr = front->nextNode();
	while(tempptr != NULL){
		Node<T>*tempQ = tempptr;
		tempptr = tempptr->nextNode();
		delete tempQ;
		size--;
	}
	rear = front;
	currPtr = prevPtr = front;
}

#endif 
