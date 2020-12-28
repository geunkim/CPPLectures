/*

	File Name: unaryOperators.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

class Distance{
	int feet;   // 0 to infinite
	int inches; //0 to 12
public:
	Distance(int f = 0, int i = 0): feet(f), inches(i) {}
	void displayDistance() {
		cout << "F: " << feet << ", I: " << inches << endl;
	}
	Distance operator - () {
		return Distance(-feet, -inches);
	}
};

int main(int argc, char const *argv[])
{
	Distance D1(11, 10), D2(-5, 11);
	Distance T;
	T = -D1;
	D1.displayDistance();
	T.displayDistance();

	T = -D2;
	D2.displayDistance();
	T.displayDistance();
	return 0;
}

