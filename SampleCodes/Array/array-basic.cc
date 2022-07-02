/*
	File: array-basec.cc
	Author: Geun-Hyung Kim

	Description: 
	정수를 저장할 저장 공간 5개를 일반 변수와 배열 변수를 이용하여 할당하고 
	저장 공간의 값을 초기화한 후 화면에 출력해보는 프로그램  
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int score_0 = 10, score_1 = 20, score_2 = 30, score_3 = 40, score_4 = 50; //정수형 일반변수로 저장장소 5개 할당 

	int score[5] = {10, 20, 30, 40, 50};  //정수형 배열변수로 저장장소 5개 할당 

	cout << score_0 << ", " << score_1 << ", " << score_2 << ", " << score_3 <<", "<< score_4 << endl;
	cout << "-- 배열에 저장된 값을 인덱스(index)를 이용하여 접근하여 출력하는 방법 --" << endl;
	cout << score[0] << ", " << score[1] << ", " << score[2] << ", " << score[3] <<", "<< score[4] << endl;

	// 반복문을 이용한 배열의 저장된 값 출력 
	for(int i = 0; i < 5; i++)
		cout << score[i] << endl;  // index i의 값을 변경하면서 출력

	return 0;
}