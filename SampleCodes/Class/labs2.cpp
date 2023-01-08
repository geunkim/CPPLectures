#include <iostream>

using namespace std;

class Man
{
	string name;
	int age;
public:
	Man(string name, int age) {
		this->name = name;
		this->age = age;
	}

	string older(Man a, Man b)
	{
		return a.age > b.age ? a.name : b.name;
	}
};

int main(int argc, const char* argv[])
{
	Man a("A", 20);
	Man b("B", 10);

	cout << a.older(a, b) << " is older" << endl;
		 
	return 0;
}