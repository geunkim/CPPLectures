/*
	File: Lab4.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int value;

	cout << "정수를 입력하시오: ";
	cin >> value;

	if(value > 10) 	
		cout << "입력한 값은 " << value << endl;
		cout << "10보다 큰 정수이다" << endl;
	else 
		cout << "10보다 작은 정수이다" << endl;

	return 0;
}