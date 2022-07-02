/*
	File: Lab2.cc (in Function)
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

/**
 * add_10: 입력하는 정수 값에 10을 더해서 반환하는 함수
 * @param {int} in [정수 매개변수]
 * @return {int}
 */
int add_10(int in) {               // 함수 정의

}

int main(int argc, char const *argv[])
{
	int data;

	cout << "정수를 입력하시요: ";
	cin >> data;

	cout <<	add_10(data) << endl;  // 함수 호출 

	return 0;
}