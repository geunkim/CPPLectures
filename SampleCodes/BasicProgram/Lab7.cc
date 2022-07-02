/*
	File: Lab7.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 100, b = 200, c = 300;
	char d ='a', e = 'A', f = 'b';


	cout << (d == f) << endl;
	cout << (d == (f -1)) << endl;
	cout << (a > b) << endl;
	cout << (a < c) << endl;
	cout << (e != f) << endl;

	return 0;
}