#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 100, b = 200;
	int &ref = a;
	int *ptr = &b;

	*ptr = *ptr + 100;

	cout << ref << ", ";
	cout << *ptr << ", ";

	a += b++; 
	*ptr += ++ref;
	
	cout << ref << ", ";
	cout << *ptr << endl;

	return 0;
}

