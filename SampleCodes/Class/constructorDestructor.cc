/*
	File name: constructorDestructor.cc
	Author: Geun-Hyung Kim
*/

// 생성자와 소멸자의 호출 순서 확인하기 

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int xp = 0, int yp = 0) : x(xp), y(yp) { 
		cout << "Point Constructor" << endl;
	}
	~Point(){
		cout << "Point Destructor" << endl;
	}
	void show(){
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

Point p;
int main(int argc, char const *argv[])
{
	cout << "main start" << endl;
	Point p;
	cout << "main end" << endl;
	return 0;
}


