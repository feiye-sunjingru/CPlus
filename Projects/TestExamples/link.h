// link.h
#ifndef _LINK_H_
#define _LINK_H_

template <class T>
class Node{
private:
	T data;
public:
	Node* next;
	Node();
	Node(const T&data, Node<T>*nt=0);
 
}