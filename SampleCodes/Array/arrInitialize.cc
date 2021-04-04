/*
	File name: arrInitialize.cc
	Author: Geun-Hyung Kim
	Description: 
	배열을 초기화 시키는 프로그램 

	Date: 2021. 3. 21
	Version: 0.1. 0
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[5] = {100, 200, 300};

	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;

	int zero[5] = {0};

	for(auto data : zero) 
		cout << data << endl;

	return 0;
}

