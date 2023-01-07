#

### 1. 다음 코드에서 클래스 Tree의 객체를 생성하고 메인 함수에서 Tree의 멤버 변수에 값을 저장 후 출력하라
객체의 데이터 구조를 알고, 객체에 데이터를 저장 및 활용할 수 있는가?

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

### 5. 4번의 문제를 응용. 클래스 Man에서 두 개의 객체 a, b를 생성하고, 각 객체의 멤버 변수가 서로 다른 값을 가지도록 한다. 그 후 a와 b의 멤버 변수를 출력하고 확인 후 대입 연산자를 이용하여 b의 멤버 변수가 a의 멤버 변수 값을 가지도록 복사 대입 후 이를 출력하여 확인하라

같은 클래스의 객체들 간 복사 대입을 수행할 수 있는가
