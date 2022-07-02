/*
	File: lvalue_ref_bound_error.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x = 5;
	int y = 6;

	int& ref = x; // ref -> y 의 의미 

	cout << "x: " << x << endl;
	cout << "&x: "<< &x << endl;       // 변수 x의 저장공간 주소 
	cout << "&ref: " << &ref << endl;  // ref의 저장공간 주소 

	ref = y;   // ref -> y 가 아닌 x = y 와 동일한 것 

	cout << "x: " << x << endl;
	cout << "&x: "<< &x << endl;       // 변수 x의 저장공간 주소 
	cout << "&ref: " << &ref << endl;  // ref의 저장공간 주소

	return 0;
}
