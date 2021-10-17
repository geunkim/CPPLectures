# 가상 소멸자

다음과 같이 ```Base``` 클래스와 ```Derived``` 클래스가 정의되었다. 

```C++
#include <iostream>

using namespace std;

// 가상 소멸자 

class Base{
public:
	Base() {cout << "base constructor" << endl;}
	~Base() {cout << "base destructor" << endl;}
};

class Derived : public Base {
public:
	Derived() {cout << "derived constructor" << endl;}
	~Derived() {cout << "derived destructor" << endl;}
};
```

다음과 같이 ```Derived``` 클래스의 객체를 생성하였다.
```C++
int main(int argc, char const *argv[])
{
  
	Derived c;
	return 0;
}
```
```Derived``` 클래스의 객체 c가 생성 및 소멸될 때 호출되는 생성자와 소멸자는 다음과 같다.

```c++
base constructor
derived constructor
derived destructor
base destructor
```

다음과 같이 다형상을 적용하기 위해서 ```Derived``` 클래스의 객체를 동적으로 활당한 후 Base 클래스의 포인터 변수에 대입 후 Base 클래스의 포인터 변수에 활당된 
메모리 공간을 해지할 경우 호출되는 생성자와 소멸자는 다음과 같다. 

```C++
int main(int argc, char const *argv[])
{
  
	Base *p = new Derived();
  delete p;
  
	return 0;
}
```

```C++
base constructor
derived constructor
base destructor
```
이 경우 ```Derived``` 클래스의 소멸자는 호출이 되지 않음을 확인했다. 
```Derived```클래스에서 동적으로 메모리를 할당한 경우 이를 해지할 수 없다. 
이러한 문제를 해결하기 위해서 ```Base``` 클래스의 소멸자를 가상 소멸자로 선언을 하면 ```Derived``` 클래스의 소멸자가 호출된다.

```c++
class Base{
public:
	Base() {cout << "base constructor" << endl;}
	virtual ~Base() {cout << "base destructor" << endl;}
};
```
```C++
int main(int argc, char const *argv[])
{
  
	Base *p = new Derived();
  delete p;
  
	return 0;
}
```
```Base``` 클래스의 소멸자를 가상 소멸자로 선언하고 다음의 ```main```함수의 실행하면 생성자와 소멸자의 호출 순서는 다음과 같다.   

```C++
base constructor
derived constructor
derived destructor
base destructor
```
