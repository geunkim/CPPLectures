/*
	File: Lab8.cc (in Array)
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[10];

	for(int i = 0; i < 10; i++) {
		data[i] = (i + 1);
	}

	for(int i = 1; i < 10; i++) {
		data[0] += data[i];
	}
	
	cout << data[0] << endl;

	return 0;
}