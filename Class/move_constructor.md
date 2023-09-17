## 이동 생성자 (move constructor)

이동 생성자는 객체의 멤버 변수의 값을 복사하는 것이 아니라 기존 객체의 데이터 소유권을 새 변수에 이동하는 특수한 멤버 함수이다. 
이동 생성자는 커다란 객체를 전달할 때 프로그램의 효율성을 높일 수 있다. 
이동 생성자 매개 변수는 **rvalue** 참조를 사용하고 매개 변수에는 기본 값이 저장되어 있어야 한다.
이동 생성자를 사용하면 **rvalue** 객체가 소유한 자원을 복사하지 않고 **lvalue**로 이동할 수 있다. 

이동 생성자의 구문은 다음과 같다.

```c++
<클래스 이름>(<클래스 이름>&& <변수 이름>);
```
앞에서 살펴본 Point 클래스 또는 Person 클래스에 대한 이동 생성자의 원형은 다음과 같다.

```c++
Point(Point&& point);
Person(Person&& person);
```

컴파일러는 객체가 동일한 자료형의 다른 객체에 의해 초기화되고 다른 객체를 제거되고 더 이상 자원이 필요하지 않은 경우 이동 생성자를 선택한다.

클래스가 이동 생성자를 정의하지 않으면 컴파일러는 사용자가 정의한 복사 생성자, 복사 할당 연산자, 이동 할딩 연산자 또는 소멸자가 없는 경우 암시적 생성자를 생성한다.
명시적 또는 암시적 이동 생성자가 정의되어 있지 않으면 이동 생성자를 사용하는 작업은 복사 생성자를 대신 사용한다. 
클래스가 이동 생성자 또는 이동 할당 연산자를 선언한 경우 암시적으로 선언된 복사 생성자는 삭제된 것으로 정의한다. 

### 이동 생성자가 호출되는 시점

* 함수의 반환 값이 전달 될 때
* 저장 공간의 소유권을 이동시키고자 할 때

```c++
#include <iostream>
using namespace std;


class Person{
    string name;
    int age;
public:
    Person(string n, int a) : name {n}, age{a} {}
    Person(const Person& other);
    Person(Person&& other);
    void show() {
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
    Person man {lee};            // 복사 생성자 호출
    Person m1 {std::move(lee)};  // 이동 생성자 사용

    lee.show();
    m1.show();
    return 0;
}
```
앞의 코드의 실행 결과는 다음과 같다. ```lee``` 객체에 저장된 값을 확인하면 string 클래스의 객체 name의 소유권이 ```m1```으로 이동되어 
이름 값이 출력되지 않았고 m1의 내용을 출력하면 "Chul-Soo Lee" 가 출력되었다.

```bash
copy constructor
move constructor
, 20
Chul-Soo Lee, 20
```

