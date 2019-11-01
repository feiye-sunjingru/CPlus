// date.cpp
#include <iostream>
#include "date.h"
using namespace std;

namespace{
	const int DAYS_BEFORE_MONTH[]={
		0,31,59,90,120,151,181,212,243,273,304,334,365
	};
} 

Date::Date(int year, int month, int day):year(year), month(month), day(day){
	if(day<=0 ||day>getMaxDay()){
		cout<<"Invalid date:";
		show();
		exit(1); // 非0表示异常退出 
	}
	int years = year - 1;
	totalDays = 365*years+years/4-years/100+years/400+DAYS_BEFORE_MONTH[month-1]+day-1;
	if(month > 2){
		if (isLeepYear()){
			totalDays += 1;
		}
	}
}

int Date::getMaxDay(){
	if(isLeepYear() && month==2){
		return 29;
	}
	return DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
}

void Date::show(){
	cout<<getYear()<<"/"<<getMonth()<<"/"<<getDay()<<endl;
}