/*
	File: simple_scope.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	{
		int value = 10;
	}
	value = 20;

	cout << "value: " << value << endl;

	return 0;
}