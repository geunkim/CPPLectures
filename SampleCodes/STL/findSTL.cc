#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> vec {"국어", "수학", "물리", "화학", "C++"};

	auto it = find(vec.begin(), vec.end(), "수학");

	return 0;
}