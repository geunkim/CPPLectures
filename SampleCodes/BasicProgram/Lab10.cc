/*
	File: Lab10.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	
	int value1 = 2;
	int value2 = 256;

	cout << "[value1 << 1]" << (value1 << 1) << endl;
	cout << "[value1 << 2]" << (value1 << 2) << endl;
	cout << "[value1 << 3]" << (value1 << 3) << endl;

	cout << "[value2 << 1]" << (value2 << 1) << endl; 
	cout << "[value2 >> 1]" << (value2 >> 1) << endl; 
	cout << "[value2 >> 2]" << (value2 >> 2) << endl; 
	cout << "[value2 >> 3]" << (value2 >> 3) << endl; 

	return 0;
}