// 10_9.cpp
#include <set>
#include <iterator>
#include <iostream>
using namespace std;
 
// ����һ��ʵ�������ظ���ȥ����ȡ������Сֵ����ֵ���ֱ����<=����ֵ�͡����ڵ��ڴ���ֵ��ʵ��

int main49(){
	set<double>s;
	while(true){
		double v;
		cin>>v;
		if(v==0) break; // ����0��ʾ����
		// ���Խ�v����
		pair<set<double>::iterator, bool>r = s.insert(v);
		if(!r.second){ // ����Ѵ��ڣ������ʾ��Ϣ 
			cout<<v<<" is duplicated"<<endl; 
		} 
	}
	// �õ���һ��Ԫ�صĵ�����
	set<double>::iterator iter1 = s.begin();
	// �õ�ĩβ�ĵ�����
	set<double>::iterator iter2 = s.end();
	// �õ���С�����Ԫ�ص���ֵ
	double medium = (*iter1 + *(--iter2))/2;
	// ���С�ڻ������ֵ��Ԫ��
	cout<<"<=medium:";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout<<endl;
	// ������ڻ������ֵ��Ԫ��
	cout<<">=medium:";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout<<endl;
	return 0; 
}