/*
	File: Lab8.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	bool a = true, b = false;
	int c = 10, d = 20;


	cout << "[출력 1]: " << !b << endl;      		// 논리 부정
	cout << "[출력 2]: " << (a && b) << endl;  		// 논리 곱 
	cout << "[출력 3]: " << (a || b) << endl;  		// 논리 합

	cout << "[출력 4]: " << (c != d || a) << endl;  // 관계 연산과 논리 합
	cout << "[출력 5]: " << (c < d && b) << endl;   // 관계 연산과 논리 곱

	cout << "[출력 6]: " << (c > 5 && c < 15) << endl; 	// 관계 연산자와 논리 곱
	cout << "[출력 7]: " << (c <= 5 || c >=15) << endl;   // 관계 연산자와 논리 합

	return 0;
}