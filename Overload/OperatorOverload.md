# Operator overloading (연산자 중복)

연산자는 의미를 간결하게 전달할 수 있는 편리한 기호이다. 일반적으로 연산자 기호를 사용하는 것이 함수로 정의하는 것 보다 이해하기 쉽다. 

연산자 오버로드는 개발자가 연산자의 의미를 객체애 대해서 다시 정의할 수 있는 기능이다. 연산자 오버로드는 operator 키워드를 사용한다. operator 키워드는 클래스의 객체의 연산자를 적용했을 때 연산자 심볼의 기능을 규정하는 함수이다.
연산자 오버로드는 연산자에 하나 이상의 의미를 갖도록 하거나 기존 성의된 연산 기능을 중복 정의한다. 컴파일러는 피 연산자의 자료형을 조사하여
연산자의 동작의 차이를 구별한다.

### 연산자 오버로딩의 잠재적 문제점

#### 구문 (Syntax)
```C++
자료형 operator operator_symbol (parameter-list)
```
대부분의 내장 연산자의 함수를 전역적으로 또는 클래스 별로 재 정의할 수 있다. 오버로드된 연산자는 함수로 구현된다. 오버로드된 연산자의
함수가 "operator X" 이면 X가 연산자이다. 예로 더하기 연산자를 오버로드하기 위해 정의된 함수는 "operator +" 이다. 빼기 연산의
오버로드 함수는 "operator-" 이다. 

다음은 오버로드할 수  없는 연산지이다.

| 연산자 | 이름 |
|---|---|
| . | 멈버 선택|
| .* | 멤버 포인터 선택|
| :: | 범위 지정 |
| ?: | 삼항 조건 |
| # | 문자열로 전처리기 변환 |
| ## | 전처리기 연결 |

