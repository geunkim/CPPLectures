#include <iostream>
using namespace std;

class A {
public:
	A() {cout << "a" << ", ";}
	~A() {cout << "A" << ", ";}
};

class B {
public:
	B() {cout << "b" << ", ";}
	~B() {cout << "B" << ", ";}
};

class C {
public:
	C() {cout << "c" << ", ";}
	~C() {cout << "C" << ", ";}
};

C c;
int main(int argc, char const *argv[])
{
	A a;
	{
		B b;
	}
	A d;
	return 0;
}

