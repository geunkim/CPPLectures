# 상속(Inheritance)

1. 부모 클래스를 아래와 같이 protected, private, public로 상속 받았을 때 부모클래스의 멤버 변수의 접근을 하기 위한 방법이 있는지 있다면 무엇인지 정리하시오. 

```cpp
class Derived : protected Base;
class Derived : private Base;
class Derived : public Base:
```

```cpp
class Base {
	int v1;
protected:
	int v2;
public:
	int v3;
};

class Derived:         Base
{

};

int main(int argc, char const *argv[]){
	/* code */
	return 0;
}
```

2. 다음 클래스들을 구현하고 main() 함수에서 각 객체를 생성하고 검증하시오.

```cpp
class Person
{
	string names;
	string address;
	string tel;
public:
	Person();
	~Person();
	
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

int main(int argc, char const *argv[])
{
	/* code */

	return 0;
}
```

3. 상속을 이용하여 다음 두 개의 클래스를 간결하게 다시 작성하고 main() 함수에서 검증하시오.

```cpp
class TwoDimension {
	double x, y;
public:
	TwoDimension(double i, double j);
};

class ThreeDimesion {
	double x, y, z;
public:
	ThreeDimension(double i, double j, double k);
};
```

4. 각 클래스의 생성자를 통해 멤버변수를 초기화하고 접근자(accessor)와 설정자(mutator) 함수를 선언하고 정의한 후 main() 함수에서 각 클래스의 객체를 생성하여 객체의 구현을 검증하시오.

* 멤버 변수 초기화 시 초기화 리스트를 활용하지 않고 구현
* 멤버 변수 초기화 시 초기화 리스트를 활용하기 

```cpp
{
	int speed;
public:
	Car (int s);
};

class SportCar: public Car
{
	bool turbo;
public:
	SportCar(int s, bool t);
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
```

5. 다음 클래스의 bark() 멤버함수를 다르게 정의하고 main()함수에서 각 클래스의 객체를 생성하여 클래스의 오버라이딩(overridng)을 확인하시오. 


```cpp
class Animal
{
public:
	void bark();	
};

class Dog : public Animal
{
public:
	void bark();	
};

class Cat : public Animal
{
public:
	void bark();	
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

```

6. 육면체 ``Box`` 클래스를 정의하시오.
  * 멤버 변수: length, width, height (모두 실수)
  * 생성자 
  	- 각 값이 주어지면 주어진 값으로 초기화
  	- 값이 주어지지 않으면 0으로 초기화
  * getVolume() 멤버함수 정의
  	- 부피를 구하여 반환

7. GitHub의  ``\SampleCodes\Inheritance``에 상속과 관련하여 클래스 오버라이딩을 활용하는 부모 클래스와 자식 클래스를 정의하고 검증하는 프로그램을 1개 이상 작성하시오. 

  