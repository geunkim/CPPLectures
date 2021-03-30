#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;
	for( ; i < 10; i++) {
		if(i == 5 || i == 8) continue;
		cout <<"i: " << i << endl;
	}

	cout << "after i: " << i << endl;
	return 0;
}
