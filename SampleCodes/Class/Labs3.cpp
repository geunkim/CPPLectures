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
	string getName() { return name; }
	int getAge() { return age; }
};

int main(int argc, const char* argv[])
{
	Man person[3] = { {"A", 10}, {"B", 20}, {"C", 30} };

	for (int i = 0; i < 3; i++) {
		cout << person[i].getAge() << endl;
	}

	return 0;
}
