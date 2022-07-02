/*
	File: lvalue_ref_bound_error.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x = 5;
	int y = 6;

	int& ref = x;

	cout << "x: " << x << endl;
	cout << "&x: "<< &x << endl;
	cout << "&ref: " << &ref << endl; 

	ref = y;

	cout << "x: " << x << endl;
	cout << "&x: "<< &x << endl;
	cout << "&ref: " << &ref << endl; 	

	return 0;
}
