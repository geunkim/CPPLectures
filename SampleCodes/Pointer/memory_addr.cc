/*
	File: memory_addr.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

	int ivar1, ivar2;
	char cvar1, cvar2;
	short svar1, svar2;
	long long lvar1, lvar2;
	long double dvar1, dvar2;
	
	cout << "변수 ivar1, ivar2에 할당된 메모리 주소: " << &ivar1 << ", " << &ivar2 << endl;
	cout << "변수 cvar1, cvar2에 할당된 메모리 주소: " << &cvar1 << ", " << &cvar2 << endl;
	cout << "변수 svar1, svar2에 할당된 메모리 주소: " << &svar1 << ", " << &svar2 << endl;
	cout << "변수 lvar1, lvar2에 할당된 메모리 주소: " << &lvar1 << ", " << &lvar2 << endl;
	cout << "변수 dvar1, dvar2에 할당된 메모리 주소: " << &dvar1 << ", " << &dvar2 << endl;

	return 0;
}