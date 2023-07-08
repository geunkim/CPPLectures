#include <iostream>
using namespace std;

class sClass {
	static int count;
public:
	sClass() { count++;}
	~sClass() {--count;}
	int numObject() { return count;}
};

int sClass::count = 0;

int main(int argc, char const *argv[])
{
	
	sClass *a = new sClass();
	sClass *b = new sClass();
	{
		sClass c;
		cout << a->numObject() << ", ";
	}
	delete b;

	sClass d;
	cout << a->numObject() << endl;
	delete a;

	return 0;
}

