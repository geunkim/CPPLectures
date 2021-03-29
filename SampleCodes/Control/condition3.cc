/*
	File Name: condtion3.cc
	Author: Geun-Hyung Kim

	Description: 삼항조건식(?:)을 활용하여 절대 값을 계산하는 프로그램 

*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	short num;
	cout << "정수를 입력하시오: ";
	cin >> num;
	cout << "입력 정수: " << num << endl;
	short absNum = (num > 0) ? num : -num; 

	cout << "abs(" << num << "): " << absNum << endl;

	return 0;
}
