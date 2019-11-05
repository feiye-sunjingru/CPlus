// 10_4.cpp
#include <list>
#include <deque>
#include <iterator>
#include <iostream>
using namespace std; 

// ���ָ����˳��������Ԫ��
template <class T>
void printContainer(const char* msg, const T&s){
	cout<<msg<<":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, ""));
	cout<<endl;
} 

int main44(){
	// �ӱ�׼�������10�������������Ƿֱ��s��ͷ������
	deque<int> s; // ˫�˶��� 
	for(int i=0; i<10; i++){
		int x;
		cin>>x;
		s.push_front(x); // ��ͷ����� 
	} 
	printContainer("deque at first", s);
	// ��s�����е����ݵ��������б�����
	list<int>l(s.rbegin(), s.rend()); // reverse 
	printContainer("list at first", l);
	
	// ���б�����l��ÿ��������Ԫ��˳��ߵ�
	list<int>::iterator iter = l.begin();
	while(iter != l.end()){
		int v = *iter;
		iter = l.erase(iter);  // ���б���ɾ���� 
		l.insert(++iter, v);
	} 
	printContainer("list at last", l);
	// ���б�����l�����ݸ�s��ֵ����s���
	s.assign(l.begin(), l.end()); // ��l��ֵ��s 
	printContainer("deque at last", s);
	return 0; 
}

