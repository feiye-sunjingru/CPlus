// date.h
#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
using namespace std;

class Date{
	public:
		Date(int year, int month, int day);
		int getMaxDay() const;
		int getYear() const{return year;}
		int getMonth() const{return month;}
		int getDay() const{return day;}
		int getTotalDays() const{return totalDays;}
		bool isLeepYear() const{
			if((year%4==0&&year%100!=0)||year%400==0) return true;
			return false;
		}
		void show() const{
			cout<<getYear()<<"/"<<getMonth()<<"/"<<getDay()<<endl;
		}
		
		int distance(const Date& date)const{ // ��������� 
			return date.totalDays-totalDays;
		}
	private:
		int year;
		int month;
		int day;
		int totalDays; // ����ڹ�ԪԪ��1��1���������� 
};

#endif