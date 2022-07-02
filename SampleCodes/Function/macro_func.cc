/*
	File: macro_func.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

#define inc(x) ((x) = ((x) + 3))

int main(int argc, char const *argv[])
{
	int i = 10;
	int count = 1;

	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;

	return 0;
}