/*
	File: Lab10.cc
	Author: Geun-Hyung Kim


*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

	for(int i = 0; i < 10; i++){
		cout << (i % 4);
		if( i != 9) cout << ", ";
	}
	cout << endl;	

	return 0;
}