#include <iostream>
using namespace std;

class Polygon{
protected:
	int width, height;
public:
	Polygon(int w, int h) : width(w), height(h) {}
	virtual int area () = 0;
};

class Rectangle : public Polygon {
public:
	Rectangle(int w, int h) : Polygon(w, h) {}
	int area() { return width * height;}
};

class Triangle : public Polygon {
public:
	Triangle(int w, int h) : Polygon (w, h) {}
	int area() { return width * height/2;}
};

int main(int argc, char const *argv[])
{
	
	Rectangle rec(4, 5);
	Triangle tri(4, 5);

	Polygon *poly1 = &tri;
	Polygon *poly2 = &rec;

	cout << poly1->area() << ", " << poly2->area() << endl;

	return 0;
}


