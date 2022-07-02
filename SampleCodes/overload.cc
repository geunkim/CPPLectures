#include <iostream>

using namespace std;

int add(int, int);
int add(int, int, int);
double add(double, double);

int main(int argc, char const *argv[])
{
	int a = 10, b = 20;
	double c = 20.5, d = 31.1;

	cout << add (20.5, 40.6) << endl;
	cout << add (10 , 20 ,30) << endl;
	cout << add (40, 50) << endl;

	return 0;
}

int add(int a, int b) {
	cout << "int add " << endl;
	return a + b;
}

int add(int a, int b, int c){
	cout << "three int add" << endl;
	return a + b + c;
}

double add(double a, double b) {
	cout << "double add " << endl;
	return a + b; 
}







