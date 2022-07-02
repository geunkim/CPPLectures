#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 100;
	int b = 300;
	int& c = b;
	int d = 400;

	c = 200;

	cout << b << endl;
	c = d;	
	cout << b << endl;
	b = a;
	cout << c << endl;

	return 0;
}

