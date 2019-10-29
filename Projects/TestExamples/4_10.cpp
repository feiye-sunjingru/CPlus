// 4_10.cpp 
# include <iostream>

using namespace std;

enum CPU_Rank{P1=1, P2, P3, P4, P5, P6, P7};  // 1~7
enum class Type{DDR4, DDR3, DDR2};
enum class InterfaceType{SATA, USB};
enum class InstallMode{external, builtin};

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
		
		CPU(CPU& cpu):
			rank(cpu.rank),frequency(cpu.frequency),voltage(cpu.voltage){
			cout<<"拷贝构造了一个CPU！"<<endl;
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

class RAM{
	public:
		void run(){
			cout<<"RAM开始运行！"<<endl;
		}
		
		void stop(){
			cout<<"RAM停止运行！"<<endl;
		}
		
		int getCapacity(){
			return capacity; 
		}
		void setCapacity(int tmp){
			capacity = tmp;
		}
		
		Type getType(){
			return type;
		}
		void setType(Type tmp){
			type = tmp;
		}
		
		int getMainFrequency(){
			return mainFrequency;
		}
		void setMainFrequency(int tmp){
			mainFrequency = tmp;
		}
		
		RAM(int capacity, Type type, int mainFrequency):
			capacity(capacity),type(type),mainFrequency(mainFrequency){
			cout<<"构造了一个RAM！"<<endl;
		}
		
		RAM(RAM & ram):
			capacity(ram.capacity),type(ram.type),mainFrequency(ram.mainFrequency){
			cout<<"拷贝构造了一个RAM！"<<endl;
		} 
		
		~RAM(){
			cout<<"析构了一个RAM！"<<endl;
		}	
			
	private:
		int capacity;
		Type type;
		int mainFrequency;
};

class CDROM{
	public:
		void run(){
			cout<<"CDROM开始运行！"<<endl;
		}
		
		void stop(){
			cout<<"CDROM停止运行！"<<endl;
		}
		
		InterfaceType getInterfaceType(){
			return interfaceType;
		}
		void setInterfaceType(InterfaceType tmp){
			interfaceType = tmp;
		}	
			
		int getCacheCapacity(){
			return cacheCapacity;
		}
		void setCacheCapacity(int tmp){
			cacheCapacity = tmp;
		}		

		InstallMode getInstallMode(){
			return installMode;
		}
		void setCacheCapacity(InstallMode tmp){
			installMode = tmp;
		}
		CDROM(InterfaceType interfaceType, int cacheCapacity, InstallMode installMode)
			:interfaceType(interfaceType), cacheCapacity(cacheCapacity), installMode(installMode){
			cout<<"构造了一个CDROM！"<<endl;
		}
		CDROM(CDROM & cdrom):
			interfaceType(cdrom.interfaceType), cacheCapacity(cdrom.cacheCapacity), 
				installMode(cdrom.installMode){
			cout<<"拷贝构造了一个CDROM！"<<endl;
		} 		
		~CDROM(){
			cout<<"析构了一个CDROM！"<<endl;
		}
				
	private:
		InterfaceType interfaceType;
		int cacheCapacity;
		InstallMode installMode;
};

class Computer{
	public:
		void run(){
			cpu.run();
			ram.run();
			cdrom.run();
			cout<<"电脑运行！"<<endl;
		}
		
		void stop(){
			cpu.stop();
			ram.stop();
			cdrom.stop();			
			cout<<"电脑停止！"<<endl;
		}
		
		Computer(CPU cpu, RAM ram, CDROM cdrom, unsigned int storage_size, unsigned int bandwidth)
			:cpu(cpu),ram(ram),cdrom(cdrom),storage_size(storage_size),bandwidth(bandwidth){
			cout<<"Computer 构造完成！"<<endl;
		}
		
		~Computer(){
			cout<<"析构了一个computer!"<<endl;
		}
		
		
	private:
		CPU cpu;
		RAM ram;
		CDROM cdrom;
		unsigned int storage_size;  // GB
		unsigned int bandwidth; // MB 带宽 
};

int main13(){
	CPU a(P6, 300, 2.8);
	a.run();
	a.stop();
	cout<<"************************"<<endl;
	RAM r(10, Type::DDR4, 66);
	r.run();
	r.stop();
	cout<<"************************"<<endl;
	CDROM c(InterfaceType::SATA, 9, InstallMode::external);
	c.run();
	c.stop();
	cout<<"************************"<<endl;
	Computer computer(a, r, c, 100, 80); // 创建完析构a\r\c形参 
	computer.run();
	computer.stop();
	cout<<"************************"<<endl;	// 最终析构computer、a+r+c 
} 

