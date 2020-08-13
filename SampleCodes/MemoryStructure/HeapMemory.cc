/*
	File name: HeapMemory.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	static int a = 10;
	static int b = 20;
	int c; 
	int d;
	int *intPtr1 = new int[5];
	int *intPtr2 = new int[5];

	cout << "address of a: " << &a << endl;
	cout << "address of b: " << &b << endl;
	cout << "address of c: " << &c << endl;
	cout << "address of d: " << &d << endl;
	cout << "address of intPtr1: " << intPtr1 << endl;
	cout << "address of intPtr2: " << intPtr2 << endl;

	return 0;
}