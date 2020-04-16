/*
	File name: doWhileInput.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char inChar;
	do
	{
		cout << "Input (char): ";
		cin >> inChar;
	}while(inChar != 'z');

	return 0;
}

