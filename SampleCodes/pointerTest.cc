#include <iostream>
using namespace std;

void arrFun(int *arr, int len) {
	for(int i = 0; i < len; i++)
		cout << arr[i] << endl;  // *(arr + i)
}

int main(int argc, char const *argv[])
{
	// 정수형 일반변수 a 선언
	int a, e = 0;
	// 정수형 참조변수 b 선언 (변수는 메모리에 할당되지 않음)
	int &b = a;
	// 정수형 포인터 변수 c 선언 (주소값을 저장하기 위한 메모리 할당)
	int *c;
	// 배열변수
	int d[10] = {10, 20, 30, 40};
	a = 10;
	//&a; //주소연산자 (변수 a가 저장된 주소값을 반환)
	//*c; //역참조연산자 (c의 주소값에 저장된 데이터 값 반환)  


	int *f = new int[5];
	c = &a;
	cout << *c << endl;
	cout << *(f + 10) << endl;

	return 0;
}