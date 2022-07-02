#include <iostream>
using namespace std;


void mySwap(int c, int d);
void Swap(int *c, int *d);
void yourSwap(int& c, int &d);

int main(int argc, char const *argv[])
{
	int a = 10, b = 20;

	cout << "Before mySwap(a, b)" << endl; 
	cout << "a: " << a << ", b: " << b << endl;
	mySwap(a, b);
	cout << "a: " << a << ", b: " << b << endl;
	cout << "Before Swap(&a, &b)" << endl;
	a = 10, b = 20;
	Swap(&a, &b);
	cout << "a: " << a << ", b: " << b << endl;
	cout << "Before yourSwap(a, b)" << endl;
	a = 10, b = 20;
	yourSwap(a, b);
	cout << "a: " << a << ", b: " << b << endl;
	return 0;
}

void mySwap(int c, int d){

	cout << __FUNCTION__ << endl;
	
	cout << "c: " << c << ", d: " << d << endl;
	int tmp = c;
	c = d;
	d = tmp;
	cout << "c: " << c << ", d: " << d << endl;

}

void yourSwap(int &c, int& d){

	cout << __FUNCTION__ << endl;

	cout << "c: " << c << ", d: " << d << endl;
	int tmp = c;
	c = d;
	d = tmp;
	cout << "c: " << c << ", d: " << d << endl;	

}

void Swap(int *c, int *d){

	cout << __FUNCTION__ << endl;
	cout << "c: " << *c << ", d: " << *d << endl;
	int tmp = *c;
	*c = *d;
	*d = tmp;
	cout << "c: " << *c << ", d: " << *d << endl;	

}