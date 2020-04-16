/*
	File name: simpleWhile.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0;
	while (count < 10) 
	{
		cout << count << ": Hello World!" << endl;
		count++;
	}
	return 0;
}

