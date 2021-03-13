/*
	File: ioWrite.cc
	Author: Geun-Hyung Kim
	Description:
	"Hello World!" 문자열을 str 배열에 저장하고 배열에 저장된 데이터를 write 함수를 
	이용하여 콘솔화면에 출력하는 프로그램 
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[] = "Hello World!";  // "Hello World!" 문자열을 배열에 저장

	cout.write(str, strlen(str)); // 배열에 저장한 데이터를 cout.write 함수로 콘솔에 출력 
	cout.put('\n');               // 콘솔에 줄바꿈 문자를 출력 
	
	return 0;
}