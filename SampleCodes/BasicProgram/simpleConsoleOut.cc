/*
  File name: simpleConsoleOut.cc
  Author: Geun-Hyung Kim
  Description:
  콘솔 화면에 Hello World! 문자열을 출력하는 프로그램 
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Hello World!" << endl; // 콘솔 화면에 문자열 출력
									// 문자열을 쌍 따움표(" ") 안에 표현
	cout << 'Q' << endl;			// 콘솔 화면에 문자(영문 알파벳: 1바이트로 표현) 출력 
									// 문자는 따움표(' ') 안에 문자 하나 표현
	cout << "ㄱ" << endl;            // 한글은 코드가 2바이트로 표현되어 문자열로 고러  

	return 0;
}