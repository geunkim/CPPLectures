/*
	File name: runtimeErrorEx.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

int factorial(int n) {
	return n * factorial(n-1);
}

int main(int argc, char const *argv[])
{
	cout << factorial(10) << endl;
	return 0;
}