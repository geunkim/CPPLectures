#include <iostream>
#include <random>
#include <ctime>

using namespace std;

double minArray(double arr[], int len) {
	double min = arr[0];

	for(int i = 1; i < len; i++)
		if (arr[i] < min) min = arr[i];

	return min;
}

int main(int argc, char const *argv[])
{
	double num[10];

	srand((unsigned int)time(NULL));
	for(int i = 0; i < 10; i++)
		num[i] = rand() % 1000;

	for(auto d : num)
		cout << d << endl;

	cout << "min: " << minArray(num, 10) << endl;

	return 0;
}