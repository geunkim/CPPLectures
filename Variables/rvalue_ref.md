# rvalue reference (rvalue 참조)

rvalue 참조는 이동 의미(move semantics)과 완벽한 포워딩(perfect forwarding)의 구현을 지원한다.

## 이동 의미

rvalue 참조는 애플리케이션의 성능을 크게 향상시킬 수 있는 이동 의미 체계의 구현을 지원한다. 
이동 의미론을 사용하면 (동적으로 할당한 메모리와 같은) 자원을 한 객체에서 다른 객체로 전달하는 코드를 작성할 수 있다.
이동 의미론은 프로그램의 다른 곳에서는 참조할 수 없는 임시 객체에서 자원을 전송할 수 있기 때문에 작동한다. 

이동 의미론을 구현하려면 일반적으로 이동 생성자(move constructor)를 제공하고 선택적으로 이동 할당 연산자(**operator=**)를 클래스에 제공한다.
복사 및 대입 오퍼레이션의 소스가 rvalue이면 자동으로 이동 의미롤 활용한다. 기본 복사 생성자와 달리 컴파일러는 기본 이동 생성자를 제공하지 않는다.
이동 의미론을 활용하기 위해서 일반 함수와 연산자를 오버로드할 수 있다. 예를 들어 ```string``` 클래스는 이동 의미론을 사용하는 오퍼레이션을 구현한다.
여러 문자열을 연결하고 결과를 출력하는 예를 살펴보자.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = string("H") + "E" + string("LL") + "O" + "!";
	cout << s << endl;
	return 0;
}
```
실행 결과는 다음과 같다.

```bash
HELLO!
```

```c++11```이전에는 각 ```operator+``` 호출은 새로운 임시 ```string```객체(rvalue)를 할당하고 반환한다. 
소스 문자열이 lvalue인지 rvalue인지 알 수 없기 때문에 ```operator+```는 한 문자열을 다른 문자열에 추가할 수 없다. 
소스 문자열이 둘 다 lvalue인 경우 프로그램의 다른 곳에서 참조할 수 있기 때문에 수정하면 안된다.
rvalue 참조를 사용하면 프로그램의 다른 곳에서 참조할 수 없는 rvalue를 사용하도록 ```operator+```를 수정할 수 있다.
이 변경으로 ```operator+``는 한 문자열을 다른 문자열로 추가할 수 있다. 
이 변경은 ```string```클래스가 수행해야 할 동적 메모리 할당의 수를 현저하게 줄인다. 

## 완벽한 포워딩(Perfect Forwarding)

완벽한 포워딩은 오버로드된 함수의 필요성을 줄이고 포워딩 문제를 방지하는데 도움이 된다. 
참조를 파러미터로 사용하는 제네릭 함수(generic function)을 작성할 때 포워딩 문제(forwarding problem)가 발생할 수 있다. 
예를 들어 ```const T&``` 타입의 파러미터를 사용하는 경우와 같이 이러한 파러미터들을 다른 함수에 전달 또는 포워딩하면, 호출된 함수는 해당 파러미터의 값을 수정할 수 없디. 
제네릭 함수가 ```T&```자료형의 파러미터를 사용하는 경우 임시 객체 또는 정수 리터럴과 같은 rvalue를 사용하여 함수를 호출할 수 없다. 

일반적으로 이 문제를 해결하기 위해서 각 파러미터로 ```T&```, ```const T&```를 모두 사용하는 일반 함수의 오버로드된 버전을 제공해야만 한다. 
결과적으로 오버로드된 함수의 수는 파러미터 수에 따라 지수적으로 증기한다. rvalue 참조를 사용하면 임의의 인수를 허용하는 함수 한 버전을 작성할 수 있다.
그러면 해당함수는 다른 함수가 직접 호출되는 것 처럼 해당함수를 다른 함수로 포워드 할 수 있다. 

```W```, ```X```, ```Y``` 및 ```Z```의 네 가지 자료형을 선언하는 예를 살펴보자. 
각 자료형의 생성자는 ```const```와 ```const```가 아닌 rvalue 참조의 다른 조합을 파러미터로 사용한다. 

```c++
{
   W(int&, int&) { cout << "W constructor" << endl; }
};

struct X
{
   X(const int&, int&) { cout << "X constructor" << endl; }
};

struct Y
{
   Y(int&, const int&) { cout << "Y constructor" << endl; }
};

struct Z
{
   Z(const int, const int&) { cout << "Z constructor" << endl; }
};

int main(int argc, char const *argv[])
{
	int i = 10, j = 20;

	W w(i, j);
	X x(i, j);
	Y y(i, j);
	Z z(i, j);

	return 0;
}
```

프로그램 실행의 결과는 다음과 같다. 

```bash
W constructor
X constructor
Y constructor
Z constructor
```






