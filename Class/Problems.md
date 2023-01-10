# Problems - Class

1. 다음 Point 변수의 기본적인 멤버 함수를 정의하고 추가적으로 멤버함수를 추가하고 main 함수에서 객체를 생성하고 기능을 검증하라. 

```c++
class Point{
	double x;
	double y;
public:
	double getX();
	double getY();
	Point();
	Point(int x, int y);
	void setX(int x);
	void setY(int y);
	void printPoint();
	/* 멤버 함수를 추가하시요 */
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
```


2. 게임 캐릭터를 설계하고 이를 표현할 수 있는 GameCharacter 클래스를 정의하고 main 함수에서 객체를 생성하고 클래스 정의가 제대로 되었는지 검증하라.

  * 속성의 캡슐화를 반영하고 속성의 값을 변경하거나 확인할 수 있어야 한다.
  * 디폴트 생성자를 포함하여 생성자의 오버로드 구현
  * 클래스의 메소드 내에서는 화면에 출력하는 기능은 추가하면 안됨
  
  
3. 배열과 관련한 저장과 기능을 포함하는 MyArray 클래스를 정의하고 main 함수에서 객체를 생성하고 클래스 정의가 제대로 되었는지 검증하라.

  * MyArray 내의 정수형 데이터의 저장공간을 정적 할당(100개)하도록 설정하시오.
  * 클래스의 메소드 내에서는 화면에 출력하는 기능은 추가하면 안됨  
  
## 추가 문제
4. 클래스 기본 이해 확인 문제
  * 학생이라는 클래스를 만들기
  * 학생이라는 클래스의 이름, 나이, 학번을 저장하는 멤버변수를 만들기(생성자에서 초기화)
  * 해당 멤버변수를 출력하는 함수를 만들기
  * 해당 클래스로 서로다른 객체 3개를 만들기(객체 생성과 소멸시 "객체 생성", "객체 소멸" 문구 출력)
  * 해당 객체의 정보를 출력하는 함수를 차례대로 호출하기

```c++
#include <iostream>

using namespace std;
class Student
{
	/* 멤버변수 추가 */
	/* 멤버함수 추가 */
};
int main(int argc, char const *argv[])
{
	/* 객체 3개 생성 */
	/* 각 객체 정보 출력 */
	return 0;
}
```

5. 해당 코드를 접근지정자를 적절히 사용하여 오류를 수정하여라

```c++
#include <iostream>

using namespace std;
class Rect
{
	int width;
	int height;
	int area;
	Rect(int w,int h)
	{
		width = w;
		height = h;
		area = 0;
	}
	int GetArea() { return area; }
	void SetArea() { area = width * height; }
	void PrintArea() { cout << area << endl; }

};
int main(int argc, char const* argv[])
{
	Rect r(4,3);
	r.SetArea();
	r.PrintArea();

	return 0;
}
```
