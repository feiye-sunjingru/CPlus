// Node.h
#ifndef _NODE_H_
#define _NODE_H_

template<class T>
class LinkedList;
// ��ģ��Ķ���
template<class T>
class Node{ // ��������� ��ģ�� 
private:
	Node<T> *next; // ָ���̽���ָ�� 
public:
	T data; // ������ 
	Node(const T&item, Node<T>*next=0);  // ���캯�� 
	void insertAfter(Node<T>*p); // �ڱ��ڵ�֮�����һ��ͬ����p 
	Node<T>*deleteAfter(); // ɾ�������ĺ�̽�㣬���������ַ 
	Node<T>*nextNode(); // ��ȡ��̽��ĵ�ַ 
	const Node<T>*nextNode()const; // ��ȡ��̽��ĵ�ַ 
	friend LinkedList<T>;
};

template<class T>
Node<T>::Node(const T&item, Node<T>*next):data(item), next(next){}

template<class T>
void Node<T>::insertAfter(Node<T>*p){
	p->next = next;  // p���ָ����ָ��ǰ���ĺ�̽�� 
	next = p; // this.next ��ǰ����ָ����ָ��p 
}

template<class T>
Node<T>* Node<T>::deleteAfter(){
	Node<T>*tempptr = next; // �Ƿ�Ҫ��Ҫɾ����������
	if(next == 0){  // ��ָ���Ƿ�Ϊ�� 
		return 0;
	}
	next = tempptr->next; // �м���Ϳ�����
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