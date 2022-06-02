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
  
