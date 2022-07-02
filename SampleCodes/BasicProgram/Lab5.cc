/*
	File: Lab5.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 100, b = 200;
	double c = 10.123, d = 20.456;

	cout << "a: " << a << ", ";
	cout << "b: " << b << ", ";
	cout << "c: " << c << ", ";
	cout << "d: " << d << endl;

	a = c;
	b = d;

	cout << "a: " << a << ", ";
	cout << "b: " << b << endl;

	return 0;
}