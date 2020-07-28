# 프렌드 함수 (friend function) 와 프렌드 클래스 (friend class)

C++ 프렌드(friend) 키워드는 클래스 내의 모든 멤버를 접근할 수 있도록 함수로 클래스의 멤버함수와 동일한 접근 권한을 갖는다. 프렌드 키워드는 함수와 클래스에 사용된다.
C++ 에서는 클래스 외부에 작성된 함수나 클래스를 클래스 내에서 ```friend``` 키워드로 선언하여 클래스의 멤버와 동일한 접근 자격을 부여할 수 있다. 
클래스 내의 모든 멤버에 접근할 수 있는 **외부 함수** 또는 다른 **클래스의 멤버 함수** 를 프렌드 함수라 한다. 프렌드 함수는 클래스 내에 ```friend``` 키워드와 함께 선언된 함수이다.
프렌드 함수는 클래스의 멤버 함수가 아니기 떄문에 상속되지 않기 때문에 클래스 내의 어디에서든지 선언할 수 있따. 프렌드 키워드와 선언할 수 있는 것은 **외부 함수**, **다른 클래스의 멤버 함수**, **다른 클래스** 세 종류이다.

## 프렌드 함수가 왜 필요한가?

두 개의 객체를 연산하는 함수를 클래스의 멤버 함수로 작성하는 경우 클래스의 멤버 함수의 입력 파러미터르 같은 클래스의 객체를 전달하여야 한다. 
그러나 두 개의 객체를 입력 파러미터로 전달하여 연산하는 함수는 클래스의 멘버를 접근할 수 있어야 하기 때문에 프렌드 키워드가 사용된다. 

## 프렌드 함수 (외부 함수) 선언 
클래스 외부에서 정의된 함수가 클래스 멤버를 접근할 수 있도록 하기 위해서 클래스 외부 함수를 클래스 내에서 프렌드 키워드를 사용허여 아래와 같이 선인한다.
equals() 함수는 Box 클래스의 모든 멤버를 접근할 수 있다.
```C++
class Box {
  ...
  friend bool equals(Box a, Box b); 
};
```
프렌드 함수 선언 및 정의의 예는 다음과 같다.

## 프렌드 함수의 예
```C++
#include <iostream>
using namespace std;


class Rect;
bool equals(Rect r, Rect s);

class Rect
{
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	friend bool equals(Rect r, Rect s);      // 프렌드 함수 선언
};

bool equals(Rect r, Rect s) {				 // 프렌드 함수 정의 
	return ((r.width == s.width) && (r.height == s.height));
}     

int main(int argc, char const *argv[])
{
	Rect a(5, 5), b(5, 5);
	if(equals(a, b)) cout << "equal" << endl;
	else cout << "Not equal" << endl;
	return 0;
}
```
실행결과는 다음과 같다.
```equal```

## 프렌드 멤버(다른 클래스의 멤버 함수) 선언 

```C++
class Box {
  ...
  friend bool BoxManager::equls(Box a, Box b);
};
```
# 프렌드 클래스 (friend class)
클래스 내부의 멤버 변수와 멤버 변수의 내용

## 프렌드 클래스 선언

```C++
class Box{             // 접근을 허용해주는 클래스 이름 (BoX)
  ...
  friend BoxManager;   // 접근을 허용받는 클래스 이름 (BoxManager)
};
```
다음 프로그램은 프렌드 클래스의 예이다. ```Rect``` 클래스는 ```objManager``` 클래스를 
프렌드 클래스로 선언하여 ```objManager```클래스에서 ```Rect``` 클래스의 멤버를 직접 접근할 수 
있어서 ```objManager```클래스의 멤버 함수 ```equals```에서 ```Rect``` 클래스의 멤버 변수를 
직접 접근하여 ```Rect```클래스의 구 객체를 비교하고 있다. 

```C++
#include <iostream>
using namespace std;

class Rect;
class objManager
{
public:
	bool equals(Rect r, Rect s);
};

class Rect
{
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	friend objManager;               		
};

bool objManager::equals(Rect r, Rect s) {	
	return ((r.width == s.width) && (r.height == s.height));
}     

int main(int argc, char const *argv[])
{
	Rect a(5, 4), b(5, 5);
	objManager manager;

	if(manager.equals(a,b)) cout << "equal" << endl;
	else cout << "Not equal" << endl;
	return 0;
}
```
실행 결과는 다음과 같다.
```C++
Not equal
```

앞의 함수들은 연산자 중복(오버로딩)을 통해서 구현이 가능하다. 

### 프렌드 함수의 특징
 
* 프렌드 함수와 프레드 클래스의 선언은 클래스 내의 어디에서도 가능하다.
* 접근을 허용받는 클래스와 함수는 허용해주는 클래스의 모든 멤버를 접근할 수 있다.
* 반드시 허용해주는 클래스와 함수에서만 선언할 수 있다.


```friend```는 객체지향의 정보 은닉 개념에 위배되는 것으로 ```friend```남발하는 것은 좋지 않다.



