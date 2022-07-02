/*
	File: lvalue_reference_init.cc
	Author: Geun-Hyung Kim

 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x { 30 };
	int& ref{ x };

	int& invalidRef; // error in reference initialization

	return 0;
}