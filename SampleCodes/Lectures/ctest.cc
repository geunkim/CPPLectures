#include <iostream>
using namespace std;




int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 20;

	// 산술 연산 
	
	// +, -, *, /, %
	
	int c = 0;

	c = a + b;

	// double f = (double)a / b;
	// cout << c << endl;
	// cout << a + b << endl;
	// cout << a - b << endl;
	// cout <<  a * b << endl;
	// cout << f << endl; 
	// cout <<  a / (double)b << endl;
	// cout << a % 3 << endl;
	// cout << b % 7 << endl;

	// 관계 연산
	// <, <=, >, >=, ==, !=
	// 
	
	// cout << (a < b) << endl;
	// cout << (a > b) << endl; 
	// cout << (a != b) << endl; 
	// cout << (a == b) << endl;

	// 논리 연산 (AND, OR, NOT)
	// &&, |\, !

	// cout << ((a < b) || (a > b)) << endl;
	// cout << !(a == b) << endl;
	// cout << (a == 20 && b == 20) << endl;


	// 비트 연산 
	// 논리 &, |, ~
	// 이동연산자
	
	short e = 15;
	short d = 6;

	cout << (e & d) << endl;
	cout << (e | d) << endl;

	char h = 127;

	cout << ~h << endl;  // 1의 보수, Q) 컴퓨터에서 음수를 어떻게 표현할까? 

	return 0;
}