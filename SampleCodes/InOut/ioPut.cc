/*
	File: ioPut.cc
	
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;

	while(i < 5){
		cout.put(65+i);
		i++;
	}
	cout.put('\n');

	return 0;
}