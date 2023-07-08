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
	if(tf() || ff()) { cout << "--first--" << endl; }

	if(ff() && tf()) { cout << "--second--" << endl; } 

	if(ff() || tf()) { cout << "--third--" << endl; }	

	if(tf() && ff()) { cout << "--fourth--" << endl; }

	return 0;
}