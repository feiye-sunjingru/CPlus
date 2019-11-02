#include <iostream>
using namespace std;

template <typename T>
T abs(T x) {
	return x < 0 ? -x : x;
};

template <typename T>
void outputArray(const T* array, int count) {
	for (int i = 0; i < count; i++) {
		cout << array[i] << " ";  // 如果数组元素是类的对象，需要该对象重载流插入运算符<<
	}
	cout << endl;
}

int main6() {
	int n = -5;
	double d = -5.5;
	cout << abs(n) << endl;
	cout << abs(d) << endl;
	cout << "*******************************************" << endl;

	const int A_COUNT = 8, B_COUNT = 8, C_COUNT = 20;
	int a[A_COUNT] = { 1,2,3,4,5,6,7,8};
	outputArray(a, A_COUNT);
	double b[B_COUNT] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8 };
	outputArray(b, B_COUNT);
	char c[C_COUNT] = "Welcome!";
	outputArray(c, C_COUNT);

	return 0;
}