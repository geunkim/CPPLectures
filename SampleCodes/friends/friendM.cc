/*
  File: friendM.cc
  Description: The example of friend member function

  date: 2019. 10. 18
*/

#include <iostream>

using namespace std;

class Box;

class ShapeManager
{
public:
	bool equals(const Box& a, const Box& b);
};

class Box
{
	double width, height;
public:
	Box(double w = 1, double h = 1) : width(w), height(h) {}
	friend bool ShapeManager::equals(const Box& a, const Box& b);
};



bool ShapeManager::equals(const Box& a, const Box& b) {
	return (a.width == b.width) && (a.height == b.height);
}

int main(int argc, char const *argv[])
{
	Box a(10, 10), b(10, 5), c(10, 10);
	ShapeManager shape;

	cout << "Is Box a equal to Box b ? " << shape.equals(a, b) << endl;
	cout << "Is Box a equal to Box c ?  " << shape.equals(a, c) << endl;

	return 0;
}