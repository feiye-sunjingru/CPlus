// 7_3.cpp
#include <string>
#include <iostream> 
using namespace std;

class Base1{
	public:
		virtual ~Base1(){ //不是虚函数 
			cout<<"析构一个Base1."<<endl;
		} 
		virtual void display() const{
			cout<<"Base1::display()"<<endl;
		}
};

class Base2:public Base1{
	public:
		~Base2(){ //不是虚函数 
			cout<<"析构一个Base2."<<endl;
		};  
		void display() const{
			cout<<"Base2::display()"<<endl;
		}
};
class Derived:public Base1{
	public:
		Derived(){
			p = new int(1);
		}
		~Derived(){
			cout<<"析构一个Derived."<<endl;
		}
		void display() const{
			cout<<"Derived::display()"<<endl;
		}
	private:
		int *p;
};
void func(Base1* ptr){  // 想把它变化成Base2\derived\base1 
	ptr->display();
}
void func2(Base1* b){
	delete b;  // 静态绑定，只会调用~Base1() 
}

int main(){
	/*Base1 base1;
	Base2 base2;
	Derived derived;
	
	func(&base1);
	func(&base2);
	func(&derived);*/
	
	Base1*b = new Derived();  // Base1类型，Derived对象 
	func2(b);
	return 0; 
}