/*
	File: stringIn.cc
	Author: Geun-Hyung Kim
	Description:
	키보드로 부터 문자열을 입력받아 콘솔에 출력하는 프로그램 
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char arr[20];				// 문자형 배열 선언
	cout << "문자열을 입력하시오:";  
 	cin >> arr;                 // 키보드로 부터 문자열을 입력 받아 arr 배열 변수에 저장
 								// 키보드에서 return에 입력되면 다음 코드로 이동
	cout << arr << endl;        // arr 배열에 저장된 문자열과 줄바꿈 문자를 콘손에 출력

	return 0;
}