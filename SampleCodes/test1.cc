#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int a, b, r = 0;

	cin >> a >> b;
	cout << a << ", " << b <<endl;

	while(1) {
		if (a > b) {
			r = a % b;
			a = b;
			b = r;
			if(r==0) break;
		}
	}
	cout << r << endl;
	
}