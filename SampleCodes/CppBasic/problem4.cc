/*
	File: problem4.cc
	Author: Geun-Hyung Kim


	Purpose: To test namespace

*/
#include <iostream>
#include <string>

using namespace std;
//

namespace my {
	void echo(string message) { cout << "My message: " << message << endl; }
}

namespace your {
	void echo(string message) { cout << "Your message: " << message << endl;}
}

int main(int argc, char const *argv[])
{
	
	// "My message: Hello" 가 화면에 출력되도록 함수 호출

	// "Your message: World" 가 출력되도록 함수 호출


	return 0;
}