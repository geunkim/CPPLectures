/*
	File name: relationOp.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int testVarA = 10, testVarB = 20;
	float resultVarA = 0.1;

	cout << "(testVarA == 10): " << (testVarA == 10) << endl;		  // 같은가?	  
	cout << "(testVarA != testVarB): " << (testVarA != testVarB) << endl;     // 같지 않은가?
	cout << "(testVarA > testVarB): " << (testVarA > testVarB) << endl;	  // 큰가?
	cout << "(testVarA < testVarB): " << (testVarA < testVarB) << endl;       // 작은가?
	cout << "(testVarA >= (testVarB - 10): " << (testVarA >= (testVarB - 10)) << endl;

	cout << "(sqrt(3.0)*sqrt(3.0) == 3.0): " << (sqrt(3.0)*sqrt(3.0) == 3.0) << endl;

	return 0;
}

