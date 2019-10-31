// CPU.cpp 
# include <iostream>

using namespace std;

enum CPU_Rank{P1=1, P2, P3, P4, P5, P6, P7};  // 1~7

class CPU{
	public:
		void run(){
			cout<<"CPU开始运行！"<<endl;
		}
		
		void stop(){
			cout<<"CPU停止运行！"<<endl;
		}
		
		CPU(CPU_Rank rank, int frequency, float voltage):
			rank(rank),frequency(frequency),voltage(voltage){
			cout<<"构造了一个CPU！"<<endl;
		}
		
		~CPU(){
			cout<<"析构了一个CPU！"<<endl;
		}
		
		CPU_Rank getRank(){
			return rank;
		}
		
		void setRank(CPU_Rank rtmp){
			rank = rtmp;
		}
		
		int getFrequency(){
			return frequency;
		}
		
		void setFrequency(int ftmp){
			frequency = ftmp;
		}
		
		float getVoltage(){
			return voltage;
		} 
		
		void setVoltage(float fvol){
			voltage = fvol;
		}
		
	private:
		CPU_Rank rank;
 		int frequency;
	    float voltage;
}; 


int main12(){
	CPU a(P6, 300, 2.8);
	a.run();
	a.stop();
	return 0;
} 
