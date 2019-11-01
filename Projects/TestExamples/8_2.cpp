// 8_2.cpp
#include <string>
#include <iostream> 
using namespace std;

class Clock{
	public: // 先加1，后操作 
		Clock(int hour=0, int minute=0, int second=0):hour(hour),minute(minute),second(second){
		}	
		void showTime() const{
			cout<<"hour:"<<hour<<",minute:"<<minute<<",second:"<<second<<endl;
		}
		// 前置单目运算符重载
		Clock& operator++(){
			second++;
			if(second >= 60){
				second -= 60; minute++;
				if(minute >= 60){
					minute -= 60; 
					hour = (hour+1)%24;
				}
			} 
			return *this;	
		} 
		// 后置单目运算符重载（为了区分前置，实际上形参是不用的 ） 
		Clock operator++(int){
			Clock old = *this; // 先操作，后+1 
			++(*this);
			return old;
		}
	private:
		int hour, minute, second; 
};

int main26(){
	Clock myClock(23, 59, 59);
	cout<<"First time output:";
	myClock.showTime();
	cout<<"Show myClock++:";
	(myClock++).showTime();
	cout<<"Show ++myClock:";
	(++myClock).showTime();
	return 0;
} 