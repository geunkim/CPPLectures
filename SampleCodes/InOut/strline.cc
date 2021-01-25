/*
	File: strline.cc
	Author: Geun-Hyung Kim
	Description:
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char inbuf[100];

	cout << "문자열을 입력하시오: ";
	cin.getline(inbuf, 100, '\n');

	cout << "length of input string: " << strlen(inbuf) <<endl;
	cout << "input data: " << inbuf << endl;

	return 0;
}