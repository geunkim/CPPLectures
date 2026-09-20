## 이동 생성자 (move constructor)

기존 객체를 이용해 새 객체를 초기화할 때, 기존 객체가 소유한 자원을 복사하는 대신 새 객체로 옮길 수 있는 생성자이다. 동적 메모리처럼 복사 비용이 큰 자원에서는 복사를 줄이는 데 도움이 된다. 다만 모든 멤버가 옮겨지는 것은 아니다. 이 자료의 예제에서 `std::string` 멤버는 이동 초기화되고 `int` 멤버의 값은 복사된다.
이동 생성자 일반적으로 같은 클래스의 **오른값 참조(rvalue)(&&)** 를 매개변수로 받는다. 매개변수에 기본값을 지정할 필요는 없다.

이동 생성자의 구문은 다음과 같다.

```c++
<클래스 이름>(<클래스 이름>&& <변수 이름>);
```
앞에서 살펴본 Point 클래스 또는 Person 클래스에 대한 이동 생성자의 원형은 다음과 같다.

```c++
Point(Point&& point);
Person(Person&& person);
```

새 객체를 오른값으로 초기화하고 사용할 수 있는 이동 생성자가 있으면 이동 생성자가 선택될 수 있다. `std::move`는 객체를 직접 이동시키는 함수가 아니라, 이동 생성자를 선택할 수 있도록 객체를 오른값으로 취급하게 하는 표현이다.

복사 생성자, 복사 할당 연산자, 이동 할당 연산자 또는 소멸자를 사용자가 선언한 클래스에는 이동 생성자가 암시적으로 선언되지 않는다. 사용 가능한 이동 생성자가 없다면, 복사 생성자가 선택되어 복사가 일어날 수도 있다. 이동 생성자나 이동 할당 연산자를 사용자가 선언하면 암시적으로 선언되는 복사 생성자는 삭제된 함수가 될 수 있으므로, 필요한 복사 동작은 별도로 확인해야 한다.

이동 생성자는 오른값을 이용한 새 객체의 초기화에서 사용될 수 있다. 함수 반환에서는 복사 생략이 적용되어 이동 생성자도 복사 생성자도 호출되지 않을 수 있다.

### 이동 생성자가 호출되는 시점

* 함수의 반환 값이 전달 될 때
* 저장 공간의 소유권을 이동시키고자 할 때

```c++
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Person{
    string name;
    int age;
public:
    Person(string n, int a) : name {n}, age{a} {}
    Person(const Person& other);
    Person(Person&& other);
    void show() const {
      cout << name << ", " << age << endl;
   }
};

Person::Person(const Person& other) : name{ other.name }, age {other.age } 
{
    cout << "copy constructor" << endl;
}

Person::Person(Person&& other) : name {std::move(other.name)}, age {other.age} 
{
    cout << "move constructor" << endl;
}

int main(int argc, char const *argv[])
{
    Person lee("Chul-Soo Lee", 20);
    Person man{lee};            // 복사 생성자 호출
    Person m1{std::move(lee)};  // 이동 생성자 사용

    lee.show();
    m1.show();
    return 0;
}
```
앞의 코드의 실행 결과는 다음과 같다. `lee` 객체에 저장된 값을 확인하면 string 클래스의 객체 name의 소유권이 `m1`으로 이동되어 
이름 값이 출력되지 않았고 m1의 내용을 출력하면 "Chul-Soo Lee" 가 출력되었다.

```bash
copy constructor
move constructor
, 20
Chul-Soo Lee, 20
```
`man`은 `lee`에서 복사하여 생성하고, `m1`은 `std::move(lee)`를 사용하여 이동 생성자로 생성한다. 이동 생성자에서 `name`은 이동 초기화되고 `age` 값은 복사된다. 이동 후 `lee`는 여전히 유효한 객체이지만, `lee.name`이 빈 문자열이라고 가정해서는 안 된다. 값을 다시 지정하거나 객체의 수명이 끝나도록 둘 수 있다.
