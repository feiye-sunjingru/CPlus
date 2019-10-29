// 4_2.cpp 
# include <iostream>
# include <cmath> 
using namespace std;

class Point{
	public:
		Point(int xx=0, int yy=0){
			x = xx;
			y = yy;
			count++; 
		}
		Point(const Point &p){ // ����ɲ�������
			x = p.x;
			y = p.y;
			count++;
			cout<<"Calling the copy constructor"<<endl;		
		} // =deleteָʾ������������Ĭ�ϸ��ƹ��캯�� 

		~Point(){
			count--;
		}
		
		int getX(){
			return x;
		}
		
		int getY(){
			return y;
		}
		
		void showCount() const{
			cout<<"Object count="<<count<<endl;
		}
		
		friend float dist(const Point& a, const Point& b);
	
	private:
		int x, y;
		static int count; // ��̬���ݳ�Ա���������ڼ�¼��ĸ��� 
}; 	

int Point::count = 0; // ��̬���ݳ�Ա�����������ʼ��	

float dist(const Point& a, const Point& b){  // �ⲿ����˽�г�Ա������Ч�ʣ�û����get����ҪfriendȨ��
	double x = a.x - b.x;
	double y = a.y - b.y;
	return static_cast<float>(sqrt(x*x+y*y)); 
}
void fun1(Point& p){
	cout<< p.getX()<<endl;
} 

/*ע�⣺g++�����˱����Ż�ֱ��ʹ����fun()�ķ��ض��󣬿������캯��û�б�����
  ��Ҫʹ�ÿ������캯������Ҫ��g++ -fno-elide-constructors testReturn.cpp*/
Point fun2(){
	Point a(1,2);
	return a;  // ���ص�ֵ��Ҫ��ɸ��ƹ��� 
} 

int main(){
	Point a;  // ��һ������a 
	Point b(a);  // Q1:��a��ʼ��b����1�ε��ÿ������캯�� 
	cout<<b.getX()<<endl;
	fun1(b); // Q2:����b��Ϊfunc1��ʵ�Σ���2�ε��ÿ������ƺ��� 
	b = fun2();  // Q3:�����ķ���ֵ������󣬺�������ʱ�����ù��캯�� 
	cout<<b.getX()<<endl;
	cout<<"****************************"<<endl;
	b.showCount(); 
	cout<<"****************************"<<endl;
	cout<<dist(a,b)<<endl;
	return 0;
}
