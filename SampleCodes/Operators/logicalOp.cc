/*
	File name: logicalOp.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int testVarA = 10, testVarB = 20;
	bool testBoolA = true, testBoolB = false;
	int *ptr = NULL;

	cout << (testVarA == 10 || testBoolB) << endl;   	 // true
	cout << ((testBoolA) && (testVarA != 10)) << endl;   // false
	cout << (testBoolA && !testBoolB) << endl;		     // true
	cout << (testVarA >= 0 && testVarA <= 20) << endl;   // true
	cout << (testVarA < 0 || testVarA > 20) << endl;     // false
	//  단락 논리
	cout << (ptr == NULL || *ptr == 10) << endl;         // true
	
	// cout << (*ptr == 10) << endl;				     // Segmentation fault

	return 0;
}

