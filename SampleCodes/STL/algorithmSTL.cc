
#include <iostream>
#include <vector>

using namespace std;

bool is_greater_than_3(int value) {
		return value > 3;
}

int main(int argc, char const *argv[])
{

	vector<int> a;  // 메모리 크기...


	for(int i = 0; i < 5; i++)
		a.push_back(5-i);


	auto count = count_if(a.begin(), a.end(), [](int x) {return x>2;});

	cout << count << endl;


	return 0;


}