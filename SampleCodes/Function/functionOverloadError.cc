/*
	File name: functionOverloadError.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

int sum(int a, int b){
	return a + b;
}

double sum(int a, int b){
	return (double)(a + b);
}

int main(int argc, char const *argv[])
{
	cout << add(10, 20) << endl;
	return 0;
}

