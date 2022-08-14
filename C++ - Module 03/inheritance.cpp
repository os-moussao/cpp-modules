#include <iostream>
#include <string>
using namespace std;

class C {
	public:
		virtual void dec() {};
};

class A: C {
	protected:
		int x;
	public:
		A(): x(0) {}
		A(int x): x(x) {}
		void setX(int x) { this->x = x; }
		int getX() { return x; }
		void incX() { x++; }
		void dec() { x--; }
};

class B: public A {
	protected:
		int y;
	public:
		B(): A(), y(0) {}
		B(int x, int y) : A(x), y(y) {}
		void setY(int y) { this->y = y; }
		int  getY(int y) { return y; }
		void incY() { y++; }
};

class D: public B {
	public:
		int z;
		D(): B(), z(0) {}
};

int main () {
	D d;
	cout << d.getX() << endl;
}