
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	auto sum = [](int x, int y) {return x + y;};

	cout << sum(1, 2) << endl;
	cout << sum(10, 20) << endl;

	return 0;
}