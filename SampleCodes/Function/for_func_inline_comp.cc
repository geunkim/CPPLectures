/*
	File: for_func_comp.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

void inc(int& x) {
	x += 3;
}

int main(int argc, char const *argv[])
{
	int i = 10;
	int count = 1;

	do {
		cout << "(" << count++ << ") "; inc(i); cout << i << endl;		
	}while(count <= 20);

	return 0;
}