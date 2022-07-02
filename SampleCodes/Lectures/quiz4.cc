#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	
	short a = 138;
	short b;

	b = a++;
	cout << a << endl;

	a = ++b;
	cout << b << endl;

	return 0;
}


