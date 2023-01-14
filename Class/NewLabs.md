#

### 1. 다음 코드에서 구조체 Tree의 객체를 생성하고 메인 함수에서 Tree의 멤버 변수에 값을 저장 후 출력하라
객체의 데이터 구조를 알고, 데이터를 저장 및 활용할 수 있는가?

```c++
#include <iostream>

using namespace std;

struct Tree
{
	string name;
	int leaf;
};

int main(int argc, const char* argv[])
{
	// 코드 작성 

	return 0;
}
```
#


### 2. 구조체 Man의 두 멤버 변수를 출력하는 멤버 함수를 구현하고 이를 메인 함수에서 호출하라
클래스 내에서 멤버 변수를 활용하여 멤버 함수를 구현하고 이를 호출할 수 있는가?

```c++
#include <iostream>

using namespace std;

struct Man
{
	string name = "홍길동";
	int age = 24;
	void show()
	{
		// 코드 작성
	}
};

int main(int argc, const char* argv[])
{
	// 코드 작성

	return 0;
}
```



#

### 3. 클래스 Man의 멤버 변수를 멤버 함수를 통해 메인 함수에서 출력하라
클래스의 데이터를 저장하는 멤버 변수는 일반적으로 private 접근 지정자를 통해 클래스 외부에서 접근(사용)할 수 없도록 한다. 이러한 상황에서
멤버 변수에 접근하는 다른 방법을 사용할 수 있는지?

```c++
#include <iostream>

using namespace std;

class Man
{
	string name = "홍길동";
	int age = 24;
public:
	// 멤버 함수 구현
};

int main(int argc, const char* argv[])
{
	// 코드 작성

	return 0;
}
```

#

### 4. 메인 함수에서 클래스 Man의 멤버 변수 age에 값을 저장하려고 한다. age에 값을 저장하고 이를 출력하는 멤버 함수들을 구현한 후 메인 함수에서 활용하라
기존의 함수 관련 지식을 응용하여 클래스에 적용할 수 있는가?

```c++
#include <iostream>

using namespace std;

class Man
{
	string name = "홍길동";
	int age;
public:
	// 멤버 함수 구현
};

int main(int argc, const char* argv[])
{
	// 코드 작성

	return 0;
}
```

#

### 5. 4번 문제를 응용. 클래스 Man에서 두 개의 객체 a, b를 생성하고, 각 객체의 멤버 변수가 서로 다른 값을 가지도록 한다. 그 후 a와 b의 멤버 변수를 출력하고 확인 후 대입 연산자를 이용하여 b의 멤버 변수가 a의 멤버 변수 값을 가지도록 복사 대입 후 이를 출력하여 확인하라

같은 클래스의 객체들 간 복사 대입을 수행할 수 있는가

#

### 6. 다음 코드의 출력 결과를 예측하라
생성자와 소멸자의 실행 시점을 이해하고 있는지
```c++
#include <iostream>

using namespace std;

class Man
{
public:
	Man() { cout << "Constructor execute" << endl; }
	~Man() { cout << "Destructor execute" << endl; }
};

int main(int argc, const char* argv[])
{
	Man a;

	{
		Man b;
	}

	Man c;

	return 0;
}
```

#

### 7. 다음 코드는 컴파일 에러가 발생한다. 에러의 원인을 추론하고 다양한 방법을 이용해 클래스를 수정하여 해결하라
생성자의 동작을 이해하고 있는지
```c++
#include <iostream>

using namespace std;

class Man
{
	string name = "홍길동";
	int age;
public:
	Man(int);
};

Man::Man(int age)
{
	
}


int main(int argc, const char* argv[])
{
	Man man;

	return 0;
}
```

#

### 8. 6번의 문제에서 생성자를 통해 age의 값을 10으로 초기화 후 이를 확인하는 코드를 작성하라
생성자를 통해 객체를 초기화할 수 있는지

#

### 9. 클래스 Man의 두 생성자가 주석문과 같은 기능을 한다고 가정할 때, 두 생성자의 기능을 하나로 합친 하나의 생성자를 구현하고 확인하라.

```c++
#include <iostream>

using namespace std;

class Man
{
	string name = "홍길동";
	int age;
public:
	Man() 
	{  
		// age를 10으로 초기화하는 코드
	}
	Man(int age) 
	{ 
		// 입력받은 값으로 age를 초기화하는 코드
	}
	int getAge()
	{
		// age 반환
	}
};


int main(int argc, const char* argv[])
{


	return 0;
}
```

#

