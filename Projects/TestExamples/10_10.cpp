// 10_10.cpp
#include <iostream>
#include <map>
#include <string>
using namespace std; 
// ��5�ſγ̣�ÿ�Ŷ�����Ӧѧ�֣�����ѡ�����ţ����ѧ���ܺ�

int main50(){
	map<string, int>courses;
	// ���γ���Ϣ����coursesӳ����
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));
	int n = 3; // ʣ�µĿ�ѡ����
	int sum = 0; // ѧ���ܺ�
	
	while(n > 0){
		string name;
		cin>>name;
		map<string, int>::iterator iter = courses.find(name); // ���ҿγ�
		if(iter == courses.end()){ // �Ƿ���ҵ� 
			cout<<name<<" is not available"<<endl; 
		} else{
			sum += iter->second; // �ۼ�ѧ��
			courses.erase(iter); // ����ѡ���Ŀγ̴�ӳ����ɾ��
			n--; 
		}
	}
	cout<<"Total count:"<<sum<<endl; // �����ѧ��
	return 0; 
	 
} 