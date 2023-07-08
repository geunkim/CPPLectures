#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	
	const int x = 5;
	int &ref = x;
	ref = 5;

	const int &ref1 = x;
	ref1 = 7;
	
	int y = 5;
	const int &ref2 = y;
	ref2 = 5;
	const int &ref3 = y;
	y = 7;

	return 0;
}

