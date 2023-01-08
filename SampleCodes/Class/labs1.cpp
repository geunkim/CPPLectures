#include <iostream>

using namespace std;

class A
{
	int num = 100;
public:
	void setNum(int num) { this->num = num; }
	int getNum() { return num; }
};

class B
{
	A a;
public:
	B() {
		a.setNum(10);
	}
	int getA_num() { return a.getNum(); }
	A getA() { return a; }
};

int main(int argc, const char* argv[])
{
	B b;
	cout << b.getA_num() << endl;
	
	A a;
	a = b.getA();

	cout << a.getNum() << endl;

	return 0;
}