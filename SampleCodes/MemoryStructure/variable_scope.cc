/*
	File: variable_scope.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

void func();

int value = 5;               // scope 0

int main(int argc, char const *argv[])
{
	int value = 10;  		 // scope 1-0
	int value1 = 40;  		// scope 1-1

	{
		int value = 20;  	 // scope 2	
		{ 
			int value = 30;  // scope 3
			cout << "(scope 3) value: " << value << ", 주소: " << &value << endl;
			cout << "(scope 1-1) value1: " << value1 << ", 주소: " << &value1 << endl;
			cout << "(scope 0) value: " << ::value << ", 주소: " << &(::value) << endl;
			value1 = 60;
		}
		cout << "(scope 2) value: " << value << ", 주소: " << &value << endl;
	}

	cout << "(scope 1-1) value1: " << value1 << ", 주소: " << &value1 << endl;
	::value = 50; 
	func();
	cout << "(scope 1-0) value: " << value << ", 주소: " << &value << endl;

	return 0;
}

void func() {

	cout << "in func(scope 0): " << value << ", 주소: " << &value << endl;
}