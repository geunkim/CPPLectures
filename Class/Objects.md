# 객체(Object)

## 클래스와 객체 

프로그래밍의 목적은 일상 생활의 문제를 컴퓨터틀 통해 해결하기 위한 것으로 일상 생활의 대상을 컴퓨터에서 처리 대상으로 모델링하는 하는 것이 요구된다. 우리 주변에 있는 
모든 것이 객체라 할 수 있다. 스마트폰, TV, 책, 자동차, 컴퓨터, 의자 등은 우리 주변에 있는 객체 들이다. 또한 컴퓨터 게임에서의 캐릭터, 배경화면을 구성하는 요소들도
객체이다. 이러한 객체들은 객체를 구분짓는 특성과 기능을 가진다. C++와 같은 객체 지향 프로그래밍 언어는 이러한 실생활의 객체를 모델링하거나 게임과 같은 프로그램 내의 
객체를 만들 수 있는 구조를 제공한다. 

* C++ 클래스는 데이터와 데이터를 제어하고 관리하는데 필요한 기능들(메소드들)의 모음이다.
* 클래스는 int, float, double 등 기본자료형과 유사한 자료형이다.
* 객체는 클래스의 자료형을 갖는 특정 변수이다.  

## 프로그램에서의 객체

지금까지 데이터를 저장하기 위해서 변수(variable)와 배열(array)을 데이터를 처리하기 위해서 함수(funciton)를 배웠다. 이들은 C++와 같은 객체지향 프로그래밍 언어
뿐만 아니라 절차적 프로그래밍 언어, 어셈블리 언어와 같은 다양한 프로그래밍 언어에서도 있었다. 

그러나, 우리가 다루는 데이터의 양이 커지고 중요성이 높아지고 프로그램의 규모가 커짐에 따라서 데이터를 보호하고 효율적으로 프로그래밍을 하는 기능에 대한 요구도 증가하였다.
이러한 요구에 따라 객체 지행 프로그래밍 언어의 클래스(Class)라는 개념이 만들어 졌으며 C++ 언어에서도 클래스 기능을 지원하였다. 클래스가 제공하는 기능을 활용하면 
복잡한 프로그램을 효츌적으로 개발할 수 있게 되었다.

## 프로그램의 객체와 실생활의 객체

실생활에서 다루는 특정한 객체(사물)에 대해서 살펴보자. 프로그램에서 자동차를 표현하려고 한다. 실생활의 객체를 프로그램에서 모델링하기 위해서는 다루려는 객체가 어떠한 **일반적연 속성과 기능** 을 가지고 있는지 확인하는데서 부터 시작된다. 
자동자가 가지는 속성으로 *차량번호, 등록번호, 연료의 양, 엔진의 용량, 최대 수용 인원* 등을 고려할 수 있다. 이들 속성은 구체적인 자동차에 따라 데이터 값을 가지며 이들 값을 자동차의 상태를 표현하게 된다. 
자동차는 상태를 표현하는 속성 이외에 "시동 걸기", "시동 끄기", "가속하가", "감속하가", "정지" 등의  기능을 가진다. 즉 
실생활의 객체는 상태 및 특성을 나타내는 속성 값과 관련된 기능을 가지며 프로그램에서의 객체도 이러한 상태와 특성을 나타내는 속성(변수) 값과 관련된 기능(함수)을 가진다. 

## 클래스와 객체

클래스는 실생활의 경우 자동차의 설계도와 같은 것으로 프로그램에서의 클래스는 객체가 가지는 속성의 자료형과 관련한 기능의 선언으로 일반적인 객체를 표현한 것으로 객체를 만들 수 있는 틀로 이해되고 있다.  

``` C++
class 자동차 {
  차량번호;
  동록번호;
  연료의 량:
  엔진의 용량;
  최대 수용 인원;  ...
  시동 걸기(); 
  시동 끄기(();
  가속하기();
  감속하기();
  정지(); ...
};

```
## 캡슐화  

