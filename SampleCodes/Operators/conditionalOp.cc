/*
	File name: conditionalOp.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int testVarA = 10, testVarB = 20;

	(testVarA == 10) ? testVarB += 5 : testVarB -= 5;

	cout << "testVarB: " << testVarB << endl;     // 25

	(testVarA != 10) ? testVarB += 20 : testVarB -= 20;

	cout << "testVarB: " << testVarB << endl;     // 5

	return 0;
}
