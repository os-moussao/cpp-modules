#include <iostream>
#include <string>
using namespace std;

class A
{
	protected:
		string name;
	public:
		A(): name("Awbx") {
			cout << "A constractor called\n";
		};
		string get() { return name; }
		virtual void set(string name) { this->name = name; }
		virtual ~A() {
			cout << "A destructor called\n";
		};
};


class B: virtual public A
{
	public:
		B() {
			cout << "B constractor called\n";
		}
		virtual ~B() {
			cout << "B destructor called\n";
		}
};

class C: virtual public A
{
	public:
		C() {
			cout << "C constractor called\n";
		}
		virtual ~C() {
			cout << "C destructor called\n";
		}
};

class D: public B, public C
{
	private:
		string name;
	public:
		D() {
			cout << "D constractor called\n";
		}
		void show() { 
			cout << this->name << " " << A::name << " " << B::name << " " << C::name << endl;
		}
		void set(string name) {
			this->name = name;
		}
		~D() {
			cout << "D destructor called\n";
		}
};

int main() {
	D d;
	d.set("Oussama");
	d.show();
}