/*
	File name: prob_2.cpp
	Author: Geun-Hyung kim
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> scores;
	double score; 

	cout << "실수를 입력하시오. (음수가 입력되면 입력을 중지)" << endl;
	cout << "100.0 보다 큰 점수가 입력되면 다시 입력 받음" << endl;
	
	do {
		cin >> score;
		if(score > 100) { cout << "다시 입력하시요" << endl; continue; }
		if(score >= 0) cout << "data:" << score << endl;
	}while(score >= 0);

	return 0;
}

