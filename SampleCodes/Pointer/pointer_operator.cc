/*
	File: pointer_operator.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 10, b = 20;
	int *ptr;

	ptr = &a;
	cout << "포인터 변수(ptr)가 가리키는 주소(&a)에 저장된 값: " << *ptr << endl;
	ptr = &b;
	cout << "포인터 변수(ptr)가 가리키는 주소(&b)에 저장된 값: " << *ptr << endl;

	return 0;
}