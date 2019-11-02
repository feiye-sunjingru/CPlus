#include <iostream>
using namespace std;

class Point {
	int _x, _y;
public:
	Point(int x = 0, int y = 0) :_x(x), _y(y) {}
	Point& operator ++();
	Point& operator ++ (int); // ����
	Point& operator --();
	Point& operator --(int);
	friend ostream& operator<<(ostream& o, Point& p); // ���ز��������
};

Point& Point::operator ++() {
	_x++;
	_y++;
	return *this;
}

Point& Point::operator ++(int) {
	Point old = *this;  // ֱ�ӷ��ص�ǰ����
	++* this; // Ȼ����++
	return old;
}

Point& Point::operator --() {
	_x--;
	_y--;
	return *this;
}

Point& Point::operator --(int) {
	Point old = *this;  // ֱ�ӷ��ص�ǰ����
	--* this; // Ȼ����++
	return old;
}

ostream& operator << (ostream& out, Point& p) {
	out << "(" << p._x << "," << p._y << ")";
	return out;
}


int main2() {
	Point p(1, 2);
	cout << p << endl;
	cout <<p++<< endl;
	cout << ++ p << endl;
	cout << p-- << endl;
	cout << -- p << endl;
	return 0;
}