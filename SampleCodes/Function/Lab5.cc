/*
	File: Lab5.cc
	Author: Geun-Hyung Kim


 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "# of input parameters: " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << argv[i] << endl;
	return 0;
}
