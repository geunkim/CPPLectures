/*

	File Name: simpleCompare.cc
	Author: Geun-Hyung Kim

	Description: 두 개의 정수의 값을 비교하여 대소를 표시한다. 
	Date: 2021. 3. 29
	Version: 0. 1. 0
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x = 10;
	int y = 20;

	if(x > y)
		cout << "x(" << x << ")는 " << "y(" << y << ")보다 크다." << endl;
	else
		cout << "y(" <<y << ")는 " << "x(" <<x << ")보다 크거나 같다." << endl;
	return 0;
}