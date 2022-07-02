
#include "common.h"
#include <iostream>
using namespace std;

int find_max(int data[]){
	int ret = MIN;

	for(int i = 0; i < ELEMENTS; i++)
		if( data[i] > ret) ret = data[i];

	return ret;
}

int main(int argc, char const *argv[])
{
	int x = 20, y = 40;

	cout << min(x, y) << endl;

	return 0;
}