/*
	File: Lab2.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0, num;
	cout << "반복 횟수를 입력하시오: ";
	cin >> num;

	while(count < num) {
		cout << "repeat (" << count << ")" << endl;
		count++;
	}
	return 0;
}