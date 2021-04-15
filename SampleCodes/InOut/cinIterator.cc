/*
	File Name: inIterator.cc
	Author: Geun-Hyung Kim

	Description:
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[10];

	for(int i = 0; i < 10; i++){
		cin >> data[i];
	}

	cout << "output:" << endl;

	for(auto d : data)
		cout << d << endl;

	return 0;
}