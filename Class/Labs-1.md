# 클래스 실습

## Basic Lab

1. 다음 코드를 컴파일 하고 오류가 발생하는지 학인하라. 오류가 발생하면 이유가 분석하라.
```c++
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() = delete;
	int getX() { return x;}
};

int main(int argc, char const *argv[])
{
	Point p1;
	return 0;
}
```

2. 다음 코드를 컴파일하고 오류가 발생하는지 확인하라. 오류가 발생하면 이유가 분석하라



2. 다음 코드를 컴파일하고 오류가 발생하는지 학인하라. 오류가 발생하면 이유가 분석하라.
```c++
#include <iostream>
using namespace std;


class Point {
	int x, y;
public:
	Point(int x, int y) : x{x}, y {y} {}
	void show() {
		cout << x << " , " << y << endl;
	}
};

int main(int argc, char const *argv[])
{
	Point p1(10, 20);
	Point points[10];
	p1.show();
	return 0;
}
```

3. 다음 코드를 컴파일하는 경우 오류가 발생한다. 오류가 발생하는 이유를 분석하라. 오류가 발생하지 않도록 main 함수의 코드를 수정하라.

```c++
#include <iostream>
using namespace std;

class Person {
   string name; 
   int age;      
public:
   Person(string n, int a) : name {n}, age {a} { //파러미터가 있는 생성자
      cout << "Constructor with parameter" << endl;
   }
   explicit Person(const Person &ref) { //복사 생성자
      cout << "User defined Copy constructor" << endl;     
      name = ref.name;
      age = ref.age;
   }
   void show() {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 파러미터가 있는 생성자 호출
   Person kim = {"Chul-soo Kim", 30};   // 파러미터가 있는 생성자 호출

   Person man = hong; // 북사 생성자 호출 (man 객체는 hong 객체의 내용을 복사하여 생성) 
   Person m1 {kim};
   man.show();
   m1.show();

   return 0;
}
```

4. 다음 코드를 컴파일하고 오류가 발생하는지 확인하라. 그 후 main 함수에서 Point 클래스의 객체를 생성하는 코드를 추가한 후 컴파일하여 오류가 발생하는지 확인하고 오류가 발생한다면 이유를 분석하라.

```c++
#include <iostream>
using namespace std;


class Point
{
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

5. 다음 코드를 컴파일하고 발생하는 오류의 이유를 분석하라.

```c++
#include <iostream>
using namespace std;

class Person {
   string name; 
   int age;      
public:
   Person(string n, int a) : name {n}, age {a} { //파러미터가 있는 생성자
      cout << "Constructor with parameter" << endl;
   }
   Person(const Person & p) = delete;

   void show() {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) 
{
   Person hong("Gil-Dong Hong", 28);  // 파러미터가 있는 생성자 호출  
 
   Person man = hong; // 북사 생성자 호출 (man 객체는 hong 객체의 내용을 복사하여 생성) 
  
   return 0;
}
```
