#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	for(int i = 1; i < 200; i *= 2)
		n += 1;

	cout << n << endl;
	return 0;
}
