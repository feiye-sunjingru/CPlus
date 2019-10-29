// �ļ�1����Ķ��壬Point.h 
class Point{
	public:  // �ⲿ�ӿ� 
		Point(int x=0, int y=0);
		Point(const Point &p);
		~Point();
		
		int getX() const{return x;}
		
		int getY() const{return y;}
		
		static void showCount(); // ��̬������Ա 
		
		friend float dist(const Point& a, const Point& b);
	
	private:
		int x, y;
		static int count; // ��̬���ݳ�Ա���������ڼ�¼��ĸ��� 
};