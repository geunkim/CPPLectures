# 열겨형 (Enumerated data type)

열거형은 표현할 수 있는 값의 범위가 제한된 고유한 자료형이다. 값의 범위는 명시적으로 명명한 여러 상수(열거자) 값은 열겨헝의 기본 형식으로 알려진 정수 형식의 값이다. 즉 열거형은 가능한 모든 값의 기호 상수로 정의되는 자료형으로 ```enum``` 키워드를 통해 다음과 같이 정의된다.

```bash
// unscoped enum:
enum [identifier] [:type]
{enum-list};

// scoped enum:
enum [class|struct]
[identifier] [:type]
{enum-list};
```

```c++
// Forward declaration of enumerations  (C++11):
enum A : int; // non-scoped enum must have type specified
enum class B; // scoped enum defaults to int but ...
enum class C : short;  // ... may have any integral underlying type
````

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







