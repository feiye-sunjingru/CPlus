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
		int getMaxDay() const; // 得到当前月的天数 
		bool isLeepYear() const{ // 用来判断是否是闰年 
			if((year%4==0 && year%100!=0) || year%400==0){
				return true;
			}
			return false;
		}
		void show() const; // 用来将当前日期输出
		
		int distance(Date date){ // 用来判断当前日期与指定日期相差天数
			cout<<date.year<<"/"<<date.month<<"/"<<date.day<<"\t";
			return date.totalDays-totalDays;
		}   
	private:
		int year;
		int month;
		int day;
		int totalDays;  // 这一天的相对日期，该日期是从公元元年1月1日开始的第几天 
};
#endif