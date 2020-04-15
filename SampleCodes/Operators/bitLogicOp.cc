/*
	File name: bitLogicOp.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	short testVarA = 10, testVarB = 20;
	short resultVarA;

	cout << "testVarA: " << bitset<16> (testVarA) << endl;
	cout << "testVarB: " << bitset<16> (testVarB) << endl;

	resultVarA = testVarA | testVarB;
	cout << "testVarA | testVarB: " << bitset<16> (resultVarA) << endl;
	resultVarA = testVarA & testVarB;
	cout << "testVarA & testVarB: " << bitset<16> (resultVarA) << endl;
	resultVarA = testVarA ^ ~testVarB;
	cout << "testVarA ^ ~testVarB: " << bitset<16> (resultVarA) << endl;
	resultVarA = ~testVarA;
	cout << "~testVarA: " << bitset<16> (resultVarA) << endl;

	return 0;
}

