/*
	File name: pointTest.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

class Point{
	int x, y;
public:
	Point(int x = 10, int y = 10);
	void show();
};

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::show(){
	cout << "x: " << x << ", " << "y: " << y << endl;
}

int main(int argc, char const *argv[])
{
	return 0;
}