* 오버로딩한 연산자는 non-static 클래스 멤버함수 또는 전역 함수이다. (private 또는 protected 접근자의 전역함수는 해당
클래스의 friend 함수로 선언되어야 한다

* 멤버함수로 오버로딩된 이항 연산자의 경우 연산자 사용 시 첫번째 피연산자는 항상 연산자가 호출되는 객체이다.
예로
```C++
T T::operator+(T& s);
```
의 연산자 오버로딩이 선언/정의되어 있을 경우, 이 연산자를 다음과 같이 사용할 수 있다.
``` T a, b, c; ```
```...```
``` c = a + b; ```

**이 때 a 객체의 속성 값은 선언하는 클래스의 멤버 변수가 된다. 즉 a 객체는 ```opeator+```를 
멤버함수로 제공하는 객체에 해당하고 b 객체는 ```opeator +``` 함수의 입력파러미터 s에 해당한다.** 

##### 연산자 오버로딩의 종류
연산자 오버로딩은 잠재적인 문제가 있으나 잘 사용하면 코드가 깔끔해진다. 연산자 오버로딩의 특징은 다음과 같다.

* 기본적으로 연산자에 대해 이미 정의된 피연산자의 수는 변경할 수 없다.
* 대부분의 연산자는 멤버함수와 일반함수로 모두 구현 가능하나 이항 연산자는 왼쪽 피연산자가 속한 클래스의 
멤버함수로만 구현이 가능하다. 
* 다음 연산자들은 멤버 함수로만 중복할 수 있다. 
  * 대입 연산자: =
  * 함수 호출 연산자: ( )
  * 배열 원소 참소 연산자: []
  * 포인터에서 멤버를 참조하는 연산자: ->
* 연산자의 우선순위와 결합 방향은 변경이 없다. 
* 연산자 오버로딩은 클래스의 객체가 포함한 연산에 대해서만 가능하다. 

| 연산자 종류 | 연산 |구문 예| 비고 |
|----|----|-----|----|
| 단향연산자 | - | T operator-() |  음수 | 
| 이항연산자 | + , - , \*, / | T operator+(const T& c); |  |
| 이항연산자 | ==, !=  | bool operator==(const T& c); |  |
| 이항연산자 | = | T& operator=(const T& c); |  |
| 이항연산자 | += | T& operator+=(const T& c); |
| 이항연산자 | [] | T& operator[](int i); |
|  | << | friend ostream& operator <<(ostream& os, const T& c); |
|  | >> | friend istream&  operator>>(istream& in, T& c); |
| 단항연산자 | 전위 연산자++ | T& operator++(); |
| 단항연산자 | 후위 연산자++ | const T operator++(int i); |
| 단항연산자 | 역참조 연산자 * |                      |

#### 연산자 오버로딩의 특징
* C++ 언어에 있던 연산자만 중복 가능하다. 
연산자 중복은 C++ 언어에 원래 있던 연산자에 대해서만 새로운 연산이 추가될 뿐 새로운 연산자를 만들어 낼 수 없다.

* 피연산자의 타입이 다른 연산을 새롭게 정의한다.
예로 C++에서 사칙연산(+, -, \*, /) 의 피연산자는 모두 숫자이다. 이들 연산을 중복하려면 피연산자가 숫자가 아니라 
<객체, 수>, <수, 객체>, <객체, 객체>의 형태를 되어야 한다. 

* 연산자 중복은 함수를 통해 이루어진다.
새로운 연산 처리를 수행하는 함수를 구현하는 것이다. 이 함수를 연산자 함수(operator function)라 한다. 

* 연산자 중복은 반드시 클래스와 관계를 가진다.
중복된 연산자는 반드시 피 연산자에 객체를 동반한다. 그러므로 연산자 함수는 클래스 멤버함수로 구현하든지 아니면 전역 함수로
구현하고 클래스에 프렌드 함수로 선언한다.

* 연산자 중복으로 피연산자의 개수를 바꿀 수 없다.
* 연산자 중복으로 연산의 우선순위를 바꿀 수 없다. 
* 모든 연산자가 중복가능한 것은 아니다. 

#### 연산자 중복을 위한 연산자 함수 선언
연산자 중복은 연산자 함수를 통해 구현되며 연산자 함수는 다음의 2가지 방법으로 작성가능하다. 

* 외부 함수로 구현하고 클래스의 프렌드 함수로 선언
사칙연산과 비교연산자 함수는 외부 전역 함수로 선언하고 두 개의 피 연산자를 모두 매개 변수로 전달할 수 있다. 
다음은 프렌드 함수를 이용하여 ```Rect``` 클래스의 ```equals```함수를 프렌드 함수로 구현한 것이다. 
```C++
#include <iostream>

using namespace std;
class Rect;
bool operator == (const Rect& a, const Rect& b);

class Rect
{
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	friend bool operator == (const Rect& a, const Rect& b);
};

bool operator == (const Rect& a, const Rect& b) {
 	return ((a.width == b.width) && (a.height == b.height));
}

int main(int argc, char const *argv[])
{
	Rect a(5, 5), b(5, 5);
	if(a == b) cout << "Equal" << endl;
	else cout << "Not equal" << endl;
	return 0;
}
```

* 클래스의 멤버 함수로 구현

다음은 프렌드 함수를 이용하여 ```Rect``` 클래스의 ```equals```함수를 클래스 멤버 함수 형태로 연산자 오버로딩으로 구현한 것이다.

```C++
#include <iostream>
using namespace std;

class Rect
{
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	bool operator == (const Rect& b);
};

bool Rect::operator == (const Rect& b) {
 	return ((this->width == b.width) && (this->height == b.height));
}

int main(int argc, char const *argv[])
{
	Rect a(5, 5), b(5, 5);
	if(a == b) cout << "Equal" << endl;
	else cout << "Not equal" << endl;
	return 0;
}
```


#### 연산자 오버로딩 예
```myVector``` 클래스에 대한 연산자 오버로딩을 클래스의 멤버함수로 선언하고 정의한 예를 보인다. 

```C++
// myvector.h
//
class myVector
{
	double x, y;
public:
	myVector(double x = 0.0, double y = 0.0):  x(x), y(y){};
	void printVector();	

	myVector operator+(myVector& V);
	myVector operator-(myVector& V);	
	bool operator==(myVector& V);
};
```
myVector의 멤버함수를 정의한 코드는 다음과 같다. 

```C++
// myVector.cc or myVector.cpp
#include "myVector.h"

void myVector::printVector() {
	cout << "vector (" << x <<", " << y << ")" << endl;
}

myVector myVector::operator+(myVector& V){
	myVector rV = myVector(x+V.x, y+V.y);
	return rV;
}

myVector myVector::operator-(myVector& V){
	myVector rV = myVector(x-V.x, y-V.y);
	return rV;
}	

bool myVector::operator==(myVector& V){
	return (x == V.x && y == V.y);
}
```
MyVector에서 오버로딩된 연산자를 이용한 프로그램 코드는 다음과 같다.  아래의 코드
(10.5, 20.1), (30.2, 11.5) 의 벡터 값을 저정하는 객체 a, b 를 선언하였고 
객체 c 에  두 백터의 합과 차를 구하고 두 벡터에 저정된 값을 비교하는  ```==``` 연산자를 
검증하였다. 

```C++
// myVectorTest.cc
int main(int argc, char const *argv[])
{
	myVector a(10.5, 20.1);
	myVector b(30.2, 11.5);
	myVector c;

	c = a + b;
	c.printVector();
	c = a - b;
	c.printVector();

	if(a == b) cout << " a 와 b 는 같음" << endl;
	else cout << "a 와 b는 같지 않음" << endl;

	return 0;
}
````
프로그램의 실행결과는 다음과 같다. 
```shell
tor (40.7, 31.6)
vector (-19.7, 8.6)
a 와 b는 같지 않음
```

```C++
class Time
{
	int hour, min, sec;
public:
	Time(int h, int m, int s) : hour(h), min(m), sec(s){}
	~Time(){};
  
  Time& operator = (Time& T);   // 대입 연산자 
	bool operator == (Time& T);
	bool operator != (Time& T);
	bool operator > (Time& T);
	bool operator < (Time& T);
};
```

Time 클래스에서 선언된 4개의 연삱자 (==, !=, >, <) 의 오버로딩의 정의는 다음과 같다. 
```C++
bool Time::operator==(Time& T) {
	return hour == T.hour && min == T.min && sec == T.sec;
}

bool Time::operator!=(Time& T) {
	return !(*this == T);
}

bool Time::operator>(Time& T) {
	return hour > T.hour || min > T.min || sec > T.sec; 
}

bool Time::operator<(Time& T) {
	return (*this != T) && !(*this > T);
}
```
앞의 Time 클래스 선언 중에 다음 함수가 선언되었다. 

```C++
Time& operator=(Time& T); 
``` 
대입연산자는 오른쪽 객체의 속성 값을 왼쪽의 속성값으로 대입하고 객체의 참조자를 반환한다. 이는 대입 연산자를 
연속해서 사용하여야 하기 때문이다. 그러므로 대입연산자는 다음과 같이 정의된다.

Time& Time::operator=(Time& T) {
  this->hour = T.hour;
  this->min = T.min;
  this->sec = T.sec;
  return *this;
}

```C++
class MyString
{
	char* buf;		// 문자열 데이터가 저장된 메모리 식작 조사 		
	int length;		// 문자열의 길이 
	int capacity;  	// 할당된 메모리 용량
public:
	MyString();
	MyString(const char* str);		// 
	MyString(const MyString& str);  // 복사 생성자
	~MyString();

	int length() const;
	int capacity() const;
	char at(int i) const;

	char operator[] const;

	bool operator==(MyString& str);
	bool operator > (MyString& str);
	
};
```

## 배열 연산자 오버로딩

C++에서 배열 연산자(operator[]) 오버로딩을 할 때 반환 원본 객체의 요소를 직접 수정하거나 접근하여야 하기 때문에 반환 타입은 reference로 하여야 한다. 

C++의 기본 배열은 다음과 같이 동작한다.

```c++
int array[] = {1, 2, 3};
arr[0] = 10;    // 배열의 첫번째 저장 장소에 새로운 값을 저장
int x = arr[2]; // 배열에 저장된 값을 읽기
```
사용자 정의 클래스에서 operator[]를 오버로딩할 때도 기본 배열처럼 대입 연산자 기준으로 좌변에 있어야 하기 때문에 참조로 반환해야 한다. 

```c++
class Array {
    int data[3];
public:
    int operator[](int i) { return data[i]; }  // 값 반환
};

int main() {
    Array arr;
    arr[0] = 10;  	// (컴파일 에러) 임시 값(int)에는 대입할 수 없음
	int x = arr[1]; 
}
```
arr[0]은 data[0] 값을 반환한 것으로 데이터를 저장할 수 있는 저장 장소가 할당되어 있지 않아 오류가 발생한다.

```c++
class Array {
    int data[3];
public:
    int& operator[](int i) { return data[i]; }  // 참조 반환
};

int main() {
    Array arr;
    arr[0] = 10;      // 가능: data[0] 직접 수정
    int x = arr[1];   // 값 읽기 가능
}
```
arr[0]은 data[0]에 대한 참조(lvalue reference)로 반환되므로 원소를 직접 수정할 수 있다.
