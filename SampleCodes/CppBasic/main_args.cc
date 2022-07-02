/*
	File: main_args.cc
	Author: Geun-Hyung Kim

	Description: 
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int idx = 0;
	cout << "argc: " << argc << endl;
	while (idx < argc) {
		cout << argv[idx] << endl;
		idx++;
	}	
	return 0;
}