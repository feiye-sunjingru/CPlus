// date.h
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date{
public:
	Date(int year, int month, int day);
	int getMaxDay() ;
	void show() ; // 输出当前日期 
	
	int getYear() {return year;}
	void setYear(int tmp){year = tmp;}
	int getMonth() {return month;}
	int getDay() {return day;}
	int getTotalDays() {return totalDays;}
	
	bool isLeepYear(){
		if((year%4==0&&year%100!=0)||year%400==0) return true;
		return false;
	}
	
	int getDisYears(Date& date){ 
		int disYears = date.year - year;
		if(date.getTotalDays()>=totalDays){	
			if(date.getMonth()<month){
				disYears = disYears - 1;
			}
			if(date.getMonth()==month && date.getDay()<day){
				disYears = disYears - 1;
			}
		}else{
			if(date.getMonth()>month){
				disYears = disYears + 1;
			}
			if(date.getMonth()==month && date.getDay()>day){
				disYears = disYears + 1;
			}
		}
		return disYears;
	}
	
	int getDisMonths(Date& date){
		int disYears = getDisYears(date);
		int disMonths = (date.month - month + 12)%12;
		if(date.getTotalDays()>=totalDays){
			if(date.day < day){
				disMonths -= 1;
			}
			return 12*disYears+disMonths;
		}else{
			disMonths = (month - date.month + 12)%12;
			if(date.day > day){
				disMonths -= 1;
			}
			return 12*disYears-disMonths; // 负值 
		}
	}
	
	int operator -(Date& date)const{  // 运算符重载operator 
		return totalDays-date.totalDays;
	}
	
	int operator +(int days)const{  // 运算符重载operator 
		return totalDays+days;
	}
	
private:
	int year;
	int month;
	int day;
	int totalDays; // 相对于公元元年1月1日相距的日期 
};

#endif
 