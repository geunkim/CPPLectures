# 클래스 실습

## Basic Lab

1. 다음 코드를 컴파일하고 오류가 발생하는지 확인하라. 그 후 main 함수에서 Point 클래스의 객체를 생성하는 코드를 추가한 후 컴파일하여 오류가 발생하는지 확인하고 오류가 발생한다면 이유를 분석하라.

```c++
#include <iostream>
using namespace std;


class Point {
	int x, y;
	Point() {};
public:
	int getX() { return x;}
};

int main(int argc, char const *argv[])
{
	return 0;
}
```
2. 다음 코드를 무엇을 하는 것인지 분석하고 생성자가 무엇이며 프로그램을 실행하고 결과를 분석하고 클래스에 멤버 함수를 추가하고 검증하라.

```c++
#include <iostream>
using namespace std;

class Box
{
	int height;
	int width;
public:
	Box(int h = 3, int w = 5);
	int area();	
};
Box::Box(int h, int w)
{
	height = h;
	width = w;
}

int Box::area()
{
	return height * width;
}


int main(int argc, char const *argv[])
{
	Box b;
	Box c(3, 4);
	Box d(2);

	cout << b.area() << endl;
	cout << c.area() << endl;
	cout << d.area() << endl;

	return 0;
}
```

3. 다음 클래스 Person 클래를 구현하고 main 함수에서 Person 클래스의 객체를 생성하며 데이터가 저장되는 것을 확인할 수 있는 프로그램을 작성하라.

   (1) 멤버 변수는 외부에서 접근이 불가능하도록 멤버 함수는 외부에서 접근이 가능하도록 접근 지정자 설정
   
   (2) 멤버 함수를 구현
   
   (3) main 함수에서 Person 클래스의 객체 두 개 이상을 선언하고 클래스의 멤버함수를 통해 클래스의 값이 변경됨을 확인
   
   (4) 객체 간의 대입 연산자의 동작을 확인

```c++
class Person {
	int age;  // 클래스의 멤버 변수 
	void setAge(int age);  // 외부에서 나이에 해당하는 값을 변수 age로 전달받아 클래스의 멤버 변수에 저장 (멤버 함수)
	int getAge();          // 클래스의 멤버 변수 age의 값을 반환 (멤버 함수)
	/* 멤버 변수와 멤버 함수를 추가하시오 */
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
```
4. 3번의 Person 클래스에 생성자를 추가하시요. 생성자 함수를 통해 객체가 생성될 때 입력 파러미터를 전달받아 입력 파러미터 값이 멤버변수 age의 값으로 저정되도록 
   생성자를 추가하라. 

5. 4번의 생성자는 default parameter 값을 20으로 를 가지며 값을 전달받지 않는 경우 20이 age에 저장되도록 생성자를 수정하라.

6. 다음 프로그램의 생성자와 멤버함수를 구현하고 화면에 다음과 같이 출력이 이루어 지도록 프로그램을 작성하라.
```bash
  num: 100 (객체의  num에 저장된 값)
  gas: 200.5  (객체의 gas에 저장된 값)
```

```c++
#include <iostream>
using namespace std;

class Car
{
	int num;
	double gas;
public:
	Car(int n, double g);
	int getNum(); // 인라인 멤버함수
	double getGas(); // 인라인 멤버함수
	void show();  // num 값과 gas 값을 화면에 출력하는 멤버 함수 
};

// 생성자 
Car::Car(int n, double g) {}. // n의 값을 num에 g의 값을 gas에 저장하는 생성자

int Car::getNum() { }  // num 값 반환

double Car::getGas() { } // gas 값 반환

void Car::show() { }  // num 값과 gas 값을 화면에 출력 

int main(int argc, char const *argv[])
{
	Car h(100, 200.5);
	h.show();
	return 0;
}
```

7. 다음 프로그램의 생성자와 소멸자의 호출 시점을 추론해 보고 실행한 결과와 같은지 확인하고 분석 결과를 기술하라. 

```c++

class Obj {
	int num;
public:
	Obj(int num) {    // 생성자
		this-> num = num;
		cout << num << ":  Obj Constructor" << endl;
	}
	~Obj(){   // 소멸자
		cout << num << ":  Obj Destructor" << endl;
	}

};

int main(int argc, char const *argv[])
{
	cout << "main start" << endl;
	Obj a(1);
	{
		Obj b(2);
	}
	Obj c(3);
	cout << "main end" << endl;
	
	return 0;
}
```
8. 다음 코드에서 객체가 몇 개가 생성되고 어떤 순서로 생성되고 삭제되는지 추론하고 코드를 추가하여 확인하라.
```c++
#include <iostream>
using namespace std;

class Tower
{
	int height;
public:
	Tower(int h = 10) : height(h) {}
}

void f()
{
	Tower a(20);
}

Tower b, c(30);

int main(int argc, char const *argv[])
{
	f();
	Tower d(40);
	return 0;
}
```
## Advanced Lab.

9. 1번 코드의 기본 생성자의 접근 권한을 변경하지 않고 외부에서 Point 객체를 생성할 수 있도록 Point 클래스 정의에 기능을 추가하고 객체가 생성됨을 확인하는 코드를 작성하라. (힌트 

11. 일상생활을 객체를 클래스로 정의하고 멤버함수를 추가하고 확인하라.
