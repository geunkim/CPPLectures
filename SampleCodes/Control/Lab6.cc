/*
	File: Lab6.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch;
	cout << "A, B, C 문자 중 하나를 입력하시오:";
	cin >> ch;

	switch (ch) {
		case 'A':
			cout << "A" << endl;
			break;
		case 'B':
			cout << "B"	<< endl;
			break;
		case 'C':
			cout << "C" << endl;
			break;
		default:
			cout << "원하는 문자가 아니다" << endl;

	}

	return 0;
}