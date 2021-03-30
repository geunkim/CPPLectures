/*

	File Name: breakIteration.cc
	Author: Geun-Hyung Kim
	Description:
	반복문에서 break의 사용 예 

	Date: 2021. 3. 30
	Version: 0. 1. 0
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;
	for( ; i < 10; i++) {
		cout <<"i: " << i << endl;
		if(i == 5) break;
	}

	cout << "after i: " << i << endl;
	return 0;
}
