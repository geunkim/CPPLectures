/*
	File: Lab8.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch;
	cout << "(a, A, , b, B, c, C) 문자 중 하나를 입력하시오:";
	cin >> ch;

	switch (ch) {
		case 'A':
		case 'a':
			cout << "A 또는 a" << endl;
			break;
		case 'B':
		case 'b':
			cout << " B 또는 b"	<< endl;
			break;
		case 'C':
		case 'c':
			cout << "C 또는 c" << endl;
			break;
		default:
			cout << "원하는 문자가 아니다" << endl;

	}

	return 0;
}