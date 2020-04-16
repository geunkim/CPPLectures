/*
	File name: forRandom.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
#include <cstdlib>	// srand, rand 함수 때문에 필요
#include <ctime>	// time 함수 때문에 필요
using namespace std;

int main(int argc, char const *argv[])
{
	int randNum = 0;
	srand(time(NULL));

	for(;randNum != 5;)  // randNum 이 5가 아닐 때 계속
	{
		randNum = rand() % 10;
		cout << randNum << endl;
	}
	return 0;
}


