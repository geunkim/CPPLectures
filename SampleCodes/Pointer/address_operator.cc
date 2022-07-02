/*
	File: address_operator.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data;

	cout << "data 변수를 위해 할당된 메모리 주소: " <<  &data << endl;

	cout << &data <<"에 저장된 데이터: " << *(&data) << endl;

	*(&data) = 200;     // 변수 data의 저장공간에 정수 값 200 저장

	cout << &data <<"에 저장된 데이터: " << *(&data) << endl;

	data = 400;			// 변수 data에 정수 값 400 저장  

	cout << &data <<"에 저장된 데이터: " << *(&data) << endl;

	cout << "data 변수에 저장된 데이터: " << data << endl;

	return 0;
}