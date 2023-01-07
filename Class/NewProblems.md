### 1. 해당 프로그램에서 코드를 추가하여 함수 show()를 호출할 시 다음과 같은 결과가 나오도록 하라
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

### 2. 프로그램을 실행 시 다음의 출력 결과가 나오도록 코드를 추가하라

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

### 3. 프로그램 실행 시 다음의 출력 결과가 나오도록 클래스에 코드를 추가하라
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

### 4. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Man이 있다. Man에는 이름과 나이를 저장하는 private 변수 name과 age가 있다.
- public에는 객체 생성 시 전달받은 값으로 name과 age를 초기화하는 생성자가 있다.
- 또한 public에는 name과 age를 반환하는 멤버 함수가 있다.
- 메인 함수에서 Man의 객체 배열을 생성한다. 원소 객체는 3개이며 3개 모두 생성자에 맞게 맴버 변수를 초기화한다.
- 반복문과 멤버 함수를 이용하여 원소 객체들의 멤버 변수 값을 차례로 출력한다.


