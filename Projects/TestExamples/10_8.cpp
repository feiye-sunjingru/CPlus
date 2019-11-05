// 10_8.cpp
#include <queue>
#include <iostream>
#include <time.h>
using namespace std;


// ģ��һ��ϸ���ڵ��������ϴη��ѣ������500~2000s�ڷ���Ϊ����ϸ����ÿ��ϸ���ְ���ͬ���Ĺ��ɼ�������
const int SPLIT_TIME_MIN = 500; // ϸ���������ʱ��
const int SPLIT_TIME_MAX = 2000; // ϸ�������ʱ��

class Cell;
priority_queue<Cell>cellQueue;

class Cell{
private:
	static int count; // ϸ������
	int id; // ��ǰϸ�����
	int time; // ϸ������ʱ�� 
public:
	Cell(int birth):id(count++){ // birthΪϸ������ʱ��
		// ��ʼ����ȷ��ϸ������ʱ��
		// rand�ڴ���֮��������SPLIT_TIME_MIN~SPLIT_TIME_MAX֮�������� 
		time = birth + (rand()%(SPLIT_TIME_MAX-SPLIT_TIME_MIN))+SPLIT_TIME_MIN; 
	}
	int getId() const{return id;} // �õ�ϸ�����
	int getSplitTime() const{return time;} // �õ�ϸ������ʱ��
	bool operator <(const Cell& s)const{ // ����< 
		return time>s.time; // ����ϣ������ʱ�����ϸ���Ƚϴ� 
	} // ���ȵ�������ʱ�����ϸ�� 
	
	void split()const{ // ϸ������ 
		Cell child1(time), child2(time); // ����������ϸ��
		cout<<time<<"s:Cell #"<<id<<" splits to #"
			<<child1.getId()<<" and #"<<child2.getId()<<endl;
		cellQueue.push(child1); // ����һ����ϸ��ѹ�����ȼ�����
		cellQueue.push(child2);  
	}
};
int Cell::count = 0;

int main48(){
	srand(static_cast<unsigned>(time(0))); // ��������ӣ�ͨ��ϵͳʱ��ȡ�õģ�����ÿ�����н���ǲ�ͬ�� 
	int t; // ģ��ʱ�䳤�ȣ��೤ʱ�䷶Χ�ڹ۲���ѹ��� 
	cout<<"Simulation time:";
	cin>>t;
	cellQueue.push(Cell(0)); // ����һ��ϸ��ѹ�����ȼ�����
	while(cellQueue.top().getSplitTime()<=t){
		cellQueue.top().split(); // ģ����һ��ϸ���ķ���
		cellQueue.pop(); // ���ոշ��ѵ�ϸ������ 
	}
	return 0; 
} 