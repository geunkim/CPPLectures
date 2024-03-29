# 순수 가상 함수 (Pure Virtual Function)

순수 가상 함수는 가상 함수 중 함수의 정의가 이루어지지 않은 함수를 뜻한다.
순수 가상 함수의 선언은 다음과 같다. 

```c++
virtual int func() = 0;
```
클래스 중 순수 가상 함수를 멤버 함수로 가진 클래스를 추상 클래스(abstract class)라고 한다. 
추상 클래스는 객체를 생성할 수 없고 상속을 통해 자식 클래스를 통해 객체로 만들 수 있다. 
추상 클래스를 상속받는 클래스는 순수 가상 함수를 재 정의(overrride)하여야 한다. 

추상 클래스는 실제 구체적인 클래스 들의 공통적인 속성을 가지고 공통적인 인터페이스를 가지는 일반화된 클래스로 
상속받는 구체적인 클래스에서 공통적인 인터페이스를 구체적으로 구성한다.
즉 추상 클래스는 구체적인 클래스가 파생될 수 있는 일반적인 개념의 표현으로 동작한다. 추상 클래스는 객체를 생성할 수 없으나 
추상 클래스 자료형의 포인터와 참조를 사용할 수  있다. 
추상 클래스는 클래스의 멤버 함수 증 순수 가상 함수를 상속받는 클래스에서 구현하는 것을 강제화할 때 사용된다. 

```c++
class Shape {
public:      
  virtual void draw() = 0;
};

class Rect : public Shape {
public:
  void draw() { cout << "사각형 그리기 기능 구현" << endl; }
};

class Circle : public Shape {
public: 
  void draw() { cout << "원 그리기 기능 기능 구현" << endl; }
};

class Triangle : public Shape {
public:
  void draw() { cout << "삼각형 그리기 기능 구현" << endl; }
};
```

## 추상 클래스의 제약 사항

추상 클래스는 다음으로 사용할 수 없다. 

* 변수 또는 멤버 데이터
* 파러미터 자료형 
* 함수의 반환 자료형 
* 명시적 자료형 변환의 자료형 

추상 클래스의 생성자가 순수 가상 함수를 직접적 또는 간접적으로 호출하면, 결과는 정의되지 않는다. 
그러나 추상 클래스의 생성자와 소멸자는 다른 멤버 함수를 호출할 수 었다. 

