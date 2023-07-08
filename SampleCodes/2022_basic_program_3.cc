#include <iostream>
using namespace std;

class base{
public:
	void func() {v();}
	virtual void v() { cout<< "b" << ", ";}
};

class derived1 : public base {
public:
	void v() { cout << "d1" << ", ";}
};

class derived2 : public base {
public:
	void v() { cout << "d2" << ", ";}
};

int main(int argc, char const *argv[])
{
	base r, *ptr;
	derived1 d1;
	derived2 d2;

	d1.v(), d2.v(), r.v(), r.func();

	ptr = &d1;
	ptr->v(), ptr->func();

	ptr = &d2;
	ptr->v(), ptr->func();
	cout << endl;

	return 0;
}

