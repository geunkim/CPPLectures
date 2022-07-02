/*
	File: pointer_array.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *ptr = arr;

	cout << "배열 arr의 첫 번째 원소의 값(*ptr): " << *ptr << endl;
	ptr++;	// 포인터 변수 값(주소 값) 증가
	cout << "배열 arr의 두 번째 원소의 값(*ptr): " << *ptr << endl;
	(*ptr)++; // 포인터 변수에 저장된 값의 증가 
	cout << "배열 arr의 두 번째 원소의 값(*ptr): " << *ptr << endl;
	// 포인터 변수에 저장된 값 증가를 한 후 역참조 연산자로 메모리에 저장된 값 참조 출력 
	cout << "배열 arr의 세 번째 원소의 값(*ptr): " << *++ptr << endl;
	// 세 번째 원소의 값 참조한 후 포언터 변수에 저장된 값 증가 (다음 원소의 주소 저장)
	cout << "배열 arr의 세 번째 원소의 값(*ptr): " << *ptr++ << endl; 
	cout << "배열 arr의 네 번째 원소의 값(*ptr): " << *ptr << endl;

	return 0;
}
