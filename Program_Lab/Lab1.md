# 클래스 관련 실습

모든 프로그램은 객체지향 프로그램의 캡슐화(encapsulation)를 반영하여 클래스의 각 멤버에 대한 접근지정자를 지정한 후 멤버함수를 정의하고 ```main()```함수에서 정의한 클래스의 객체(object)를 생성하고 객체의 멤버 함수를 호출하며 검증하시오. (동영상 수업에 한 내용(생성자, 소멸자, 클래스 정의)들을 모두 검증하는 프로그램을 작성하시오.)

1. 실수 x 좌표 값과 y 좌표 값을 가지는 클래스 Point 를 정의하고 각 멤버함수를 구현하시오.([참조](../SampleCodes/Class/simpleClass.cc))



```C++
class Point{
	double x;
	double y;
	double getX();
	double getY();
	Point();
	Point(int x, int y);
	~Point();
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
2. 클래스 ```Date```와 관련한 멤버함수를 구현하시오([참조](../SampleCodes/Class/dateClass.cc)).

```C++
class Date{
	int year;
	int month;
	int day;
	Date()
	Date(int y, int m, int d);
	~Date();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear();
	int getMonth();
	int getDay();
	void printDate();
};


```
3. 클래스 ```Person```과 관련한 멤버 변수와 멤버 함수를 추가하시오. ([참조](../SampleCodes/Class/dateClass.cc)).

```C++
class Person {
	int age;
	Person();
	void setAge(int age);
	int getAge();
};
```
4. [Class Codes](../SampleCodes/Class)의 프로그램 실행하기.

