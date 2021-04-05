// 
// File Name: basicRandom.cc
// Author: Geun-Hyung Kim
// Date: 2020. 4. 3
// 

#include <iostream>			
#include <ctime>		//time 함수를 위한 헤더 파일

using namespace std;	// 이름 공간 std를 사용하겠다는 명령문으로 std::cout를 std 를 명시하지 않고 cout 으로 사용 가능 

int main(int argc, char const *argv[])
{
	int num;
	srand((unsigned int)time(NULL));  	// rand() 함수의 seed 설정, 프로그램이 실행될 때 마다 time 값을 활용하여 seed 값 설정
	num = rand() % 200; 				//  rand()함수: 0 ~ RAND_MAX 의 값을 가짐, (0 <= num) && (num < 200)

	cout << "num: " << num << endl;
	//
	// 다음에 과제와 관련한 프로그램 코드를 추가하시오. 
	//

	return 0;
}
