/*
	File: rvalue_ref_string.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = string("H") + "E" + string("LL") + "O" + "!";
	cout << s << endl;
	return 0;
}