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
		Point(const Point &p){ // ����ɲ�������
			x = p.x;
			y = p.y;
			count++;
			cout<<"Calling the copy constructor"<<endl;		
		} // =deleteָʾ������������Ĭ�ϸ��ƹ��캯�� 

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
		static int count; // ��̬���ݳ�Ա���������ڼ�¼��ĸ��� 
}; 	

