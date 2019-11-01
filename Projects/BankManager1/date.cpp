// date.cpp
 #include <iostream>
 #include <cstdlib> // exit����
 #include "date.h"
 using namespace std;
 
 namespace{  // namespaceʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч 
 	// �洢ƽ����ÿ����1��֮ǰ�ж����졣Ϊ����getMaxDay()��ʵ�֣���������һ�� 
 	const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
 }
 
 Date::Date(int year, int month, int day):year(year),month(month),day(day){
 	if(day<=0 || day>getMaxDay()){
	 	cout<<"Invalid date:";
	 	show();
	 	cout<<endl;
	 	exit(1); // ��0��ʾ�쳣�˳���0��ʾ�����˳� 
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