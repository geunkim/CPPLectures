#  가상함수 (Virtual fuction)

C++에서 가상 함수는 부모 클래스에서 선언되는 멤버 함수로 자식 클래스에서 재정의할 것을 기대하는 함수로 이 함수를 호출하는 객체의 자료형에 따라 실제 호출할 함수를 결정할 떄 사용된다. 

C++에서 가상 함수는 ```virtual``` 키워드를 아래와 같이 멤버 함수의 원형 앞에 작성하며 선언한다.

```cpp
virtual <멤버 함수의 원형>;
```

부모 클래스에서 ```virtual``` 키워드를 사용하여 가상 함수를 선언하면 자식 클래스에서도 자동으로 가상 함수로 지정되기 떄문에 ```virtual``` 키워드를 사용하지 않아도 된다. 

## 동적 바인딩(Dynamic binding)

C++ 프로그램에서 함수를 호출할 때 컴파일러는 어느 함수를 호출해야 하며 해당 함수 코드가 저장된 정확한 위치도 알아야 한다. 함수를 호출하는 코드와 실행될 함수 코드가 저장된 메모리 주소와의 관계를 저장해 놓은 것을 바인딩(binding)이라 한다. 
다형성 개념을 구현하기 위해서는 바인딩이 정적으로 이루어지면 안된다. 

C++ 프로그램에서 함수를 호출하는 코드는 컴파일 시점에 실행될 함수의 코드가 저장된 고정된 메모리 주소로 변환된다. 이 것을 정적 바인딩(static binding) 또는 초기 바인딩(early binding)이라 한다.
C++ 프로그램에서 가상함수가 아닌 멤버 함수는 정적 바인딩을 한다. 
그러나 C++ 프로그램에서 가상 함수는 프로그램이 실행될 때 대상 객체를 결정하기 때문에 
가상 함수의 호출은 컴파일 시점에 함수 호출 코드를 바인딩 할 수 없다. 
그러므로 가상함수의 호출의 경우 런 타임 시 해당 함수가 실행될 수 있도록 해야 한다.
이 것을 동적 바인딩(dynamic binding) 또는 지연 바인딩(late binding)이라 한다. 

가상 함수도 바인딩하는 자료형이 명확할 경우에는 일반 함수와 같이 정적 바인딩을 한다. 
가상 함수는 부모 클래스의 자료형의 포인터 또는 참조를 통해서 호출하는 경우에 만 동적 바인딩을 한다.

다음은 동적 바인딩을 설명하는 프로그램 예제이다. 

```cpp
#include <iostream>
using namespace std;


class Base {
public:
	virtual void check(){    	// 가상 함수 
		cout << "Base::check()" << endl;
	}
};

class Derived: public Base {	
public:
	void check() {				// 가상 함수
		cout << "Derived::check()" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Base parent, *parentPtr;
	Derived child, *childPtr;

	Base &parentRef = child;

	parent.check();	// 부모 클래스의 멤버 함수 호출
	child.check();	// 자식 클래스의 멤버 함수 호출
	
	parentRef.check(); // 부모 클래스의 참조 변수를 통한 자식 클래스의 멤버 함수 호출

	parentPtr = &parent; 
	parentPtr->check();  // 부모 클래스의 포인터 변수를 통한 부모 클래스의 멤버 함수 호출

	parentPtr = &child; 
	parentPtr->check(); // 부모 클래스의 포인터 변수를 통한 자식 클래스의 멤버 함수 호출 

	childPtr = &child;
	childPtr->check();  // 자식 클래스의 포인터 변수를 통한 자식 클래스의 멤버 함수 호출 


	return 0;
}
```

앞의 코드의 실행 결과는 다음과 같다.
``
Base::check()
Derived::check()
Derived::check()
Base::check()
Derived::check()
Derived::check()
``

다음은 정적 바인딩을 설명하는 프로그램 예제이다. 

```cpp
#include <iostream>
using namespace std;


class Base {
public:
	void check(){    
		cout << "Base::check()" << endl;
	}
};

class Derived: public Base {
public:
	void check() {
		cout << "Derived::check()" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Base parent, *parentPtr;
	Derived child, *childPtr;
	Base &parentRef = child;

	parent.check();	// 부모 클래스의 멤버 함수 호출 
	child.check();	// 자식 클래스의 멤버 함수 호출
	parentRef.check();	// 자식 클래스를 부모 클래스의 참조 변수로 참조하여 부모 클래스의 멤버 함수 호출

	parentPtr = &parent; 
	parentPtr->check();  // 부모 클래스 포인터 변수로 부모 클래스 멤버 함수 호출 

	parentPtr = &child;
	parentPtr->check();  // 자식 클래스를 부모 클래스의 포인터 변수로 참조하여 부모 클래스의 멤버 함수 호출

	childPtr = &child;
	childPtr->check();  // 자식 클래스 포인터 변수를 통해 자식 클래스의 멤버 함수 호출

	return 0;
}
```

앞의 프로그램의 실행 결과는 다음과 같다.

``
Base::check()
Derived::check()
Base::check()
Base::check()
Base::check()
Derived::check()
``




