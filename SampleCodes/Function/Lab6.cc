/*
	File: Lab6.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float x, y;

	cout << "실수 두개를 입력하시오: " << endl;
	cin >> x >> y;
	
	cout << mul(x, y) << endl;
	return 0;
}

void mul(float a, float b) {
	return a * b;
}
