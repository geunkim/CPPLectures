/*
	File Name: arrayFor.cc
	Author: Geun-Hyung Kim

	Description: 
	범위 기반 for문을 이용한 배열의 원소 값 출력 프로그램
	Date: 2021. 3. 25
	Version: 0.1.0
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
 {
 	int score[] = {50, 40, 30};

 	for(auto data: score)
 		cout << data << endl;

 	return 0;
 } 