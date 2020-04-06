
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{

	cout << "Result of AND operators" << endl;
	cout << "false && false: " << (false && false) << endl;
	cout << "false && true: " << (false && true) << endl;
	cout << "true && false: " << (true && false) << endl;
	cout << "true && true: " << (true && true) << endl;

	cout << "Result of OR operators" << endl;
	cout << "false || false : "  << (false || false) << endl;
	cout << "false || true: " << (false || true) << endl;
	cout << "true || false: " << (true || false) << endl;
	cout << "true || true: " << (true || true) << endl;

	cout << "Result of NOT operators" << endl;
	cout << "!false: " << !false << endl;
	cout << "!true: " << !true << endl;

	return 0;
}