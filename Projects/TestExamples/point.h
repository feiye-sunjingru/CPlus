// point.h 
# include <iostream>
# include <cmath> 
using namespace std;
	
class Point{
	public:
		Point(int xx=0, int yy=0){
			x = xx;
			y = yy;
			count++; 
			cout<<"Default Constructor called."<<endl;
		}
		Point(const Point &p){ // 先完成参数传递
			x = p.x;
			y = p.y;
			count++;
			cout<<"Calling the copy constructor"<<endl;		
		} // =delete指示编译器不生成默认复制构造函数 

		~Point(){
			count--;
			cout<<"Destrcutor called."<<endl;
		}
		
		int getX()const{
			return x;
		}
		
		int getY()const{
			return y;
		}
		
		void move(int myx, int myy){
			x = myx;
			y = myy;
		}
		
		void showCount() const{
			cout<<"Object count="<<count<<endl;
		}
		
		friend float dist(const Point& a, const Point& b);
	
	private:
		int x, y;
		static int count; // 静态数据成员声明，用于记录点的个数 
}; 	

