/*
	File name: simpleArrAssign.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[5];

	data[0] = 10, data[1] = 20;				  // assign value
	data[2] = 30, data[3] = 40, data[4] = 50; // assign value

	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;

	return 0;
}
