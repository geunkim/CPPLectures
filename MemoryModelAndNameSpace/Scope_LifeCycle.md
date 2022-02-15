# 변수의 유효범위와 생명주기

데이터 값을 저장하기 위한 변수는 선언을 통해 저장 공간을 할당받고 할당된 저장 공간에 필요에 따른 데이터 값를 저장하거나 데이터 값을 참조한 후 할당된 저장 공간을 운영체제에 반환하여
다른 변수에 해당하는 데이터를 저장하기 위해서 할당되어 사용된다. 
데이터를 저장하기 위한 저장 공간의 할당(변수 선언)시점에서 부터 저장 공간의 할당 해지로 변수를 더 이상 사용할 수 없는 시점까지를 변수의 생명주기(Life Cycle)이라 한다.
또한 변수의 이름(저장 공간)이 유효한 코드의 범위를 변수의 범위(scope)라고 한다. 
프로그램 내에서 동일한 변수의 이름이 존재하여도 변수의 범위(변수가 선언된 블록)가 다르면 접근하는 저장 공간이 달라진다.
C++ 프로그램 코드에서 코드의 범위는 ```중괄호({})```로 구분이 된다. 그러므로 동일한 중괄호 범위 안에서는 동일한 이름의 변수가 두 번 선언될 수 없으나 새로운 중괄호 안에서는 같은 이름의 변수가 선언될 수 있다. 

다음 프로그램 코드는 ```main 함수``` 블록 내에 중첩(중괄호 안에 중괄호가 존제하는 형태)된 중괄호가 두 개 존재하고 ```func 함수```블록이 존재한다. 
```main 함수```와 ```func 함수``` 블록 외부에 ```value``` 변수가 선언되어 있으며 ```main 함수```블록에는 변수 ```value```와 ```value1```이 선언되어 있으며 
```main 함수``` 내부의 중첩된 각 블록에도 ```value```라는 변수가 선언되어 있다.

새로운 블록 내에서 외부 블록의 변수와 동일한 이름의 변수가 선언되면 새로운 저장 공간이 할당된다. 
(scope 1-0), (scope 1-1)의 변수는 ```main함수``` 블록의 변수이다. 
이 중 ```value1```은 ```main 함수``` 내부의 중첩된 블록 내에서 새롭게 선언되지 않아 블록 내에서 변수 value1의 저장 공간을 접근할 수 있다.  



```c++
#include <iostream>
using namespace std;

void func();

int value = 5;               // scope 0

int main(int argc, char const *argv[])
{
	int value = 10;  		 // scope 1-0
	int value1 = 40;  		// scope 1-1

	{
		int value = 20;  	 // scope 2	
		{ 
			int value = 30;  // scope 3

			cout << "(scope 3) value: " << value << ", 주소: " << &value << endl;
			cout << "(scope 1-1) value1: " << value1 << ", 주소: " << &value1 << endl;
			cout << "(scope 0) value: " << ::value << ", 주소: " << &(::value) << endl;
			value1 = 60;
		}
		cout << "(scope 2) value: " << value << ", 주소: " << &value << endl;
	}

	cout << "(scope 1-1) value1: " << value1 << ", 주소: " << &value1 << endl;
	::value = 50; 
	func();
	cout << "(scope 1-0) value: " << value << ", 주소: " << &value << endl;

	return 0;
}

void func() {

	cout << "in func(scope 0): " << value << ", 주소: " << &value << endl;
}
```

