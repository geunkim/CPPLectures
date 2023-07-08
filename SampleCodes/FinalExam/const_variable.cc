#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int x = 10;
	const int& y = x;

	x = 20;
	y = 30;
	
	return 0;
}

