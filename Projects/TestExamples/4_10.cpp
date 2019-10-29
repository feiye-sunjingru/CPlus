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
			cout<<"CPU��ʼ���У�"<<endl;
		}
		
		void stop(){
			cout<<"CPUֹͣ���У�"<<endl;
		}
		
		CPU(CPU_Rank rank, int frequency, float voltage):
			rank(rank),frequency(frequency),voltage(voltage){
			cout<<"������һ��CPU��"<<endl;
		}
		
		~CPU(){
			cout<<"������һ��CPU��"<<endl;
		}
		
		CPU_Rank getRank(){
			return rank;
		}
		
		CPU(CPU& cpu):
			rank(cpu.rank),frequency(cpu.frequency),voltage(cpu.voltage){
			cout<<"����������һ��CPU��"<<endl;
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
			cout<<"RAM��ʼ���У�"<<endl;
		}
		
		void stop(){
			cout<<"RAMֹͣ���У�"<<endl;
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
			cout<<"������һ��RAM��"<<endl;
		}
		
		RAM(RAM & ram):
			capacity(ram.capacity),type(ram.type),mainFrequency(ram.mainFrequency){
			cout<<"����������һ��RAM��"<<endl;
		} 
		
		~RAM(){
			cout<<"������һ��RAM��"<<endl;
		}	
			
	private:
		int capacity;
		Type type;
		int mainFrequency;
};

class CDROM{
	public:
		void run(){
			cout<<"CDROM��ʼ���У�"<<endl;
		}
		
		void stop(){
			cout<<"CDROMֹͣ���У�"<<endl;
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
			cout<<"������һ��CDROM��"<<endl;
		}
		CDROM(CDROM & cdrom):
			interfaceType(cdrom.interfaceType), cacheCapacity(cdrom.cacheCapacity), 
				installMode(cdrom.installMode){
			cout<<"����������һ��CDROM��"<<endl;
		} 		
		~CDROM(){
			cout<<"������һ��CDROM��"<<endl;
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
			cout<<"�������У�"<<endl;
		}
		
		void stop(){
			cpu.stop();
			ram.stop();
			cdrom.stop();			
			cout<<"����ֹͣ��"<<endl;
		}
		
		Computer(CPU cpu, RAM ram, CDROM cdrom, unsigned int storage_size, unsigned int bandwidth)
			:cpu(cpu),ram(ram),cdrom(cdrom),storage_size(storage_size),bandwidth(bandwidth){
			cout<<"Computer ������ɣ�"<<endl;
		}
		
		~Computer(){
			cout<<"������һ��computer!"<<endl;
		}
		
		
	private:
		CPU cpu;
		RAM ram;
		CDROM cdrom;
		unsigned int storage_size;  // GB
		unsigned int bandwidth; // MB ���� 
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
	Computer computer(a, r, c, 100, 80); // ����������a\r\c�β� 
	computer.run();
	computer.stop();
	cout<<"************************"<<endl;	// ��������computer��a+r+c 
} 

