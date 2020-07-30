/*
	File name: functionOverriding.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void print() {
		cout << "print() in base class" << endl;
	}
	void show() {
		cout << "show() in base class" << endl;
	}
};

class Derived : public Base
{
public:
	void print() {
		cout << "print() in derived class" << endl;
	}
	void show() {
		cout << "show() in derived class" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Base b, *bptr;
	Derived d;

	b.print(); // Base 클래스의 print() 함수 호출
	d.print(); // Derived 클래스의 print() 함수 호출

	bptr = &d;     // Derived의 객체 d를 Base 자료형의 포인터 변수에 저장
	bptr->print(); // Base 포인터 변수를 통해 Derived 객체의 print() 함수 호출
	bptr->show();  // Base 포인터 변수를 통해 Base 객체의 show() 함수 호출

	return 0;
}