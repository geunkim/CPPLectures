#include <iostream>
using namespace std;

#define DEBUG 1
#define DEBUG1 1

int main(int argc, char const *argv[])
{
	
	string str1 = "Normal";
	string str2 = "Error";
	string str3 = "Exception";

	#if DEBUG
	cout << str2 << endl;
	#elif DEBUG
	cout << str1 << endl;
	#else
	cout << str3 << endl;
	#endif

	return 0;
}