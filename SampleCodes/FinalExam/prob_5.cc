#include <iostream>
using namespace std;

class Person{
private:
	static int count;
public:
	Person() { count++; }
	~Person() { count--; }
	int getCount() { return count; }
};

int Person::count = 0; 

int main(int argc, char const *argv[])
{
	Person kim;
	cout << kim.getCount() << "; ";

	{
		Person cha, park;
		cout << cha.getCount() << "; ";
		cout << kim.getCount() << "; ";
	}
	Person park;
	cout << kim.getCount() << endl;

	return 0;
}

