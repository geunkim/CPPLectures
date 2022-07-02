#include <iostream>
using namespace std;

int num = 10;

int main(int argc, char const *argv[])
{
	int num = 40;

	cout << num << endl;	// 지역변수 num 출력
	cout << ::num << endl;  // 전역변수 num 출력

	return 0;
}