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


#

### 5. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Data는 멤버 변수로 10개의 원소를 가질 수 있는 정수형 배열 val을 가지고 있다.
- 멤버 함수 init()은 val 내부의 원소를 모두 0으로 초기화한다. Data의 객체가 생성될 경우 자동으로 init()이 실행되어야 한다.
- 멤버 함수 insert()는 입력받은 정수를 val의 맨 처음 인덱스부터 차례대로 저장한다. (힌트 : 인덱스에 이미 0이 아닌 값이 저장되어 있다면, 다음 인덱스에 값을 저장한다.)
- 멤버 함수 show()는 val의 모든 원소를 출력한다.
- 이와 같이 클래스를 구현한 후, 메인 함수에서 객체를 생성하고 올바르게 동작하는지 테스트한다.


#

### 6. 5번의 프로그램에서 다음을 추가하라
- 객체를 생성 시 입력한 정수만큼의 배열이 생성되도록 할 것
- 만약 배열이 가득 찬 상태에서 insert()를 실행할 시, 기존 배열의 두 배 크기를 갖는 새로운 배열을 할당 후 그곳에 기존의 값을 모두 복사할 것, 새로 할당된 배열은 클래스의 멤버 변수로써 유효해야 한다.
- 입력받은 정수에 해당하는 배열의 인덱스 값을 다시 0으로 만드는 deleteData()함수를 구현할 것. 이때, 0이 된 원소 뒤에 원소가 존재할 경우, 모두 앞으로 한 칸씩 이동할 것.


