#include <iostream>
using namespace std;

int threeMax(int a, int b, int c) {
	if(a >= b && a >= c) 
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;

}

int main(int argc, char const *argv[])
{
	cout << threeMax(10, 15, 5) << endl;
	cout << threeMax(30, 10 ,30) << endl;
	cout << threeMax(10, 30, 50) << endl;

	return 0;
}