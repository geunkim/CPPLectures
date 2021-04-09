/*
	File Name: randomNum.cc
	Author: Geun-Hyung Kim

	Description: 
	0 ~ 7 사이의 난수를 생성하는 프로그램
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(static_cast<unsigned int> (time(NULL)));

	for(int i = 0; i < 10; i++) {
		cout << "random number[" << i << "]: " << rand() % 7 << endl;
	}
	return 0;
}