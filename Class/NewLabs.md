#

### 1. 다음 코드에서 클래스 Tree의 객체를 생성하고 메인 함수에서 Tree의 멤버 변수에 값을 저장 후 출력하라
객체의 데이터 구조를 알고, 데이터를 저장 및 활용할 수 있는가?

```c++
#include <iostream>

using namespace std;

class Tree
{
public:
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


### 2. 클래스 Man의 두 멤버 변수를 출력하는 멤버 함수를 구현하고 이를 메인 함수에서 호출하라
클래스 내에서 멤버 변수를 활용하여 멤버 함수를 구현하고 이를 호출할 수 있는가?

```c++
#include <iostream>

using namespace std;

class Man
{
public:
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
	string name = "홍길동";
public:
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
	int num = 100;
public:
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



