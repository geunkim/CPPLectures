# 변수의 유효범위와 생명주기

데이터 값을 저장하기 위한 변수는 선언을 통해 저장 공간을 할당받고 할당된 저장 공간에 필요에 따른 데이터 값를 저장하거나 데이터 값을 참조한 후 할당된 저장 공간을 운영체제에 반환하여
다른 변수에 해당하는 데이터를 저장하기 위해서 할당되어 사용된다. 
데이터를 저장하기 위한 저장 공간의 할당(변수 선언)시점에서 부터 저장 공간의 할당 해지로 변수를 더 이상 사용할 수 없는 시점까지를 변수의 생명주기(Life Cycle)이라 한다.
또한 변수의 이름(저장 공간)이 유효한 코드의 범위를 변수의 범위(scope)라고 한다. 
프로그램 내에서 동일한 변수의 이름이 존재하여도 변수의 범위(변수가 선언된 블록)가 다르면 접근하는 저장 공간이 달라진다.

```c++
#include <iostream>
using namespace std;

void func();

int value = 5;               // scope 0

int main(int argc, char const *argv[])
{
	int value = 10;  		 // scope 1-0

	{
		int value = 20;  	 // scope 2

		{ 
			int value = 30;  // scope 3
			
			cout << "(scope 3) value: " << value << ", 주소: " << &value << endl;
			cout << "(scope 0) value: " << ::value << ", 주소: " << &(::value) << endl;
		}
		cout << "(scope 2) value: " << value << ", 주소: " << &value << endl;
	}

	int value1 = 40;  // scope 1-1

	cout << "(scope 1-1) value1: " << value1 << ", 주소: " << &value1 << endl;
	::value = 50; 
	func();
	cout << "(scope 1-0) value: " << value << ", 주소: " << &value << endl;

	return 0;
}

void func() {
	cout << "in func(scope 0): " << value << ", 주소: " << &value << endl;
}
