/*
	File: Lab6.cc (in Array)
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float data[10], initlal_value = 10.1;

	for(int i = 0; i < 10; i++){
		data[i] = initlal_value + 0.3 * i;
	}

	for(int i = 0; i < 10; i++)
		cout << data[i] << ", ";

	cout << endl;
	return 0;
}