캡슐화는 객체지향 프로그램의 주요 특징으로 객체의 속성인 데이터를 캡슐로 감싸서 보호하여 객체 외부에서 객체의 데이터에 접근(데이터 값 읽기 및 쓰기)할 수 업도록 하는 것이다. 외부에서 객체의 데이터를 접근하지 못하도록 캡슐화하면 객체 내의 데이터를 보호할 수 있다.

## 인터페이스 

일상 생활의 객체나 C++의 객체는 서로 상호작용(interaction)을 하면서 원하는 작업을 수행하게 된다. C++ 객체 간의 상호작용은 객체 내의 속성 값에 직접 접근하는 것은 객체의 캡슐화로 불가능하기 때문에 객체가 제공하는 기능을 이용하여 객체 들이 서로 정보를 교환한다. 이를 위해 객체는 기능을 외부에서 접근할 수 있도록 공개한다. 이러한 기능을 객체의 인터페이스라고도 한다. 객체들은 객체들이 제공하는 인터페이스를 통해 상호 통신을 한다.

예로 커피자판기를 생각해 보자. 커피 자판기는 일반적인 속성으로 *커피, 프림, 설탕, 물* 을 가진다. 실제 커피 자판기를 설치하고 동직 시키기 위해서 실제 커피, 설탕, 프림, 물이 자판기 내부의 재료 통 안에 들어 있어야 하는데 이 때 통 안 있는 커피, 설탕, 프림, 물의 제품(브랜드)는 커피 자판기 운영자에 따라 다를 것이다. 이러한 제품명이 속성 값의 예가 될 수 있다. 
커피 자판기가 가지는 기능은 자판기 앞에 있는 버튼 (블랙커피, 커피+프림 커리, 밀크커피) 이 된다. 이들 버톤을 누름에 따라 자판기 내에 저장된 재료를 알맞게 섞어 요청한 기능에 맞게 커피를 만들어 제공한다. 여기서 버튼들이 **인터페이스** 또는 **기능** 이라 하고 이들 기능 과 인터페이스는 외부에 공개되어 있는 반면 재료와 같은 속성에 대해서는 사용자가 직접 접근이 불가능하다. 

##  C++ 객체 구성 요소

C++에서 클래스는 어떤 개념을 프로그램 코드로 표현하기 위한 사용자 정의 자료형이다. 프로그램을 설게할 때 유용한 개념이나 아이디어들을 프로그램 안에서 클래스로 표현한다. 
C++ 객체는 자신만의 고유한 상태(state) 정보를 저장하고 있는 멤버 변수와 객체의 행동(behavior)에 해당하는 멤버 함수로 구성된다. 행동으로 객체의 상태가 변화되거나 행동으로 객체의 상태가 외부로 전달되기도 한다. 즉 외부에서 C++ 객체에게 특정 작업을 요청하거나 상태를 알고자 할 때 마다 객체에서 공개된 멤버 함수를 호출하게 된다.

C++에서 클래스를 선언하기 위해 **class** 키워드를 사용한다. C++ 클래스는 C언어의 구조체와 같이 사용자 정의 데이터 자료형(타입)이다. 객체의 일반화된 상태나 특성, 기능에 대해서 기술하는 작업을 **클래스의 선언(Class declaration)** 이라 한다.

```C++
class 클래스 이름 {  // 클래스 이름의 자료형을 선언
접근 지정자:
   멤버 변수 선언;    // 객체의 상태 또는 특성에 해당하는 변수 "자료형 변수이름" 의 형태로 선언 
    ...
   멤버 함수 선언;    // 객체의 기능에 해당하는 함수 "반환 자료형 함수 이름(인수 리스트)" 의 형태로 선언 
     ...
};   // 세미콜론(;)으로 끝내야 함
```
클래스 이름은 개발자가 객체를 잘 표현할 수 있도록 만들면 된다. 클래스 선언에는 객체를 일반화시킨 모양을
정의하는 것으로 멤버 변수와 멤버 함수를 선언한다. 멤버 변수와 멤버 함수는 중괄호{} 안에 작성되고 마지막에
세미콜론을 붙여야 한다. 
클래스의 멤버 함수는 클래스 선언 내에서 정의되거나 클래스 선언 밖에서 정의할 수 있다.
멤버 함수를 클래스 선언 밖에서 정의하는 구문은 다음과 같다.

