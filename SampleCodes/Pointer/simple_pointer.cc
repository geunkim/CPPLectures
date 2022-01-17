/*

	File: simple_pointer.cc
	Author: Geun-Hyung Kim

	Description: 
	  (1) 일반 변수 선언 및 데이터 값으로 초기화
	  (2) 포인터 변수 선언 및 NULL 값으로 초기화 
	  (3) a의 메모리 주소를 포인터 변수 ptr 에 저장
	  (4) ptr을 이용하여 메모리 공간에 데이터 값 대입

      정수형 데이터를 저장할 수 있는 저장공간 한 개 할당 후 
      할당된 저장 공간을 포인터 변수를 활용하여 저장된 데이터 값을 조작 또는 참조하는 프로그램 
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a = 10;        // (1) 일반 변수 선언 및 데이터 값으로 초기화
	int *ptr = NULL;   // (2) 포인터 변수 선언 및 NULL 값으로 초기화 

	// 변수 a를 위해 할당된 메모리 공간의 시작 주소 출력
	cout << "변수 a를 위해 할당된 메모리 주소: " << &a << endl; 
	
	ptr = &a;          // (3) a의 메모리 주소를 포인터 변수 ptr 에 저장

	// 변수 ptr에 저장된 주소 값에 저장된 데이터 값 출력 
	cout << "ptr 이 가리키는 곳에 저장된 데이터 값(*ptr): " << *ptr << endl; 
	cout << "변수 a에 저장된 값: " << a << endl;

	*ptr = 30;         // (4) ptr을 이용하여 메모리 공간에 데이터 값 대입

	// ptr에 저장된 주소 갑 확인
	cout << "ptr에 저장된 주소 겂(ptr): " << ptr << endl;

	// 변수 a에 저장된 값 확인 
	cout << "ptr을 이용한 데이터 값 조작 후 변수 a의 값(a): " << a << endl;

	return 0;
}