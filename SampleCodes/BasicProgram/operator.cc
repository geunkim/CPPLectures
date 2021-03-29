#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x, y, z;
	x = 10;
	y = 20;

	z = --x + y;

	cout << "x: " << x << ",y: " << y << ",z : " << z << endl;

	return 0;
}