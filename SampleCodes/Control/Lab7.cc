/*
	File: Lab7.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int value;
	cout << "1 ~ 3 중의 정수를 입력하시오: ";
	cin >> value;

	switch(value){
		case '1':
			cout << "1이 입력" << endl;
			break;
		case '2':
			cout << "2가 입력" << endl;
			break;
		case '3':
			cout << "3이 입력" << endl;
			break;
		default:
			cout << "원하는 수가 아니다" << endl;		
	}

	return 0;
}