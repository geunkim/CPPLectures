#include <iostream>
using namespace std;

class Base{

};

class Derived : public Base {

};


int main(int argc, char const *argv[])
{
	Base a;
	Derived b;
	Base *pa = new Base;
	Derived *pb = new Derived;
	Base *pa1 = new Derived;
	Derived *pb1 = new Base;

	return 0;
}


