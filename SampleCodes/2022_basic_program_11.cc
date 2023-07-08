#include <iostream>
using namespace std;

class Base{
public:
	Base() { cout << "base constructor" << endl;}
	~Base() { cout << "base destructor" << endl;}
	virtual void func() { cout << "base func" << endl;}
};

class Derived : public Base
{
public:
	Derived() { cout << "derived constructor" << endl;}
	~Derived() { cout << "derived destructor" << endl;}
	virtual void func() { cout << "derived func" << endl;}
};

int main(int argc, char const *argv[])
{
	Base bvar, *bptr;
	Derived dvar;
	bvar.func();
	dvar.func();

	bptr = &dvar;
	bvar.func();

	bptr = &dvar;
	bptr->func();

	return 0;
}