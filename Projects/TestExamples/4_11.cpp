// CPU.cpp 
# include <iostream>

using namespace std;

enum SEX{Man, WOMAN}; 

class Date{
	public:
		Date(string year, string month, string day):year(year),month(month),day(day){
		}
		string getYear(){
			return year;
		}
		void setYear(string tmp){
			year = tmp;
		}
		string getMonth(){
			return month;
		}
		void setMonth(string tmp){
			month = tmp;
		}						
		string getDay(){
			return day;
		}
		void setDay(int tmp){
			day = tmp;
		}
		string inline getDate(){
			return year+"-"+month+"-"+day;
		}			
	private:
		string year;
		string month;
		string day;
}; 

class People{
	public:
		People(int myNumber, SEX mySex, Date myBirthday, string myId):birthday(myBirthday){
			number = myNumber;
			sex = mySex;
			id = myId;
			cout<<"������һ��People!"<<endl; 
		}
		People(People& p):number(p.number),sex(p.sex),birthday(p.birthday),id(p.id){
			cout<<"����������һ��people��"<<endl;
		}
		~People(){
			cout<<"������һ��People!"<<endl;
		}		
		
		void show(){
			cout<<"��Ա����ţ�"<<number<<", �Ա�"<<sex<<", ���գ�"<<
			birthday.getDate()<<", id:"<<id<<endl;
		}
		
	private:
		int number;
		SEX sex;
		Date birthday;
		string id;
};

int main14(){
	Date birth("2012","3","6");
	People people(1, Man, birth, "0000001");
	people.show();
}