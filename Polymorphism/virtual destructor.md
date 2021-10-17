 # 가상 소멸자(Virtual Destructor)
 
 소멸자는 객체가 될 때 자동으로 호출되는 클래스의 멤버 함수이다. 객체가 소멸되면 객체에 할당된 메모리는 반환되어야 한다.
 
상속된 클래스가 있는 경우 일반적인 소멸자를 사용하였을때 메모리가 해제되지 않는 현상이 발생하여 메모리 누수가 발생하여 시스템에 부하가 갈 수있다. 
이를 방지하기 위해 상속된 클래스가 있는 경우 가상 소멸자를 사용한다.

가상 소멸자는 ``virtual 소멸자``처럼 기존의 소멸자 앞에 virtual만 붙이면 된다.

아래부터는 가상 소멸자를 쓰는 이유에 관한 프로그램이다.

다음은 일반적인 소멸자 호출을 확인하는 프로그램이다.

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
	~Parent() {
		cout << "Parent 소멸자" << endl;
	}
};

class Child:public Parent {
public:
	~Child(){
		cout << "Child 소멸자" << endl;
	}
};
int main() {
	Child* a = new Child;
	delete a;
}
```
Child 클래스의 a가 동적으로 할당되고 반환된다. 실행 결과는 다음과 같다.

```c++
Child 소멸자
Parent 소멸자
```

그러나 자식 클래스에서 부모 클래스의 포인터를 소멸시킬 때 문제가 발생한다.
다음은 그 문제에 대한 프로그램과 프로그램의 결과이다.

```cpp 
#include <iostream>
using namespace std;

class Parent {
public:
	~Parent() {
		cout << "Parent 소멸자" << endl;
	}
};

class Child :public Parent {
public:
	~Child() {
		cout << "Child 소멸자" << endl;
	}
};

int main() {
	Parent* a = new Child;
	delete a;
}
```

``` Parent 소멸자 ```

이 결과를 봤을 때 부모 클래스만 소멸되고 자식 클래스는 소멸이 되지 않은 모습이다. 그래서 **메모리 누수** 가 발생하게 된다. 메모리 누수가 쌓이게 되면 **시스템에 부하가 갈수 있다.** 이 문제를 해결하기 위해서 부모 클래스의 소멸자가 가상함수가 되어야한다. 부모 클래스의 소멸자 앞에 virtual을 붙이면 자동으로 자식 클래스의 소멸자들은 가상함수가 된다.
다음은 가상 소멸자를 사용한 프로그램이다.

```cpp 
#include <iostream>
using namespace std;

class Parent {
public:
	virtual~Parent() {
		cout << "Parent 소멸자" << endl;
	}
};

class Child :public Parent {
public:
	~Child() {
		cout << "Child 소멸자" << endl;
	}
};

int main() {
	Parent* a = new Child;
	delete a;
}
```
이 프로그램의 결과를 보면 부모 클래스와 자식 클래스가 소멸된 것을 확인할 수 있다.

```c++
Parent 소멸자
Child 소멸자 
```

자식 클래스를 가진 클래스라면 부모 클래스의 소멸자에 virtual을 붙여 가상 소멸자로 만드는 것이 좋다. 소멸자가 가상 함수라면 메모리 누수도 발생하지 않고 손해볼 게 없으나 가상 소멸자가 아니라면 손해볼 것이 많다.  
