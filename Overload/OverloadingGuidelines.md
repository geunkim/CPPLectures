# cpp 연산자 오버로딩 가이드라인 

사용자 정의 클래스에 대한 연산자에 특별한 의미를 부여하는 연산자 오버로딩을 할 수 있는 대표적인 연산자는 다음과 같이 분류할 수 있다. 
* 대입연산자 (assignment operator): =
* 복합 대입 연산자 (compound assignment operators): +=, -=, \*=
* 이진 산술 연산자 (binary arithmetic operators): +, -, \*, /
* 비교 연산자 (comparision operators): ==, !=

## 대입연산자 (assignment operator)
```cpp
class MyClass {
  public:
...
MyClass & operator=(const MyClass &rhs); 
...
};

MyClass a, b;
...
b = a;  // b.operator=(a); 와 동일
```

= 연산자가 우측에 대입한 내용을 상수 참조한다. 상수 참조하는 이유는 연산자 왼쪽에 있는 객체의 내용을 변경하는 것일 뿐 오른쪽에 있는 객체의 내용의 변경을 원하지 않기 때문이다. 
그리고 대입 연산자가 참조로 변환한다. 대입 연산자의 연결(operator chaining)을 가능하도록 하기 위해서 참조형을 반환한다. 기본 자료형에 대해 대입연산자를 다음과 같이 사용한다.

```cpp
int a, b, c, d, e;
a = b = c = d = e = 42;
```
컴파일러는 앞의 코드를 다음처럼 해석한다.
 ```cpp
 a = (b = (c = (d = (e = 42))));
 ```
 
 대입 연산은 오른쪽 연관(right-associative)이다. 오른쪽의 마지막 대입 연산이 먼저 처리되고 연속적으로 대입 연산을 따라 왼쪽으로 처리된다.
 
 * e = 42 는 42를 e에 대입하고 그 결과로 e를 반환한다.
 * e의 값이 d에 대입되며 그 결과로 d를 반환한다.
 * d의 값이 c에 대입되며 그 결과로 d를 반환한다.
 * 그 외..
 
 즉 연산자 연결을 지원하기 위해서 대입 연산자는 반드시 값을 반환해야 한다. 반환되어야 하는 값은 대입 연산의 왼쪽의 값을 참조하여야 한다. 반환 참조를 상수로 선언하지 않는 것은 다음과 같은 코드를 작성할 수 있기 때문이다.
 ```cpp
 MyClass a, b, c;
 ...
 (a = b) = c;
 ```
 앞의 코드의 동작이 기본 자료형과 같이 동작되어야 하기 때문에 상수로 반환해서는 안된다. 그러므로 MyClass 대입 연산자는 다음과 같이 작성 가능하다.
 
```cpp
//대입 연산의 오른쪽은 상수 참조
//대입 연산의 왼쪽은 상수가 아닌 참조를 반환 
MyClass& MyClass::operator=(const MyClass& rhs) {
  ... // 대입 연산을 수행 
  return *this; // 객체 자기 자신을 참조로 반환 
}
```
여기서 this는 객체에 대한 포인터이고 멤버 함수로 호출되는 대상이다. a = b 가 a.operator=(b) 로 처리되는 방법으로 부터 객체 자체가 호출되는 함수로 해석하는 것이 바람직하다. 객체 a는 대입 연산자의 왼쪽에 해당한다. 

대입 연산자를 고려할 때 가장 중요한 것은 자기 할당(self-assignment)를 확인하는 것이다. 클래스가 자체적으로 메모리를 할당하는 경우이면 특히 중요하다. 대입 연산자가 일련의 연산을 수행할 때 다음과 같이 동작한다.

