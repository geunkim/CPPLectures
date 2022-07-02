/*
	File: Lab12.cc
	Author: Geun-Hyung Kim


*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int result = 1;

	for(int i = 2; i <= 16; i++)
		result *= i;

	cout << result << endl;
	return 0;
}