#include <iostream>

using namespace std;

int add(int x, int y){
	cout << __func__ << " (" << __LINE__  << ")"  << endl;
	return x + y;
}

short add(short x, short y){
	cout << __func__ << " (" << __LINE__  << ")"  << endl;	
	return x + y;
}

float add(float x, float y){
	cout << __func__ << " (" << __LINE__  << ")"  << endl;
	return x + y;
}

double add(double x, double y){
	cout << __func__ << " (" << __LINE__  << ")"  << endl;
	return x + y;
}

string add(string x, string y){
	cout << __func__ << " (" << __LINE__  << ")"  << endl;
	return x + y;
}

int main(int argc, char const *argv[])
{
	short a = 100;
	short b = 200;

	cout << add(a, b) << endl;
	cout << add(100, 200) << endl;

	cout << add(4.5, 6.4) << endl;
	cout << add(5.6f, 4.5f) << endl;

	cout << add("My name is ", "Hong Gil-Dong.") << endl;
	return 0;
}
