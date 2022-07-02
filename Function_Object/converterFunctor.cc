#include <iostream>
using namespace std;

class converter{
	double exchange_rate;

public:
	converter(double ex) : exchange_rate(ex) {}

	double operator()(double amt) {
		return amt * exchange_rate;
	}
};

int main(int argc, char const *argv[])
{
	converter dollarToWon(1182);
	double won = dollarToWon(100);   // dollar to won converter

	cout << "won: " << won << endl;
}