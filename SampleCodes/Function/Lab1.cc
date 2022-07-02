/*
	File: Lab1.cc (in Function)
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int sum(int a, int b);   // 함수 선언 (function declaration)


int main(int argc, char const *argv[])
{
	int x = 10, y = 30;

	int result = sum(x, y);  // 함수 호출 (function call)

	cout << x << " + " << y << " = " << result << endl;

	return 0;
}

// 함수 sum을 정의하여야 하는 영역 
int sum(int i, int j) { return i + j;}