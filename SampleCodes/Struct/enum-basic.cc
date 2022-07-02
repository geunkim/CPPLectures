/*

	File: enum-basic.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>

using namespace std;

enum Mycard { Diamonds = 10, Hearts = 20, Clubs, Spades}; // unscoped enum

enum class Yourcard { Diamonds = 1, Hearts, Clubs, Spades}; // scpoed enum

int main(int argc, char const *argv[])
{

	int value; 
	int account_num;
	Yourcard realcard;  // scoped enum variable
	value = Spades;     // OK. unscpoed enum can be asspgi
	cout << "Mycard enum(Diamonds): " << Diamonds << endl;
	cout << "Mycard enum(Hearts): " << Hearts << endl;
	cout << "Mycard enum(Clubs): " << Clubs << endl; 
	cout << "value: " << value << endl;
	realcard = Yourcard::Clubs; 

	account_num = static_cast<int>(Yourcard::Hearts);
	cout << "Yourcard::Hearts: " << account_num << endl;

	return 0;
}