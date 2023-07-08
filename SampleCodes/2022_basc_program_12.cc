#include <iostream>
using namespace std;

class Rect {
	int a, b;
public:
	Rect (int x, int y = 30) { a = x, b = y;}
	friend ostream& operator << (ostream& os, Rect& s){
		os << "a: " << s.a << ", " << "b: " << s.b << endl;
		return os;
	}
};

int main(int argc, char const *argv[])
{
	Rect a;
	Rect b(20);
	Rect c(10, 20);
	cout << b << endl;
	cout << c << endl;

	return 0;
}