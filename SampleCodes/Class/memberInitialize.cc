/*
	File name: memberInitialize.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int xp = 0, int yp = 0) : x(xp), y(yp) {}
	void show(){
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

class Line {
	Point startP, endP;
public:
	Line(int sX, int sY, int eX, int eY) : startP(sX, sY), endP(eX, eY){}
	void show() {
		cout << "startPoint: ";
		startP.show();
		cout << "endPoint: ";
		endP.show();
	}
};

int main(int argc, char const *argv[])
{
	Point p1;
	Point p2(10, 20);
	Line ln(10, 10, 30, 30);

	p1.show();
	p2.show();
	ln.show();
	return 0;
}



