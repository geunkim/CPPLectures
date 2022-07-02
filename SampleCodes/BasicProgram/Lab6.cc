/*
	File: Lab6.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 2, b = 3, c = 4;

	// 질문 1: +, * 의 연산 우선순위
	// 출력 1
	cout << "[출력 1] " << a + b * c << endl;
	// 출력 2
	cout << "[출력 2] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 질문 2: +=, *= 연산자 의미
	a += b;
	b *= c++;

	// 출력 3
	cout << "[출력 3] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	c %= a;

	// 출력 4
	cout << "[출력 4] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 질문 3: =, +,-- 순서 
	c = b + --a;

	// 출력 5
	cout << "[출력 5] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 질문 4: =, +, -- 순서 
	c = b + a--;

	// 출력 6
	cout << "[출력 6] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 잘문 5: 후위 증가와 전위 증가의 차이점 
	b = c++;  // 후위 증가
	c = ++a;  // 전위 증가
	// 출력 7
	cout << "[출력 7] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	return 0;
}