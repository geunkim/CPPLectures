/*
	File name: bitShiftOp.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	short testVarA = 10, testVarB = -32768;
	unsigned short testVarC = 16382;
 
	cout << "testVarA: " << bitset<16>(testVarA) << endl;
	cout << "testVarB: " << bitset<16>(testVarB) << endl;
	cout << "testVarC: " << bitset<16>(testVarC) << endl;

	testVarA <<= 1,	testVarB >>= 2, testVarC <<= 1;

	cout << "testVarA: " << testVarA << endl;
	cout << "testVarB: " << testVarB << endl;
	cout << "testVarC: " << testVarC << endl;

	return 0;
}
