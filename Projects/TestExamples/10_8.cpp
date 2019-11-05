// 10_8.cpp
#include <queue>
#include <iostream>
#include <time.h>
using namespace std;


// 模拟一种细胞在诞生（即上次分裂）后会在500~2000s内分裂为两个细胞，每个细胞又按照同样的规律继续分裂
const int SPLIT_TIME_MIN = 500; // 细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000; // 细胞分裂最长时间

class Cell;
priority_queue<Cell>cellQueue;

class Cell{
private:
	static int count; // 细胞总数
	int id; // 当前细胞编号
	int time; // 细胞分裂时间 
public:
	Cell(int birth):id(count++){ // birth为细胞诞生时间
		// 初始化，确定细胞分裂时间
		// rand在处理之后变成了在SPLIT_TIME_MIN~SPLIT_TIME_MAX之间的随机数 
		time = birth + (rand()%(SPLIT_TIME_MAX-SPLIT_TIME_MIN))+SPLIT_TIME_MIN; 
	}
	int getId() const{return id;} // 得到细胞编号
	int getSplitTime() const{return time;} // 得到细胞分裂时间
	bool operator <(const Cell& s)const{ // 定义< 
		return time>s.time; // 我们希望分裂时间早的细胞比较大 
	} // 优先弹出分裂时间早的细胞 
	
	void split()const{ // 细胞分裂 
		Cell child1(time), child2(time); // 建立两个子细胞
		cout<<time<<"s:Cell #"<<id<<" splits to #"
			<<child1.getId()<<" and #"<<child2.getId()<<endl;
		cellQueue.push(child1); // 将第一个子细胞压入优先级队列
		cellQueue.push(child2);  
	}
};
int Cell::count = 0;

int main48(){
	srand(static_cast<unsigned>(time(0))); // 随机数种子，通过系统时间取得的，这样每次运行结果是不同的 
	int t; // 模拟时间长度，多长时间范围内观察分裂过程 
	cout<<"Simulation time:";
	cin>>t;
	cellQueue.push(Cell(0)); // 将第一个细胞压入优先级队列
	while(cellQueue.top().getSplitTime()<=t){
		cellQueue.top().split(); // 模拟下一个细胞的分裂
		cellQueue.pop(); // 将刚刚分裂的细胞弹出 
	}
	return 0; 
} 