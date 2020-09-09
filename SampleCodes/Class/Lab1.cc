/* 
	File name: Lab1.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

class Test{
	int x;
public:
	Test(int k) { x = k;}
	void setX(int a) { x = a;}
	int getX() {return x;}
};


int main(int argc, char const *argv[])
{
	Test t;
	t.setX(100);
	cout << t.getX() << endl;
	return 0;
}

