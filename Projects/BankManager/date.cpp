// date.cpp
 #include <iostream>
 #include <cstdlib> // exit函数
 #include "date.h"
 using namespace std;
 
 namespace{  // namespace使下面的定义只在当前文件中有效 
 	// 存储平年中每个月1日之前有多少天。为便于getMaxDay()的实现，该数组多出一项 
 	const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
 }
 
 Date::Date(int year, int month, int day):year(year),month(month),day(day){
 	if(day<=0 || day>getMaxDay()){
	 	cout<<"Invalid date:";
	 	show();
	 	cout<<endl;
	 	exit(1); // 非0表示异常退出，0表示正常退出 
	 } 
	 int years = year-1;
	 totalDays = years*365+years/4-years/100+years/400+DAYS_BEFORE_MONTH[month-1]+day;
	 if(isLeepYear() && month>2){ 
		 totalDays++;
	 } 
 }
 
int Date::getMaxDay()const{
	if(isLeepYear()&&month==2){
		return 29;
	}else{
		return DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
	} 	
 }
 
 void Date::show() const{
 	cout<<getYear()<<"/"<<getMonth()<<"/"<<getDay()<<endl;
 }