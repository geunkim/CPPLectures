# Opeerator overloading (연산자 중복)

연산자는 의미를 간결하게 전달할 수 있는 편리한 기호이다. 일반적으로 연산자 기호를 사용하는 것이 함수로 정의하는 것 보다 이해하기 쉽다. 
이러한 이유 때문에 객체 

연산자 오버로드는 개발자가 연산자의 의미를 객체애 대해서 다시 정의할 수 있는 기능이다. 연산자 오버로드는 operator 키워드를 사용한다. operator 키워드는 클래스의 객체의 연산자를 적용했을 때 연산자 심볼의 기능을 규정하는 함수이다.
연산자 오버로드는 연산자에 하나 이상의 의미를 갖도록 하거나 기존 성의된 연산 기능을 중복 정의한다. 컴파일러는 피 연산자의 자료형을 조사하여
연산자의 동작의 차이를 구별한다.

#### 구문 (Syntax)
```C++
자료형 operator operator_symbol (parameter-list)
```
대부분의 내장 연산자의 함수를 전역적으로 또는 클래스 별로 재 정의할 수 있다. 오버로드된 연산자는 함수로 구현된다. 오버로드된 연산자의
함수가 "operator X" 이면 X가 연산자이다. 예로 더하기 연산자를 오버로드하기 위해 정의된 함수는 "operator +" 이다. 빼기 연산의
오버로드 함수는 "operator -" 이다. 

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

* 멤버함수로 오버로드된 이항 연산자의 경우 연산자 사용 시 첫번째 피연산자는 항상 연산자가 호출되는 객체이다.
예로
```C++
Sample Sample::operator + (Sample& s);
```
의 연산자 오버로딩이 선언/정의되어 있을 경우, 이 연산자를 다음과 같이 사용할 수 있다.
``` Sample a, b, c; ```
```...```
``` c = a + b; ```

이 때 a 객체의 속성 값은 선언하는 클래스의 멤버 변수가 된다. 즉 a 객체는 ```opeator+```를 
멤버함수로 제공하는 객체에 해당하고 b 객체는 ```opeator +``` 함수의 입력파러미터 s에 해당한다. 

```C++
class myVector
{
	double x, y;
public:
	myVector(double x = 0.0, double y = 0.0):  x(x), y(y){};
	void printVector();	

	myVector operator+(myVector& V);
	myVector operator-(myVector& V);	
	bool operator == (myVector& V);
};
`




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
bool Time::operator == (Time& T) {
	return hour == T.hour && min == T.min && sec == T.sec;
}

bool Time::operator != (Time& T) {
	return !(*this == T);
}

bool Time::operator > (Time& T) {
	return hour > T.hour || min > T.min || sec > T.sec; 
}

bool Time::operator < (Time& T) {
	return (*this != T) && !(*this > T);
}
```
앞의 Time 클래스 선언 중에 다음 함수가 선언되었다. 
```C++
Time& operator = (Time& T); 
``` 
대입연산자는 오른쪽 객체의 속성 값을 왼쪽의 속성값으로 대입하고 객체의 참조자를 반환한다. 이는 대입 연산자를 
연속해서 사용하여야 하기 때문이다. 그러므로 대입연산자는 다음과 같이 정의된다.

Time& Time::operator = (Time& T) {
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


