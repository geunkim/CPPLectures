#include <iostream>
using namespace std;

class Functor{
public:
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

int main(int argc, char const *argv[])
{
	Functor f;
	int a = 5, b = 6;

	bool result = f(a, b);
	cout << "f(" << a <<", " << b <<"): " << result << endl;
	return 0;
}