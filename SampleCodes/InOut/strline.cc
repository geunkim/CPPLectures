/*
	File: strline.cc
	Author: Geun-Hyung Kim
	Description:
	키보드로 입력된 문자 14개 또는 줄 바꿈 문자까지의 문자만을 입력받는 프로그램 
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char inbuf[100];     // 문자형 배열 선언 (저장공간 100개)

	cout << "문자열을 입력하시오: ";
	// 입력 버퍼에서 14 문자 또는 (\n)까지의 문자를 읽어와서 inbuf에 저장
	cin.getline(inbuf, 15, '\n'); 
	// strlen 함수를 사용하여 inbuf에 저장된 문자열의 길이를 구해 콘솔 화면에 출력 
	cout << "length of input string: " << strlen(inbuf) <<endl;
	// inbuf에 저장된 문자열 콘솔화면에 출력
	cout << "input data: " << inbuf << endl;

	return 0;
}