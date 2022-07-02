/*
	File: Lab3.cc
	Author: Geun-Hyung Kim


 */
#include <iostream>
using namespace std;

int min_value(int a, int b);  // (4) min 함수 호출


int main(int argc, char const *argv[]) // (2) main 함수 정의
{

	cout << min_value(3, 5) << endl;   // (1) 함수 호출 

	return 0;
}

int min_value(int x, int y){ return x > y ? y : x;} // (3) min 함수 정의