```cpp
MyClass& MyClass::operator=(const MyClass& rhs) {
   // 1. MyClass가 내부적으로 가지고 있은 모든 메모리 할당을 해제한다. 
   // 2. rhs의 내용을 저장하기 위해 메모리에 할당한다.
   // 3. rhs로 부터 값을 인스턴스에 복사한다.
   // 4. *this를 반환한다.
}

MyClass mc;
...
mc = mc; 
```
mc는 대입 연산자의 왼쪽에도 있고 오른쪽에데 있기 때문에 mc가 내부적으로 할당된 모든 메모리를 해체한다. 그러나 오른쪽 mc의 값이 복사될 곳이기도 하다. 메모리 해제와 할당을 모두 고려하여야 하는 문제가 있다. 이 문제를 해결하기 위해서 **자기 대입**을 확인하여야 한다. 즉 두 인스턴스가 같은 것인지 확인하여야 한다. 두 인스턴스가 같은지를 확인하는 방법은 여럿있을 수 있으나 객체 주소가 동일한지 확인하면 된다. 만일 주소가 동일하면 할당을 하지 않는다. 주소가 다르면 새로운 저장 공간을 할당한다.

```cpp
MyClass& MyClass::operator=(const MyClass &rhs) {
  // 자기 대입을 확인 
  if (this == &rhs)  
     return *this; 
  else // 할당 해제, 새 공간을 할당하고 값을 복사
  
  return *this;
}
```
앞의 코드에서 this는 호출되는 객체 포인터이고 &rhs는 인자로 전달된 객체를 가리키는 포인터로 앞의 코드와 같은 검사로 대입의 위험성을 
회피할 수 있다. 

결론으로 정리하면 대입 연산자를 위한 가이드라인은 다음과 같다. 

1. 입력 파라미터(인자)는 상수 참조로 받는다. 
2. 왼쪽에 참조를 반환해서 안전하고 적절한 연산자 연결을 지원한다. (\*this를 반환하는 방법으로)
3. 포인터를 비교하여 자기 대입을 확인한다. (this와 &rhs) 

## 복합 대입 연산자 

이 연산은 destructive 연산자로 대입의 왼쪽의 값이 갱신되거나 대체되게 된다. 
```cpp
MyClass a, b;
...
a += b; // a.operator++(b) 와 같음 
```
이 연산자 오버로딩 함수의 형태는 다음과 같다.
```cpp
MyClass& operator+= (const MyClass &rhs) {
...
}
```
반환 형태가 참조자이기 때문에 다음 코드가 가능하다.
```cpp
MyClass mc;
...
(mc += 5) += 3;
```
이와 같이 코드를 작성하는 프로그래머는 드물겠지면 일반적인 대입 연산자와 같이 이 복합 대입 연산자는 기본 자료형에서 지원되기 때문에 이와 같은 사용자 정의 자료형에서도 같은 맥락으로 동적이 되어야 한다. 북합 대입 연산자의 구현도 ```cpp\*this```를 반환하도록 작성한다. 그러므로 복합 대입 연산자의 정의는 다음과 같다.
```cpp
MyClass& operator+= (const MyClass &rhs) {
...   // 복합 대입 작업을 수행 
  return *this;
}

## 이진 산술 연산자 

이진 산술 연산자는 연산의 양쪽을 모두 수정하지 않으며 두 인자로 만든 새로운 값을 반환한다. 이 연산은 조금 추가적인 작업이 필요하다. 
이진 산술 연산자인 ```+```을 구현하는 함수는 다음과 같다. 

```cpp
//인스턴스의 값을 다른 곳에 추가하고 결과와 함께 새 인스턴스를 반환
const MyClass MyClass::operator+(const MyClass &other) const {
   MyClass result = *this;  // 복사폰본을 만든다.
   result += other;         // 
   return result;
}
 ```
 
 앞의 코드를 다음가 같이 한줄 구문으로 작성할 수 있다. 
```cpp
const MyClass MyClass::operator+(const MyClass &other) const { 
   return MyClass(*this) += other;
}
 ```
앞의 코드는 ```*this```의 사본으로 이름없는 MyClass 인스턴스를 생성한다.
그 후 ```+-``` 연산자는 이 임시 값에서 호출하고 반환한다.

## 비교 연산자

비교 연산자는 다음과 같이 선언된다.
```cpp
bool MyCLiass::operator==(const MyClass &other) const {
   .. .
}
```
!= 연산자는 == 연산자를 활용하여 간편하게 정의한다. 
```cpp
bool MyCLiass::operator!=(const MyClass &other) const {
   return !(*this == other)
}
```


 



