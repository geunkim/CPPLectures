/*
	File: Lab11.cc
	Author: Geun-Hyung Kim


*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum;
	sum = 1+2+3+4+5+6+7+8+9+10;  // 1 ~ 10 까지의 정수 더하기 

	cout << "(1): 1+2+3+4+5+6+7+8+9+10 = " << sum << endl;
	
	sum = 0;
	for(int i = 1; i <= 10; i++){
		// 프로그램 코드 영역 (1 ~ 10 까지의 정수 더하는 코드)
		sum += 1;
    }

	cout << "(2): 1+2+3+4+5+6+7+8+9+10 = " << sum << endl;

	return 0;
}