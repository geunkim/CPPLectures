/*
	File: Lab7.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

void swap1(int x, int y){
	cout << "(swap1 연산 전 출력) x:" << x <<", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap1 연산 후 출력) x:" << x <<", y: " << y << endl;
}


void swap2(int &x, int &y){
	cout << "(swap2 연산 전 출력) x:" << x <<", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap2 연산 후 출력) x:" << x <<", y: " << y << endl;
}


int main(int argc, char const *argv[])
{
	int x = 10, y = 20;

	cout << "(출력 1) x: "  << x << ", y: " << y << endl;
	swap1(x, y);
	cout << "(출력 2) x: "  << x << ", y: " << y << endl;
	swap2(x, y);
	cout << "(출력 3) x: "  << x << ", y: " << y << endl;

	return 0;
}