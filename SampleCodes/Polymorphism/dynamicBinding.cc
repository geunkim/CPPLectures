/*
	File name: dynamicBinding.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;


class Base {
public:
	virtual void check(){    	// 가상 함수 
		cout << "Base::check()" << endl;
	}
};

class Derived: public Base {	
public:
	void check() {				// 가상 함수
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
	
	parentRef.check(); // 부모 클래스의 참조 변수를 통한 자식 클래스의 멤버 함수 호출

	parentPtr = &parent; 
	parentPtr->check();  // 부모 클래스의 포인터 변수를 통한 부모 클래스의 멤버 함수 호출

	parentPtr = &child; 
	parentPtr->check(); // 부모 클래스의 포인터 변수를 통한 자식 클래스의 멤버 함수 호출 

	childPtr = &child;
	childPtr->check();  // 자식 클래스의 포인터 변수를 통한 자식 클래스의 멤버 함수 호출 


	return 0;
}