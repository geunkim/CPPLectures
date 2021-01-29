/*
	File: ioWrite.cc

	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[] = "Hello world!";

	cout.write(str, strlen(str));
	cout.put('\n');
	return 0;
}