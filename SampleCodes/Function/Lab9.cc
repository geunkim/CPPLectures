/*
	File: Lab9.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

double div_eq(double x = 10, double y = 20) {
	return x / y; 
}

int main(int argc, char const *argv[])
{
	cout << "출력(1): " << div_eq() << endl;
	cout << "출력(2): " << div_eq(5) << endl;
	cout << "출력(3): " << div_eq(50, 10) << endl;
	return 0;
}