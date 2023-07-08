#include <iostream>
using namespace std;

bool tf() {
	cout << "true" << endl;
	return true;
}

bool ff() {
	cout << "false" << endl;
	return false;
}

int main(int argc, char const *argv[])
{
	if(tf() || ff()) { cout << "--(1)--" << endl; } cout << "main (1)" << endl;

	if(ff() && tf()) { cout << "--(2)--" << endl; } cout << "main (2)" << endl;

	if(ff() || tf()) { cout << "--(3)--" << endl; }	cout << "main (3)" << endl;

	if(tf() && ff()) { cout << "--(4)--" << endl; } cout << "main (4)" << endl;

	if(!tf() && ff() && tf()) { cout << "--(5)--" << endl;} cout << "main (5)" << endl;

	if(!tf() || ff() || tf()) { cout << "--(6)--" << endl;} cout << "main (5)" << endl;

	return 0;
}