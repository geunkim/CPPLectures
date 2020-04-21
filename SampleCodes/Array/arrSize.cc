/*
	File name: arrSize.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	cout <<"배열에 할당된 메모리 크기: " << sizeof(data) << endl;
	cout <<"배열의 데이터 요소에 할당된 메모리 크기: " << sizeof(data[0]) << endl;
	cout <<"배열의 크기: " << sizeof(data)/sizeof(data[0]) << endl;

	return 0;
}


