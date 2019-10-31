// date.h
#ifndef __DATE_H__
#define __DATE_H__
#include <iostream> 
using namespace std;

class Date{
	public:
		Date(int year, int month, int day);
		int getYear() const{
			return year;
		}
	    int getMonth() const{
			return month;
		}
		int getDay() const{
			return day;
		}
		int getMaxDay() const; // �õ���ǰ�µ����� 
		bool isLeepYear() const{ // �����ж��Ƿ������� 
			if((year%4==0 && year%100!=0) || year%400==0){
				return true;
			}
			return false;
		}
		void show() const; // ��������ǰ�������
		
		int distance(Date date){ // �����жϵ�ǰ������ָ�������������
			cout<<date.year<<"/"<<date.month<<"/"<<date.day<<"\t";
			return date.totalDays-totalDays;
		}   
	private:
		int year;
		int month;
		int day;
		int totalDays;  // ��һ���������ڣ��������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ��� 
};
#endif