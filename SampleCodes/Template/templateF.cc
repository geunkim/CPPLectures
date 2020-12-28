#include <iostream>

using namespace std;

template <typename T>
T add(T& x, T& y) {
	return x + y;
}

template <typename T>
T mMax(T& x, T& y) {
	return x > y ? x : y;
}

int main(int argc, char const *argv[])
{
	int a = 2, b = 4;
	double c = 3.4, d = 5.4;
	cout << add(a, b) << endl;
	cout << add(c, d) << endl;

	cout << mMax(a, b) << endl;
	cout << mMax(c, d) << endl;

	return 0;
}