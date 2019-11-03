// Calculator.h
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
#include "Stack.h"

class Calculator{ // ��������
private:
	Stack<double>s; // ������ջ
	void enter(double num); // ��������numѹ��ջ
	// ��������������������ջ������opnd1��opnd2��
	bool getTwoOperands(double&opnd1, double&opnd2);
	void compute(char op); // ִ���ɲ�����opָ��������	
public: 
	void run();  // ���м��������� 
	void clear(); // ��ղ�����ջ 
}; 


#endif