/*
	File: ioPut.cc
	Author: Geun-Hyung Kim
	Description:
	ASCII 코드 값 65에서 69까지 해당되는 문자를 출력하느 프로그램
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0; 			 //정수형 변수 i 선언과 0 으로 초가화

	while(i < 5){        // i의 값이 5보다 작으면 중괄호 내 코드 수행         
		cout.put(65+i);  // 65+i  값이 해당하는 문자를 콘솔화면에 출력
		i++;             // i를 1 증가
	}
	cout.put('\n');      // 줄 바꿈 문자 출력 

	return 0;
}