```C++
반환 자료형 클래스 이름::함수 이름(인수 리스트)  // 멤버 함수 정의 
{ 
   ....
}
```
:: 는 범위 결정 연산자(scope resolution operator)로 멤버 함수가 특정 클래스의 멤버함수라는 것을 명시하는데
사용된다. 

에로 사각형을 나타내는 Rect 클래스를 선언해보자.

```C++
class Rect {
public:
  int width, height;   // 멤버 변수
  int getArea();       // 멤버 함수
};
```

클래스 선언 영역 외부에서 Rect 클래스의 멤버함수 getArea()의 정의는 다음과 같다.

```C++
int Rect::getArea() {
  return width * height;
}
```

클래스 선언 영역 내부에서 getArea() 함수의 정의는 다움과 같다.

```C++
class Rect {
public:
  int width, height;
  int getArea() { return width * height; }
```
멤버 함수를 클래스 선언 영역 내부에 정의할 경우 간결해 보일 수 있으나 멤버 함수의 개수가 많은 경우 클래스의 전체 구조를 한 눈에 
파악하기 어렵다. 그러므로 가능하면 클래스의 선언과 멘버 함수의 정의를 분리하여 표현하는 것이 일반적이다. 

### 접근 지정자
C++의 접근 지정자는 private, protected, public 의 3 종류가 있다. 이 접근지정자는 C++의 데이터 캡슐화와 관련이 있다.   
* private: private 접근 지정자는 갖는 멤버 변수, 명변 함수는 클래스 외부에서는 접근이 불가능 것으로 클래스 내부의 멥버에 의해서만 
접근이 가능하다. 
```C++
#include <iostream>

using namespace std;

class Rect {
private:
  int width, height;   // private 멤버 변수 
public:
  Rect(int w = 2, int h = 2) : width(w), height(h) {}
  int getArea() { return width * height; }
 };
 
 
int main(int argc, char const *argv[])
{
  Rect rectangle;
  rectangle.width = 5;     // 접근 오류
  rectangle.height = 4;   // 접근 오류
  
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
  cout << "Area: " << rectangle.getArea() << endl; 
}
```
앞의 프로그램을 컴파일하면 아래와 같이 세 곳에서 에러가 발생한다. 
```C++
error: 'width' is a private member of 'Rect'
  rectangle.width = 5;     // 접근 오류
            ^
error: 'height' is a private member of 'Rect'
  rectangle.height = 4;   // 접근 오류
            ^
error: 'width' is a private member of 'Rect'
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
```  

* public: public 접근 지정자로 지정된 멥버 변수와 멤버 함수는 클래스 외부에서 접근이 가능하다. 

```C++ 
#include <iostream>

using namespace std;

class Rect {
public:
  int width, height;   // public 멤버 변수 
  Rect(int w = 2, int h = 2) : width(w), height(h) {}
  int getArea() { return width * height; }
 };
 
int main(int argc, char const *argv[])
{
  Rect rectangle;
  rectangle.width = 5;     // 접근 가능
  rectangle.height = 4;    // 접근 가능
  
  cout << "Width: " << rectangle.width<< endl;  // 접근 가능
  cout << "Area: " << rectangle.getArea() << endl; 
}
```
앞의 프로그램을 컴파일하면 컴파일 에러가 발생하지 않으며 실행한 결과는 다음과 같다.
```C++
Width: 5
Area: 20
```
* protected: private 접근 지정자와 비슷하게 클래스 외부에서는 protected 멤버에 접근하지 못하나 상속을 받는 자식 클래스 내부의 멤버들은 접근이 가능하다. 이 접근 지정자는 상속 관계에서만 의미를 가진다. **private 접근 지정자로 지정된 멤버는 상속받은 자식 클래스 내부에서 접근이 불가능하다.**

