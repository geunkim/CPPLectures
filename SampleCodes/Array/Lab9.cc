/*
	File: Lab9.cc (in Array)
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	char name[] = "Chul-Soo Kim";
	int values[] = {10, 40, 50, 60, 80, 100};

	num = sizeof(name)/sizeof(name[0]);
	cout << "num_of_name: " << num << endl;
	num = sizeof(values)/sizeof(values[0]);
	cout << "num of values: " << num << endl;

	return 0;
}