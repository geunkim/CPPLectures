/*
	File name: prob_3.cpp
	Author: Geun-Hyung kim
*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string word;
	set<string> words;
	int count = 0;   // 단어의 크가
	

	cout << "단어를 입력하시오('q' 입력할 때 까지): " << endl;

	do {
		cin >> word;
		// set 에 단어 저장 
	}while(word != "q"); 


	// for_each와 단어의 길이가 4 이상인 단어의 개수를 계산하는 lambda 함수를 정의해서 
	// 단어의 개수가 4 이상의 개수를 count에 저장

	
	cout << count << endl; // 입력한 단어 중 길이가 4 이상인 단어의 개수 출력 

	return 0;
}