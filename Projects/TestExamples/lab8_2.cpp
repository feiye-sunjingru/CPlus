#include <iostream>
using namespace std;

class Vehicle {
public:
	int maxSpeed;
	int weight;
	virtual void run() {
		cout << "vehicle run!" << endl;
	}
	virtual void stop() {
		cout << "vehicle stop!" << endl;
	}
};

class Bicycle: public Vehicle {
public:
	virtual void run() {
		cout << "Bicycle run!" << endl;
	}
	virtual void stop() {
		cout << "Bicycle stop!" << endl;
	}
};

class MotorCar : public Vehicle {
public:
	virtual void run() {
		cout << "MotorCar run!" << endl;
	}
	virtual void stop() {
		cout << "MotorCar stop!" << endl;
	}
};

class MotorBicycle : public Bicycle, public MotorCar {
public:
	virtual void run() {
		cout << "MotorBicycle run!" << endl;
	}
	virtual void stop() {
		cout << "MotorBicycle stop!" << endl;
	}
};

void func(Vehicle* ptr) {
	ptr->run();
	ptr->stop();
}

int main29() {
	Vehicle v;
	func(&v);
	return 0;
}