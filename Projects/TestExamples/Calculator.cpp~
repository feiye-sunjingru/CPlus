// Calculator.cpp
#include "Calculator.h"
#include <string>
#include <sstream>
#include <cmath> 
#include <iostream>
using namespace std;

// 工具函数，用于将字符串转换成实数 
inline double stringToDouble(const string& str){
	istringstream stream(str); // 字符串输入流，作为数据来源 
	double result;
	stream>> result;
	return result; 
}

void Calculator::enter(double num){  // 将操作数压入栈 
	s.push(num);
}

bool Calculator::getTwoOperands(double&opnd1, double&opnd2){
	if(s.isEmpty()){ // 检查栈是否空 
		cerr<<"Missing operand!"<<endl;
		return false;
	}
	opnd1 = s.pop(); // 将右操作数弹出栈
	if(s.isEmpty()){
		cerr<<"Missing operand!"<<endl;
		return false;
	} 
	opnd2 = s.pop(); // 将左操作数弹出栈 
	return true;
} 

void Calculator::compute(char op){  // 执行运算 
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);
	if(result){  // 如果成功，执行运算并将运算结果压入栈 
		switch(op){
		case '+': s.push(operand2+operand1); break;
		case '-': s.push(operand2-operand1); break;
		case '*': s.push(operand2*operand1); break;
		case '/': 
			if(operand1==0){  // 检查除数是否为0 
				cerr<<"Divided by 0!"<<endl;
				s.clear(); // 除数均为0时清空栈 
			}else{
				s.push(operand2*operand1); 
			} 
			break;
		case '^': s.push(pow(operand2, operand1)); break;
		default: cerr<<"Unrecognized operator!"<<endl; break;
		} 
		
		cout<<"="<<s.peek()<<""; //输出本次运算结果 
	}else{
		s.clear(); // 操作数不够，清空栈 
	} 
}

void Calculator::run(){ // 读入并处理后缀表达式 
	string str;
	while(cin>>str, str!="q"){  // 逗号表达式，从左到右 
		switch(str[0]){
			case 'c': s.clear(); break;
			case '-':  // 遇到-需要判断是减号还是负号
				if(str.size()>1){
					enter(stringToDouble(str)); // 负号 
				} else{
					compute(str[0]); // 要做计算 
				}
				break;
			case '+':
			case '*':
			case '/':
			case '^': compute(str[0]);
			default: // 若读入的是操作数，转换为整型后压入栈
				enter(stringToDouble(str)); break; 	
		} 
	} 
} 

void Calculator::clear(){ // 清空操作栈 
	s.clear(); 
}