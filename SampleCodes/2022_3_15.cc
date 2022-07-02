#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	short b;
	char c;  //
	long d;
	long long e;

	std::cout << sizeof(a) << std::endl;
	cout << sizeof(short) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;

	float f;
	double g;
	long double h;




	c = 'A';

	d = 123.4567;

	cout << c << endl;
	cout << (int)c << endl;

	cout << d << endl;
	c = c + 1;
	c = c + 31;

	cout << c << endl;


	return 0;
}