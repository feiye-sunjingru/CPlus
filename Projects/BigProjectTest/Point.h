// 文件1，类的定义，Point.h 
class Point{
	public:  // 外部接口 
		Point(int x=0, int y=0);
		Point(const Point &p);
		~Point();
		
		int getX() const{return x;}
		
		int getY() const{return y;}
		
		static void showCount(); // 静态函数成员 
		
		friend float dist(const Point& a, const Point& b);
	
	private:
		int x, y;
		static int count; // 静态数据成员声明，用于记录点的个数 
};