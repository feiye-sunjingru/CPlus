// Node.h
#ifndef _NODE_H_
#define _NODE_H_

template<class T>
class LinkedList;
// 类模板的定义
template<class T>
class Node{ // 单链表结点的 类模板 
private:
	Node<T> *next; // 指向后继结点的指针 
public:
	T data; // 数据域 
	Node(const T&item=0, Node<T>*next=0);  // 构造函数 
	void insertAfter(Node<T>*p); // 在本节点之后插入一个同类结点p 
	Node<T>*deleteAfter(); // 删除本结点的后继结点，并返回其地址 
	Node<T>*nextNode(); // 获取后继结点的地址 
	const Node<T>*nextNode()const; // 获取后继结点的地址 
	friend LinkedList<T>;
};

template<class T>
Node<T>::Node(const T&item, Node<T>*next):data(item), next(next){}

template<class T>
void Node<T>::insertAfter(Node<T>*p){
	p->next = next;  // p结点指针域指向当前结点的后继结点 
	next = p; // this.next 当前结点的指针域指向p 
}

template<class T>
Node<T>* Node<T>::deleteAfter(){
	Node<T>*tempptr = next; // 是否要留要删除的这个结点
	if(next == 0){  // 该指针是否为空 
		return 0;
	}
	next = tempptr->next; // 中间结点就空着了
	return tempptr; 
}

template<class T>
Node<T>* Node<T>::nextNode(){
	return next;
} 

template<class T>
const Node<T>* Node<T>::nextNode()const{
	return next;
} 

#endif