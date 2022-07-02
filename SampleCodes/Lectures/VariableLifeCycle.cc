#include <iostream>

// local variable (지역 변수)
// global variable (전역변수)

// static variable (정적 변수)
// extern variable (외부 변수)

using namespace std;

int increase();
int num = 0;

int main(int argc, char const *argv[])
{
	cout << increase() << endl;
	cout << increase() << endl;

	cout << num << endl;
	return 0;
}


