#include <iostream>
using namespace std;

class Obj {
	int x, y, z;
public:
	Obj(){}
	Obj(int a, int b, int c) : x(a), y(b), z(c) {}
	friend ostream& operator << (ostream& os, const Obj& o) {
		os << "(" << o.x << ", " << o.y << ", " << o.z << ")";
		return os;
	}
	void printAddr(){
		cout << "x_addr(" << &x << "), ";
		cout << "y addr(" << &y << "), ";
		cout << "z addr(" << &z << ")" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Obj x(1, 2, 3), z(10, 20, 30);

	cout << "x: " << x << endl;
	cout << "객체 x의 각 멤버 변수의 주소: ";
	x.printAddr();
	cout << "z: " << z << endl;
	cout << "객체 z의 각 멤버 변수의 주소: ";
	z.printAddr();

	z = x;
	cout << endl;
    cout <<"대입 연산 후 z의 값: ";
	cout << "z: " << z << endl;
	cout << "대입 연산 후 객체 z의 각 멤버 변수의 주소: ";
	z.printAddr();


	return 0;
}