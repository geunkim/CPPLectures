/*
	File: Lab5.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int value;

	cout << "정수를 입력하시오: ";
	cin >> value;

	if(value % 2)
		cout << " A " << endl;
	else 
		cout << " B " << endl;
	return 0;
}