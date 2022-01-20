# 열겨형 (Enumerated data type)

열거형은 표현할 수 있는 값의 범위가 제한된 고유한 자료형이다. 값의 범위는 명시적으로 명명한 여러 상수(열거자) 값은 열겨헝의 기본 형식으로 알려진 정수 형식의 값이다. 즉 열거형은 가능한 모든 값의 기호 상수로 정의되는 자료형으로 ```enum``` 키워드를 통해 다음과 같이 정의된다.

## 구문

```bash
// unscoped enum:
enum [identifier] [:type]
{enum-list};

// scoped enum:
enum [class|struct]
[identifier] [:type]
{enum-list};
```

```identifier```는 열거형에 지정된 자료형의 이름이다. ```type```은 열거형의 기본 자료형으로 모든 열거자의 기본 자료형이 동일하다. 모든 정수 자료형이 될 수 있다. 열거형 자료형 선언 시 ```class```라는 키워드를 사용하여 열거형의 범위를 지정하고 ```identifier```를 제공해야 한다. 이 맥락에서 struct 키워드는 의미적으로 동일하므로 class 대신 struct 키워드를 사용할 수도 있다. 

```c++
// Forward declaration of enumerations  (C++11):
enum A : int; // non-scoped enum must have type specified
enum class B; // scoped enum defaults to int but ...
enum class C : short;  // ... may have any integral underlying type
````
## 열거자 범위

열거(enumeration)는 열거자라고 불리는 이름이 부여된 상수로 표현되는 값의 범위를 기술하는 맥락을 제공한다.  원래 C 및 C++ 열거형 자료형에서는 정규화되지 않은 열거자가 열거형이 선언되는 범위(scope) 전체에서 접근이 가능하다. 범위가 지정된 열거형(scoped enum)에서는 열거자 이름을 열거형 자료형 이름으로 한정되어야 한다. 

아래 프로그램의 ```Mycard```, ```Yourcard```와 같이 열겨자에 해당되는 정수 값을 할당할 수 있다. 정수 값을 할당하지 않는 경우 기본적으로 0이 할당되고 다음 열거자는 1씩 증가된 값이 할당된다. 다음 프로그램의 Mycard의 Diamonds와 Hearts에는 각각 10과 20이 할당되고 Clubs와 Spades에는 각각 21, 22가 할당된다. Yourcard의 경우는 Damonds에 1을 할당하여서 다음 열거자에는 2, 3, 4 가 할당된 것을 프로그램의 결과로 부터 확인할 수 있다.

```c++
#include <iostream>

using namespace std;

enum Mycard { Diamonds = 10, Hearts = 20, Clubs, Spades}; // unscoped enum

enum class Yourcard { Diamonds = 1, Hearts, Clubs, Spades}; // scpoed enum

int main(int argc, char const *argv[])
{

	int value; 
	int account_num;
	Yourcard realcard;  // scoped enum variable
	value = Spades;     // OK. unscpoed enum can be asspgi
	cout << "Mycard enum(Diamonds): " << Diamonds << endl;
	cout << "Mycard enum(Hearts): " << Hearts << endl;
	cout << "Mycard enum(Clubs): " << Clubs << endl; 
	cout << "value: " << value << endl;
	realcard = Yourcard::Clubs; 

	account_num = static_cast<int>(Yourcard::Hearts);
	cout << "Yourcard::Hearts: " << account_num << endl;

	return 0;
}
```

앞의 프로그램 실행 결과는 다음과 같다. 

```bash
Mycard enum(Diamonds): 10
Mycard enum(Hearts): 20
Mycard enum(Clubs): 21
value: 22
Yourcard::Hearts: 2
```

## 형변환 규칙

앞의 코드에서 범위가 없는 열거형 상수는 암목적으로 ```int```형으로 변환할 수 있으나 ```int```는 enum 값으로 암묵적으로 변환할 수 없다. ```int``` 자료형의 값은 열거형 상수로 변환하기 위해서는 형변환이 필요하다. 그러나 범위가 없는 열거자는 형 변환 없이 정수 값에 대입할 수 있다.  

```c++
int value = Spades;  // OK
```

그러나 범위가 규정된 정수형 열거자 또는 정수형 변수에 대입하는 경우 의도하지 않는 문제가 발생할 수 있다. 

```c++
int value = Yourcard::Hearts;  // Error 
```



참고자료

* [MS Docs](https://docs.microsoft.com/ko-kr/cpp/cpp/enumerations-cpp?view=msvc-170)


