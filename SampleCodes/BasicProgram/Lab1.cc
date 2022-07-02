/*

	File: Lab1.cc
	Author: Geun-Hyung Kim


*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned short a, b;       // 변수 a, b 선언에 적합한 자료형 명시
	int result;     // 두 수를 더한 값과 곱한 값을 저장하기 위한 변수 result 선언 - 자료형 명시

	a = 15000;
	b = 20000;

	// 다음 줄에 두 수를 더하고 result 변수에 저장하는 연산 코드를 작성  
	result = a + b;

	cout << "두 수 덧셈 결과: " << result << endl;

	// 다음 줄에 두 수를 곱하고 result 변수에 저장하는 연산 코드를 작성

	result = a * b;
	cout << "두 수 곱셈 결과: " << result << endl;

	return 0;
}