/*
	File name: incDecOp.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int testVarA = 10, testVarB = 20, testVarC = 30, testVarD =40;

	cout << "++testVarA: " << ++testVarA << endl;          	// 11
	cout << "testVarA++: " << testVarA++ << endl;	       	// 11
	cout << "testVarA: " << testVarA << endl;				// 12
	cout << "--testVarB: " << --testVarB << endl;			// 19
	cout << "testVarB--: " << testVarB-- << endl;			// 19
	cout << "testVarB: " << testVarB << endl;				// 18
	cout << "testVarC + testVarD++: " << testVarC + testVarD++ << endl; // 70
	cout << "testVarC + ++testVarD: " << testVarC + ++testVarD << endl; // 72

	return 0;
}
