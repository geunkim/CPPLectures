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

2. 다음 코드를 컴파일하고 오류가 발생하는지 확인하라. 
```c++
#include <iostream>

using namespace std;

class Point 
{
	int x, y;
	Point(int a, int b) : x{a}, y{b} {}
public:
	void show(){
	  cout << x << ", " << y << endl;
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}
```
3. 2번의 프로그램의 main 함수에서 Point 클래스에서 선언된 생성자를 이용하여 객체를 생성하는 코드를 추가하고 컴파일을 하였을 때 오류가 발생하는지 확인하라. 오류가 발생하면 이유를 분석하라.

4. 2의 프로그램 코드에서 Point클래스의 형태를 변경하지 않고 새로운 멤버 함수를 통해 객체를 생성할 수 있는 멤버 함수를 선언/정의하여 객체를 생성할 수 있는 클래스를 생성하라. (Advance한 개념으로 가능한 학생만 시도하기 바람: 힌트 정적 멤버 함수를 사용하여야 함)

5. 다음 코드를 컴파일하고 오류가 발생하는지 학인하라. 오류가 발생하면 이유를 분석하라.
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

6. 다음 코드를 컴파일하는 경우 오류가 발생한다. 오류가 발생하는 이유를 분석하라. 오류가 발생하지 않도록 main 함수의 코드를 수정하라.

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
7. 다음 코드를 컴파일하고 발생하는 오류의 이유를 분석하라.

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

8. 다음의 코드를 컴파일하고 발생하는 오류의 이유를 분석하고 main() 함수의 내용을 수정하라.

```C++
#include <iostream>
using namespace std;

class Rect {
private:
    int width, height;

public:
    Rect(int w, int h) : width(w), height(h) {}

    // friend 함수 선언
    friend int getArea(const Rect& r);
};

// friend 함수 정의
int getArea(const Rect& r) {
    // private 멤버 접근 가능
    return r.width * r.height;
}

int main() {
    Rect r1(3, 4);
    cout << "넓이: " << r1.getArea(r1) << endl;  // 12 출력
    return 0;
}
```

9. (1) 다음의 코드를 컴파일하고 실행하여 보고 ``friend class`` 의 의미를 확인하고 캡슐화를 보장하는지 검토하라.
   그 후(2) Engine class의 ``friend class Car`` 줄을 제거하고 Car의 showspec() 멈버 함수에서 앞의 경우와 같이 출력이 되도록 Engine Class의 정의를 수정하라.
   (3) Engine 객체가 생성되는지 확인을 하고 한다면 Car의 객체보다 먼저 생성되는지 나중에 생성되는지 확인하는 코드를 추가해서 실행 결과를 기반으로 추론하라.

```C++
#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    // Car 클래스가 Engine의 private 멤버에 접근할 수 있음
    friend class Car;
};

class Car {
private:
    Engine engine;

public:
    Car(int hp) : engine(hp) {}

    void showSpec() {
        // Engine의 private 멤버 horsepower 접근 가능
        cout << "엔진 출력: " << engine.horsepower << " 마력" << endl;
    }
};

int main() {
    Car c1(200);
    c1.showSpec();  // "엔진 출력: 200 마력"
    return 0;
}
```
10. 다음 코드를 실행하고 복사 생성자, 이동 생성자의 차이에 대해서 코드를 분석 결과 또는 코드를 더 추가하여 확인을 하라.
    복사 생성자와 이동 생성자의 프로토타입의 차이가 있는지 확인하라. 차이가 있다면 어떻게 차이가 있는지 기술하라.
    코드의 (1), (2), (3)의 어떠한 생성자를 호출하는지 확인하라. 

```C++
#include <iostream>
#include <utility>  // std::move
using namespace std;

class MyVector {
private:
    int* data;
    size_t size;

public:
    // 생성자
    MyVector(size_t n) : size(n) {
        data = new int[n];
        cout << "Constructor: allocate " << size << " ints" << endl;
    }

    // 소멸자
    ~MyVector() {
        delete[] data;
        std::cout << "Destructor: release" << endl;;
    }

    // 복사 생성자
    MyVector(const MyVector& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }

    // 이동 생성자
    MyVector(MyVector&& other) noexcept : data(nullptr), size(0) {
        // 자원 소유권 이전
        data = other.data;
        size = other.size;

        // 원본은 nullptr 상태로 초기화
        other.data = nullptr;
        other.size = 0;
    }

    // 디버그용 출력
    void print() const {
        std::cout << "Vector size: " << size << ", data: " << (void*)data << "\n";
    }
};

int main() {
    MyVector v1(5);      // (1)
    MyVector v2 = v1;    // (2)
    MyVector v3 = std::move(v1);  // (3)

    std::cout << "v1: "; v1.print();
    std::cout << "v2: "; v2.print();
    std::cout << "v3: "; v3.print();

    return 0;
}
```
