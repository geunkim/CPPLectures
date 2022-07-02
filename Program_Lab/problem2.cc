#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0;
	while(count == 10) {
		count++;
		cout << count << ": " << "Hello World!" << endl;
	}

	cout << count << endl;
	return 0;
}