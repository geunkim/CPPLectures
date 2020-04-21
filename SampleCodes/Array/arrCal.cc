/*
	File name: arrCal.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[5];

	data[0] = 10;
	data[1] = 30 - 10;
	data[2] = data[0] + 2*data[1];
	data[3] = data[2] + 20;
	data[4] = data[0] - data[3];

	for(int i = 0; i < 5; i++)
		cout << "data[" << i << "]: " << data[i] << endl; 

	return 0;
}




