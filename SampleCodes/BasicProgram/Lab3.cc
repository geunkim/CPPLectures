/*
	File: Lab3.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int dividend = 15;
	int divisor = 4;
	double result;

	result = dividend / (double)divisor;

	cout << dividend << "/" << divisor << " = " << result << endl;


	return 0;
}