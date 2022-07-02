/*
	File: lvalue_reference.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x {10};
	int& ref {x};

	cout << "(after modify) x: " << x << endl;  // 10 출력

	ref = 40;

	cout << "(after modify) x: " << x << endl;  // 40 출력
	return 0;
}