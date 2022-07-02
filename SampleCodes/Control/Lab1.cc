/*
	File: Lab1.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int input;
	do {
		cout << "정수를 입력하시오: ";
		cin >> input;
		cout << "입력값: " << input << endl;
	}while(input != 0);
	
	return 0;
}