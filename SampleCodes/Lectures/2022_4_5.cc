#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	
	int c = 20;
	int b = 50;
	{
		int b = 30;
		cout << c + 100 << endl;
		cout << b << endl;
	}
	cout << c + 200 << endl;
	cout << b << endl;

	return 0;
}