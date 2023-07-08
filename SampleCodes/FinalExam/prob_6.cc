#include <iostream>
using namespace std;
 
 
 class Box {
 private:
 	int x, y, z;
 public:
 	Box(int a = 1, int b = 4, int c = 5) { x = a; y = b; z = c;}
 	int getVolume() { return x * y * z; }
};

int main(int argc, char const *argv[])
{
	Box A;
	Box B(3);
	Box C(3, 2);
	Box D(3, 2, 1);
	
	cout << A.getVolume() << "; ";
	cout << B.getVolume() << "; ";
	cout << C.getVolume() << "; ";
	cout << D.getVolume() << endl;

	return 0;
}

