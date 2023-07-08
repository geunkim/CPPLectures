#include <iostream>
using namespace std;

class A{
public:
	int f() {return 1;}
	virtual int g() {return 2;}
};

class B: public A{
public:
	int f() {return 3;}
	int g() {return 4;}
};

class C: public A{
public:
	int g() {return 5;}
};

int main(int argc, char const *argv[])
{
	A *ptr, a;
	B b;
	C c;

	ptr = &b; cout << ptr->f() << ", " << ptr->g() << ", ";
	ptr = &c; cout << ptr->g() + ptr->f() << ", ";
	ptr = &a; cout << ptr->f() << ", " << ptr->g() << endl;

	return 0;
}

