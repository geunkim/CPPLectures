# 정적 클래스, 정적 멤버변수, 정적 멤버함수 (static class, static member varialbe, static member function)

## 정적 멤버

클래스로부터 객체가 생성되면 클래스에서 선언된 멤버는 "객체 단위의 멤버"로 객체들 마다 각기 다른 값을 가질 수 있는 독립된 변수이다. 
```C++
class Rect {
public:
  int width, height;
  int getArea() { return width * height; }
```
앞의 Rect 클래스로 부터 객체를 r1, r2, r3를 생성하면 각 객체마다 별도의 width, height 변수를 가진다. 

정적 멤버는 "클래스의 멤버"로 객체마다 독립적으로 변수가 선언되는 것이 아니라 클래스에 하나의 변수만 할당되고 생성된 객체들 간 저장공간의 
공유가 생긴다. 
정적 멤버는 다음과 같은 경우에 사용될 수 있다.
* 프로그램에서 Rect 클래스로 부터 생성된 객체의 수를 알고 싶은 경우
* Rect 클래스의 버전 또는 개발 정보를 클래스에남기고 싶은 경우 
