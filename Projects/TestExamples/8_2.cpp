// 8_2.cpp
#include <string>
#include <iostream> 
using namespace std;

class Clock{
	public: // �ȼ�1������� 
		Clock(int hour=0, int minute=0, int second=0):hour(hour),minute(minute),second(second){
		}	
		void showTime() const{
			cout<<"hour:"<<hour<<",minute:"<<minute<<",second:"<<second<<endl;
		}
		// ǰ�õ�Ŀ���������
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
		// ���õ�Ŀ��������أ�Ϊ������ǰ�ã�ʵ�����β��ǲ��õ� �� 
		Clock operator++(int){
			Clock old = *this; // �Ȳ�������+1 
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