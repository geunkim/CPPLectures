/*
	File name: arrayWhile.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[5];

	int idx = 0; 
	while(idx < 5) {
		data[idx] = (idx + 1) * 10;
		idx++;
	}

	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;

	return 0;
}


