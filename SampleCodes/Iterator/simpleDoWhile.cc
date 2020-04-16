/*
	File name: simpleDoWhile.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0;
	do 
	{
		cout << count << ": Hello World!" << endl;
		count++;
	}while(count < 10);

	return 0;
}



