#include "common.h"
#include <iostream>
#include <random>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[ELEMENTS];

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(MIN, MAX);


	for(int i = 0; i < ELEMENTS; i++) data[i]= dis(gen);
	for(int i = 0; i < ELEMENTS; i++) cout << data[i] << ", ";
	cout << endl;


	// cout << "배열의 최소 값: " << find_min(data) << endl;
	// cout << "배열의 최대 값: " << find_max(data) << endl;


	int x = 10, y = 20;

	cout << min(x, y) << endl;
	cout << max(x, y) << endl;

	return 0;
}