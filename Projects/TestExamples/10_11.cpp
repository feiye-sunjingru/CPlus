// 10_11.cpp
#include <iostream>
#include <map>

using namespace std;
 
// ͳ��һ�仰��ÿ����ĸ���ֵĴ���

int main51(){
	map<char, int>s; // �����洢��ĸ���ִ�����ӳ�� 
	char c; // �洢�����ַ�
	do{
		cin>>c; // ������һ���ַ�
		if(isalpha(c)){ // �ж��Ƿ�����ĸ
			c = tolower(c); // ����ĸת��ΪСд 
			s[c]++; // ������ĸ�ĳ���Ƶ��+1 
		} 
	} while(c!='.'); // ����"."���������
	// ���ÿ����ĸ���ֵĴ���
	for(map<char,int>::iterator iter=s.begin(); iter!=s.end(); ++iter){
		cout<<iter->first<<" "<<iter->second<<" ";
	} 
	cout<<endl;
	return 0;
}
 