/*
	File: lvalue_scope.cc
	Author: Geun-Hyung Kim
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x {6};

	{
		int& ref {x};
		cout << "internal scope: " << ref << endl;
	}
	cout << "outer scope(x): " << x << endl;
	cout << "outer scope(ref): " << ref << endl;

	return 0;
	
}