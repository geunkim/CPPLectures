#include <iostream>
using namespace std;

void change(int *x, int *y) {
	int tmp = 20;
	tmp = *x;
	*x = *y;
	*y = tmp;
	cout << *x << ", " << *y << endl;
}

int main(int argc, char const *argv[])
{
	int v1 = 10;
	int v2 = 30;

	change(&v1, &v2);
	cout << v1 << ", " << v2 << endl;
	return 0;
}

