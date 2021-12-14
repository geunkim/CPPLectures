# 함수 객체

## 함수 객체란 

일련의 초기화 과정이 필요하고 특정 상태를 유지하는 함수가 필요한 경우 C++에서 함수 객체를 사용하여 이 기능을 구현한다. 함수 객체는 하나의 (이름 없는) 함수를 캡슐화한 객체이다. 

```함수 객체(function object)``` 또는 ```functor```는 ```operator()```를 구현하는 임의의 자료형이다. 이 연산은 호출 연산자(call operator)라 . 
C++ 표준 라이브러리는 기본적으로 컨테이너의 정렬 기준과 알고리즘에서 함수 객체를 사용한다. 

함수 객체는 직접적인 함수 호출에 비해 두 가지 장점을 가진다. 첫 번째 장점은 함수 객체에 상태를 포함할 수 있다는 점이고 두 번쨰 장점은 객체가 자료형이므로 템플릿 매개변수로 사용할 수 있다.

### 함수 객체 만들기 

함수 객체를 만들기 위해서 다음과 같은 형식을 만들고 ```operator()```를 구현한다. 

```c++
class Functor{
public:
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

int main(int argc, char const *argv[])
{
	Functor f;
	int a = 5, b = 6;

	bool result = f(a, b);  // 함수 객체 호출 
	cout << "f(" << a <<", " << b <<"): " << result << endl;
	return 0;
}
```
```f(a, b)```는 함수를 호출하는 것과 같으나 실제로 Functor 자료형의 ```()``` 연산자를 호출한 것이다. 

다음 함수 객체 환율을 변환하는 함수 객체의 간단한 예이다. 객체 안에 포함되는 이름없는 함수를 선언할 때는 ```operator()``` 연산자를 사용하면 된다.

```c++

class converter{
	double exchange_rate;

public:
	converter(double ex) : exchange_rate(ex) {}

	double operator()(double amt) {
		return amt * exchange_rate;
	}
};

int main(int argc, char const *argv[])
{
	converter dollar_to_won(1182);     // 달러를 원으로 변환하기 위한 객체
	double won = dollar_to_won(100);   // dollar to won converter

	cout << "won: " << won << endl;
}

```
converter() 함수를 사용하기 위해서 conveter 클래스의 인스턴스를 생성해야 한다. 함수 객체는 함수를 인자로 넘겨줄 수 있다. 

### 함수 객체 및 컨테이너

C++ 표준 라이브러리는 ```<functional>``` 헤더 파일에 여러 함수 객체를 포함한다. 함수 객체의 사용은 컨테이너의 정렬 기준이다.
에로 다음과 같은 ```set``` 컨테이너 선언이 있다.

```c++
template <class Key, class Traits=less<Key>, class Allocator=allocator<Key>> class set
```
두 번쨰 템플릿 매개변수인 ```less``` 가 함수 객체이다. 이 함수 객체는 첫 번째 파라미터가 두 번째 파라미터보다 적으면 **true**를 반환한다.
```set```, ```map```과 같은 컨테이너는 요소를 정렬하기 때문에 컨테이너는 두 요소를 비교하는 방법이 필요하다. 
비교는 함수 객체를 이용하여 행해지며 함수 객체를 생성하여 컨테이너에 대한 프로그래머가 규정한 정렬 기준을 정의할 수 있고 컨테이너 내의 템플릿 리스트에 적용할 수 있다.

### 함수 객체 및 알고리즘 

함수 객체의 또 다른 용도는 알고리즘이다. 예로 다음과 같은 ```remove_if``` 알고리즘이 있다. 

```c++
template <class ForwardIterator, class Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred);
```
```remove_if```의 마지막 인자도 부울 값을 반환하는 함수 객체이다. 함수 객체의 반환 값이 **true**이면 반복자 ```first```에서 ```last```로 접근이 되는 컨테이너로 부터 요소가 삭제된다. 인자 ```pred```에 ```<functional>``` 해더에 선언된 함수 객체 또는 직접 정의한 함수 객체를 사용할 수 있다. 


## Sample Code
