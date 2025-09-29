# Class 상속 실습 (1)

1. 다음 코드를 기반으로 요구하는 멤버 함수를 정의하시오. 
```c++

class Base {
  int v1;
protected:
  int v2;
public:
  int v3;
  int getV1();  // 접근자 (accessor)
  int getV2();
  int getV3();
  void setV1(int v);  // 설정자 (mutator)
  void setV2(int v);
  void setV3(int v);
};

class Derived1 : public Base {
  // v1,v2, v3를 직접 접근이 가능한지 코드로 확인
  // Bsse의 접근자, 설정자 호출이 가능한지 확인
  // 이 클래스 독자적인 멤버 변수 및 멤버 함수를 선언 및 정의   
};

class Derived2 : protected Base{
  // v1,v2, v3를 직접 접근이 가능한지 코드로 확인
  // Bsse의 접근자, 설정자 호출이 가능한지 확인
  // 이 클래스 독자적인 멤버 변수 및 멤버 함수를 선언 및 정의   
};

class Derived3 : private Base{
  // v1,v2, v3를 직접 접근이 가능한지 코드로 확인
  // Bsse의 접근자, 설정자 호출이 가능한지 확인
  // 이 클래스 독자적인 멤버 변수 및 멤버 함수를 선언 및 정의     
};

int main(int argc, char cost *argv[]) 
{
  // 클래스 Derived1, Derived2, Derived3의 객체를 생성하는 코드를 생성하고 각 경우 객체가 생성되는지 확인 
  // 객체를 통해 v1, v2, v3를 getV1, getV2, getV3, setV1, setV2, setv3의 함수를 통해서 접근이 가능한지 확인 하시오.  

}
```
2. 정수형, 실수형, 문자형을 저장할 수 있는 배열 클래스 IntegerArr, RealArr, CharArr를 정의하고 main 함수에서 객체를 생성하고 클래스 정의를 검증하시오. 세 개의 클래스의 멤버 변수와 멤버 함수는 같도록 정의하시오. 

3. 각 클래스의 생성자를 통해 멤버변수를 초기화하고 접근자와 설정자 함수를 선언하고 정의한 후 main 함수에서 각 클래스의 객체를 생성하여 객체의 구현을 검증하시오. 
**(자식 클래스 생성 시 자식 클래스의 멤버 변수와 부모 클래스의 멤버 변수를 초기화한다. t-> turbo, s-> speed)**
  
  - 자식 클래스의 멤버 변수 초기화 시 초기화 리스트를 활용해 보기
  - 자식 클래스의 멤버 변수 초기화 시 초기화 리스트를 활용하지 않기 

```c++
#include <iostream>
using namespace std;

class Car
{ 
  int speed;
public:
  Car(int s);
  // 메소드 추가 
};

class SportCar : public Car
{
  bool turbo;
public:
  SportCar(int s, bool t);
  // 메소드 추가
};

int main(int argc, char const *argv[])
{

  return 0;
}
```

4. 두 개의 클래스를 간결하게 하나의 클래스로 다시 작성하고 main 함수에서 테스트하시오.

```c++
class TwoDimension
{
  double x, y;
public:
  TwoDimension(double i, double j);
};

class ThreeDimension
{
  double x, y, z;
public:
  ThreeDimension(double i, double j, double k);
};
```

5. 다음 클래스들을 구현하고 main 함수에서 각 객체를 생성하고 검증하시오.

```c++
#include <iostream>
#include <string>
using namespace std;

class Person{
  stirng name;
  string address;
  string tel;
public:
  Person();
  ~Person();
  // 메소드 추가
};

class Professor : public Person
{
public:
  Professor();
  ~Professor();
  void teach();
};

class TennisPlayer : public Person
{
public:
  TennisPlayer();
  ~TennisPlayer();
  void playTennis();
};

class Businessman : public Person
{
public:
  Businessman();
  ~Businessman();
  void runBusiness();
};
```
5. 다음의 코드에서 컴파일 에러가 발생하는 부분을 확인하고 컴파일이 발생하는 부분의 코드를 수정하시오.

```c++
class Base{
	int a;
protected:
	int b;
public:
	Base() { cout << "Base(1)" << endl; }
	Base(int i, int j) : a(i), b(j) { cout << "Base(2)" << endl; }
	void setTwoData(int k, int l) { a = k; b = l;}
	void setA(int i) { a = i;}
	void setB(int j) { b = j;}
	int getDataA() {return a;}
	int getDataB() {return b;} 
};

class Derived : public Base 
{
	int c;
public:
	Derived(int k) : c(k) {}
	Derived(int i, int j, int k) : Base(i, j), c(k) {}
	void setThreeData(int i, int j, int k) {a = i, b = j, c = k;}
	void printAll() {cout << "a: " << a <<", b:" << b << ",c: " << c << endl; } 
};

int main(int argc, char const *argv[])
{
	Derived child1(50);
	Derived child2(1, 2, 3);
	child1.setThreeData(10, 20, 30);
	child1.printAll();
	child2.printAll();

	return 0;
}
```
