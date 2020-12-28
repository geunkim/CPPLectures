#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> a;  // 메모리 크기...

	for(int i = 0; i < 5; i++)
		a.push_back(5-i);

	for(auto it = a.begin(); it != a.end(); it++)
		cout << *it << ",";
	cout << endl;

	sort(a.begin(), a.end());
		
	for(auto it = a.begin(); it != a.end(); it++)
		cout << *it << ",";
	cout << endl;

	auto ptr = find(a.begin(), a.end(), 10);

	if(ptr != a.end())
		cout << "ptr: " << *ptr << endl;

	a[3] = 5;

	cout << count(a.begin(), a.end(), 5) << endl;
	cout << count(a.begin(), a.end(), 7) << endl;

	return 0;
}