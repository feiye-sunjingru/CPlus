// 4_4.cpp 
# include <iostream>
# include <cmath> 
using namespace std;
class Point{
	public:
		Point(int xx=0, int yy=0){
			x = xx;
			y = yy;
		}
		Point(Point &p); 

		~Point(){
			
		}
		
		int getX(){
			return x;
		};
		
		int getY(){
			return y;
		};
	
	private:
		int x, y;
}; 

Point::Point(Point& p){  // 先完成参数传递 
	x = p.x;
	y = p.y;
	cout<<"Calling the copy constructor of Point"<<endl;			
} // =delete指示编译器不生成默认复制构造函数 

class Line{
	public:
		// 组合类的构造函数，把xp1复制给p1，再是xp2给p2 
		Line(Point xp1, Point xp2):p1(xp1),p2(xp2){
			cout<<"Calling constructor of Line"<<endl;
			int x = static_cast<int>(p1.getX()-p2.getX());
			int y = static_cast<int>(p1.getY()-p2.getY());
			len = sqrt(x*x + y*y); 
		}
		
		// 组合类的拷贝构造函数 
		Line(Line & l):p1(l.p1),p2(l.p2){
			cout<<"Calling the copy constructor of Line"<<endl;
			len = l.len;
		}
		
		double getLen(){
			return len;
		}
	private:
		double len;
		Point p1, p2;
}; 

int main6(){
	Point myp1(1,1), myp2(4,5);
	// 先把myp2复制给形参，再是myp1 
	Line line(myp1, myp2);
	Line lin2(line);
	cout<<"The length of the line is:"<<line.getLen()<<endl;
	cout<<"The length of the line2 is:";
	return 0;
}
