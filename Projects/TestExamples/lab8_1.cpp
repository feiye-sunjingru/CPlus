#include <iostream>
using namespace std;

class Point {
protected:
	int _x, _y;
public:
	Point(int x = 0, int y = 0) :_x(x), _y(y) {}
	Point& operator ++();
	Point operator ++(int); // 后置
	Point& operator --();
	Point operator --(int);
	friend ostream& operator<<(ostream& o, Point& p); // 重载插入运算符
};

Point& Point::operator ++() {
	_x++;
	_y++;
	return *this;
}

// 后缀的版本中，返回值是尚未自增的原值，但对象本身已经做了自增的操作了 
Point Point::operator ++(int) {
	Point old = *this;  // 直接返回当前对象
	++(*this); // 然后再++
	return old;
}

Point& Point::operator --() {
	_x--;
	_y--;
	return *this;
}

Point Point::operator --(int) {
	Point old = *this;  // 直接返回当前对象
	--(*this); // 然后再++
	return old;
}

ostream& operator << (ostream& out, Point& p) {
	out << "(" << p._x << "," << p._y << ")";
	return out;
}


int main32() {
	Point p(1, 2);
	cout << p << endl;
	cout << p << endl; p++; 
	cout << ++p << endl;
	cout << p << endl; p--;
	cout << --p << endl;
	return 0;
}