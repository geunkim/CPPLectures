/*
	File: Lab8.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;


void increase(int x){
	x++;
}

int main(int argc, char const *argv[])
{
	int x = 10;

	increase(x);

	cout << "출력: " <<  x << endl;

	return 0;
}