### 10. 해당 프로그램에서 코드를 추가하여 함수 show()를 호출할 시 다음과 같은 결과가 나오도록 하라
(단, 접근 지정자의 범위를 수정하지 않으며 '홍길동'과 '10'은 각 클래스의 멤버 변수로 출력한다.)

출력 결과
```
홍길동 has 10 books
```

```c++
#include <iostream>

using namespace std;

class Man
{
	string name;
public:
	Man() { name = "홍길동"; }
	void show(int);
};

void Man::show(int book)
{

}

class Book
{
	int num = 10;
public:

};

int main(int argc, const char* argv[])
{


	return 0;
}
```

#

### 11. 프로그램을 실행 시 다음의 출력 결과가 나오도록 코드를 추가하라

출력 결과
```c++
10
10
```

```c++
#include <iostream>

using namespace std;

class A
{
	int num;
public:
	A() { num = 100; }
	void setNum(int num) { this->num = num; }
	int getNum() { return num; }
};

class B
{
	A a;
public:
	// 코드 작성
};

int main(int argc, const char* argv[])
{
	B b;
	cout << b.getA_num() << endl;
	
	A a;
	a = b.getA();

	cout << a.getNum() << endl;

	return 0;
}
```

#

### 12. 프로그램 실행 시 다음의 출력 결과가 나오도록 클래스에 코드를 추가하라
```c++
A is older
```

```c++
#include <iostream>

using namespace std;

class Man
{
	string name;
	int age;
public:
	Man(string name, int age) {
		this->name = name;
		this->age = age;
	}
        // 코드 작성
};

int main(int argc, const char* argv[])
{
	Man a("A", 20);
	Man b("B", 10);

	cout << a.older(a, b) << " is older" << endl;
		 
	return 0;
}
```

#

### 13. 다음 프로그램을 실행하면 컴파일 에러가 발생한다. 에러를 해결할 수 있는 한 줄의 코드를 작성하라.
정적 멤버를 사용하기 위한 조건을 알고 있는지
```c++
#include <iostream>

using namespace std;

class Player
{
	static int playerNum;
public:
	static int getPlayerNum() { return playerNum; }
};

int main(int argc, const char* argv[])
{
	Player a, b;

	cout << a.getPlayerNum() << endl;

	return 0;
}
```

#

### 14. 다음 프로그램에서 main 함수에서 에러가 발생하지 않도록 클래스 멤버 함수 getTreeNum()을 적절히 수정하라. 수정 후 정적 멤버의 특징을 추론하라
정적 멤버의 특징을 이해하고 있는가

```c++
#include <iostream>

using namespace std;

class Tree
{
	static int treeNum;
public:
	Tree(int leaf)
	{
		treeNum++;
	}
	int getTreeNum()
	{
		return treeNum;
	}
};

int Tree::treeNum = 0;

int main(int argc, const char* argv[])
{
	cout << Tree::getTreeNum() << endl;

	Tree a(10), b(20);

	cout << Tree::getTreeNum() << endl;

	return 0;
}
```

#

### 15. 다음 프로그램에서 에러가 발생하지 않도록 클래스 Man을 수정하라.
프렌드 함수의 역할을 이해하고 있는지
```c++
#include <iostream>

using namespace std;

class Man {
	int money;
public:
	Man(int money) { this->money = money; }
	bool rich(Man a, Man b);         
};

bool rich(Man a, Man b) {                       
	if (a.money > b.money) return true;     
	else return false;                     
}

int main(int argc, const char* argv[]) {

	Man Jinho(100);
	Man Donghun(200);

	if (rich(Jinho, Donghun)) cout << "rich : Jinho" << endl; 
	else cout << "rich : Donghun" << endl;                 

	return 0;
}
```

#

### 16. 다음 프로그램에서 에러가 발생하지 않도록 수정하라. 단, 코드의 추가만 허용되며 순서 변경, 기존 코드의 수정은 하지 않는다.
다른 클래스의 멤버 함수를 프렌드로 활용할 수 있는지
```c++
#include <iostream>

using namespace std;

class Man;

class MantoMan {
public:
	bool fight(Man a, Man b);
};

class Man {
	int power;
public:
	Man(int power) { this->power = power; }
};

bool MantoMan::fight(Man a, Man b) { 
	if (a.power > b.power) return true;
	else return false;
}


int main(int argc, const char* argv[]) {

	Man Donghun(50);
	Man Jinho(1000);
	MantoMan a;

	if (a.fight(Donghun, Jinho) == 1) cout << "Donghun Win" << endl;
	else cout << "Jinho Win" << endl;

	return 0;
}
```

