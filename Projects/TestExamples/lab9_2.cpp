#include <iostream>
#include <cstdlib>
using namespace std;

struct Student {
	int id;
	float gps;
};

template <class T>
class Store {
private:
	T item;
	bool haveValue; // ���item�Ƿ��ѱ���������
public:
	Store() :haveValue(false) {}
	T& getElem() { // ��ȡ����
		if (!haveValue) {
			cout << "No item present!" << endl;
			exit(1);
		}
		return item;
	} 
	void putElem(const T& x) { // �������ݺ���
		haveValue = true;
		item = x;
	}
};

int main4() {
	Store<int> s1, s2;
	s1.putElem(3);
	s2.putElem(-7);
	cout << s1.getElem() << "  " << s2.getElem() << endl;

	Student g = { 1000,23 };
	Store<Student>s3;
	s3.putElem(g);
	cout << "The student id is:" << s3.getElem().id << endl;

	Store <double> d;
	cout << "Retriving object D...";
	cout << d.getElem() << endl;
	return 0;
}