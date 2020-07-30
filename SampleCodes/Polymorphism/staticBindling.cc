/*
	File name: staticBinding.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;


class Base {
public:
	void check(){    
		cout << "Base::check()" << endl;
	}
};

class Derived: public Base {
public:
	void check() {
		cout << "Derived::check()" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Base parent, *parentPtr;
	Derived child, *childPtr;
	Base &parentRef = child;

	parent.check();	// 부모 클래스의 멤버 함수 호출 
	child.check();	// 자식 클래스의 멤버 함수 호출
	parentRef.check();	// 자식 클래스를 부모 클래스의 참조 변수로 참조하여 부모 클래스의 멤버 함수 호출

	parentPtr = &parent; 
	parentPtr->check();  // 부모 클래스 포인터 변수로 부모 클래스 멤버 함수 호출 

	parentPtr = &child;
	parentPtr->check();  // 자식 클래스를 부모 클래스의 포인터 변수로 참조하여 부모 클래스의 멤버 함수 호출

	childPtr = &child;
	childPtr->check();  // 자식 클래스 포인터 변수를 통해 자식 클래스의 멤버 함수 호출

	return 0;
}