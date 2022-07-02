
#include "common.h"
#include <iostream>
using namespace std;

int find_min(int data[]){
	int ret = MAX;

	for(int i = 0; i < ELEMENTS; i++)
		if( data[i] < ret) ret = data[i];

	return ret;
}

int main(int argc, char const *argv[])
{
	int x = 30, y = 50;

	cout << max(x, y) << endl;

	return 0;
}