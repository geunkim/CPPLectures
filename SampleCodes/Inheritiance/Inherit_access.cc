#include <iostream>
using namespace std;

class A{
	public: int w;
};
class B : public A{
	public: int x;
};
class C : private A {
	public: int y;
};
class D: protected B {
	public: int z;
};

int main(int argc, char const *argv[])
{
	A a; a.w = 10;
	B b; b.w = 10;
	C c; c.y = 10;
	D d; d.w = 10;
	
	return 0;
}