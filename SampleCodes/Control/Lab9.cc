/*
	File: Lab9.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 10; i++){
		if(i == 3 || i == 6) break;
		cout << i << ", ";
	}
	cout << endl;
	return 0;
}