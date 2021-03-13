/* 
	File: putConcate.cc
	Author: Geun-Hyung Kim
	Description:
	put 함수의 결과에 새로운 put 함수를 연속해서 호출하는 프로그램 
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout.put('A').put('B').put('C').put('D').put('\n');
	return 0;
}