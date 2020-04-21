/*
	File name: arrPrint.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[5];

	int idx = 0; 
	while(idx < 5) {
		data[idx] = (idx + 1) * 10;
		idx++;
	}

	for(idx = 0; idx < 5; idx++)
		cout << "data[" << idx << "]: " << data[idx] << endl; 

	// cout << "data[0]: " << data[0] << endl;
	// cout << "data[1]: " << data[1] << endl;
	// cout << "data[2]: " << data[2] << endl;
	// cout << "data[3]: " << data[3] << endl;
	// cout << "data[4]: " << data[4] << endl;

	return 0;
}