```C++ 
#include <iostream>

using namespace std;

class Rect {
protected:
  int width, height;   // protected 멤버 변수 
public:
  Rect(int w = 2, int h = 2) : width(w), height(h) {}
  int getArea() { return width * height; }
 };
 
int main(int argc, char const *argv[])
{
  Rect rectangle;
  rectangle.width = 5;     // 접근 오류
  rectangle.height = 4;    // 접근 오류
  
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
  cout << "Area: " << rectangle.getArea() << endl; 
}
```
앞의 프로그램을 컴파일하면 아래와 같이 세 곳에서 에러가 발생한다. 
```C++
error: 'width' is a protected member of 'Rect'
  rectangle.width = 5;     // 접근 오류
            ^
error: 'height' is a protected member of 'Rect'
  rectangle.height = 4;   // 접근 오류
            ^
error: 'width' is a protected member of 'Rect'
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
```  

```C++
#include <iostream>

using namespace std;

class Shape {
private:
  int pointX, pointY;
public:
  Shape(int x = 2, int y = 2) : pointX(x), pointY(y) {}
  void printPoint() { cout <<"point: " << pointX << ", " << pointY << endl; } 
 };
 
 class Rect : public Shape
 {
 private:
 	int width, height;
 public:
 	Rect(int w, int h) : width(w), height(h) {}
 	void printEndpoint() {
 		cout <<"Rect: " << pointX + width << ", "   // 접근 에러
 			 << pointY + height << endl;
 	}
 };
 
int main(int argc, char const *argv[])
{
	Shape p1(10, 20);
	Rect rectangle(10, 20);

	p1.printPoint();

	rectangle.printPoint();
	rectangle.printEndpoint();
}
```
앞의 코드를 컴파일 하면 다음과 같이 2개의 컴파일 에러가 발생한다. 에러가 발생하는 이유는 부모 클래스인 shape의 멤버 변수 
pointX 와 pointY 가 private 접근 지정자로 지정되어 있어 자식 클래스인 Rect 클래스에서 접근이 가능하지 않기 떄문이다. 

```C++
error: 'pointX' is a private member of 'Shape'
                cout <<"Rect: " << pointX + width << ", "    // 접근 에러
error: 'pointY' is a private member of 'Shape'
                         << pointY + height << endl;         // 접근 에러
```
다음 코드는 부모 클래스의 pointX, pointY 멤버 변수가 protected 접근 지정자로 지정되어 있다. 이를 상속받은 Rect 클래스의 멤버 함수에서 Shape 클래스의 pointX, pointY 를 접근할 수 있다. 
```C++
#include <iostream>

using namespace std;

class Shape {
protected:
  int pointX, pointY;
public:
  Shape(int x = 2, int y = 2) : pointX(x), pointY(y) {}
  void printPoint() { cout <<"point: " << pointX << ", " << pointY << endl; }
 };
 
 class Rect : public Shape
 {
 private:
 	int width, height;
 public:
 	Rect(int w, int h) : width(w), height(h) {}
 	void printEndpoint() {
 		cout <<"Rect: " << pointX + width << ", "    //접근 에러
 			 << pointY + height << endl;
 	}
 };
 
int main(int argc, char const *argv[])
{
	Shape p1(10, 20);
	Rect rectangle(10, 20);

	p1.printPoint();

	rectangle.printPoint();
	rectangle.printEndpoint();
}
```
앞의 코드의 실행 결과는 다음과 같다.
```C++
point: 10, 20
point: 2, 2
Rect: 12, 22
```




