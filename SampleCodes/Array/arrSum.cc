/*
	File name: arrSum.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[5] = {100, 200, 300, 400, 500};

	int sum = 0;

	sum += data[0];
	sum += data[1];
	sum += data[2];
	sum += data[3];
	sum += data[4];

	cout << "sum: " << sum << endl;

	return 0;
}

