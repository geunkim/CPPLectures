#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0;
	for(int i = 0; i <= 9; i++)
		for(int j = 0; j < 3; j += 3)
			count++;

	cout << count << endl;

	return 0;
}

