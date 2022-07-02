#include <iostream>

//using namespace std;

int count = 0;  // std::__1::count 가 존재

int increase() {
	return ++count;  
}

using namespace std;

int main(int argc, char const *argv[])
{
	cout << increase() << endl;
	cout << increase() << endl;	
	return 0;
}