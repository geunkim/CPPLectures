/*
	File Name: functionOverloading.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

int add(int a, int b);
double add(double a, double b);

int main(int argc, char const *argv[])
{
	cout << add(10, 20) << endl;      // int add(int a, int b) 호출
	cout << add(5.3, 20.6) << endl;   // double add(double a, double b) 호출
	//cout << add(10, 15.7) << endl;  // error: call to 'add' is ambigious
	return 0;
}

int add(int a, int b){
	cout << "int add()" << endl;
	return a + b;
}

double add(double a, double b) {
	cout << "double add()" << endl;
	return a + b;
}