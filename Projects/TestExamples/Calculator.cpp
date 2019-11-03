// Calculator.cpp
#include "Calculator.h"
#include <string>
#include <sstream>
#include <cmath> 
#include <iostream>
using namespace std;

// ���ߺ��������ڽ��ַ���ת����ʵ�� 
inline double stringToDouble(const string& str){
	istringstream stream(str); // �ַ�������������Ϊ������Դ 
	double result;
	stream>> result;
	return result; 
}

void Calculator::enter(double num){  // ��������ѹ��ջ 
	s.push(num);
}

bool Calculator::getTwoOperands(double&opnd1, double&opnd2){
	if(s.isEmpty()){ // ���ջ�Ƿ�� 
		cerr<<"Missing operand!"<<endl;
		return false;
	}
	opnd1 = s.pop(); // ���Ҳ���������ջ
	if(s.isEmpty()){
		cerr<<"Missing operand!"<<endl;
		return false;
	} 
	opnd2 = s.pop(); // �������������ջ 
	return true;
} 

void Calculator::compute(char op){  // ִ������ 
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);
	if(result){  // ����ɹ���ִ�����㲢��������ѹ��ջ 
		switch(op){
		case '+': s.push(operand2+operand1); break;
		case '-': s.push(operand2-operand1); break;
		case '*': s.push(operand2*operand1); break;
		case '/': 
			if(operand1==0){  // �������Ƿ�Ϊ0 
				cerr<<"Divided by 0!"<<endl;
				s.clear(); // ������Ϊ0ʱ���ջ 
			}else{
				s.push(operand2*operand1); 
			} 
			break;
		case '^': s.push(pow(operand2, operand1)); break;
		default: cerr<<"Unrecognized operator!"<<endl; break;
		} 
		
		cout<<"="<<s.peek()<<""; //������������� 
	}else{
		s.clear(); // ���������������ջ 
	} 
}

void Calculator::run(){ // ���벢�����׺���ʽ 
	string str;
	while(cin>>str, str!="q"){  // ���ű��ʽ�������� 
		switch(str[0]){
			case 'c': s.clear(); break;
			case '-':  // ����-��Ҫ�ж��Ǽ��Ż��Ǹ���
				if(str.size()>1){
					enter(stringToDouble(str)); // ���� 
				} else{
					compute(str[0]); // Ҫ������ 
				}
				break;
			case '+':
			case '*':
			case '/':
			case '^': compute(str[0]);
			default: // ��������ǲ�������ת��Ϊ���ͺ�ѹ��ջ
				enter(stringToDouble(str)); break; 	
		} 
	} 
} 

void Calculator::clear(){ // ��ղ���ջ 
	s.clear(); 
}