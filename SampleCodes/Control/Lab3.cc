/*
	File: Lab3.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int input;
	cout << "정수를 입력하시오: ";
	cin >> input;

	if(input <= 100) {
		cout << "100 이하 정수이다" << endl;
	}

	cout << "100 초과 정수이다" << endl;

	return 0;
}