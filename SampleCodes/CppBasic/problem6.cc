/*

	File: problem6.cc
	Author: Geun-Hyung Kim

*/

#include <iostream>

using namespace std;

namespace manager {
	int value = 300;
}

namespace player {
	int value = 200;
}


int main(int argc, char const *argv[])
{

	cout << manager::value << endl;
	cout << player::value << endl;

	return 0;
}