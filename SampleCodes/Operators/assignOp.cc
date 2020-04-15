/*
	File name: incDecOp.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int testVarA = 10, testVarB = 20, testVarC = 30, testVarD =40;

	testVarA += 10;
	cout << "testVarA: " << testVarA << endl;
	testVarB -= 30;
	cout << "testVarB: " << testVarB << endl;
	testVarC *= 2;
	cout << "testVarC: " << testVarC << endl;
	testVarD /= 2;
	cout << "testVarD(/=2): " << testVarD << endl;
	testVarD <<= 1;
	cout << "testVarD(<<=1): " << testVarD << endl;

	return 0;
}

