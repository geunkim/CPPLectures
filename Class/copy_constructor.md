# 복사 생성자(Copy Constructor)

복사 생성자는 같은 클래스의 기존 객체를 이용해 **새 객체를 초기화하는 생성자**이다. 컴파일러가 제공하는 복사 생성자는 객체의 각 멤버를 복사한다.
멤버가 값을 직접 저장하거나 `std::string`처럼 복사를 스스로 처리하는 자료형이라면, 일반적으로 복사 생성자를 직접 정의할 필요가 없다.
클래스의 멤버 변수가 값을 저장하는 간단한 행태라면 컴파일러에서 생성하는 복사 생성자로 충분하여 사용자가 직접 복사 생성자를 정의할 필요는 없으나 객체 복사 시 복잡한 초기화가 필요한 경우에는 사용자 정의 복사 생성자를 정의하여야 한다. 

클래스가 동적 메모리를 직접 소유하고, 복잡한 객체에도 독립적인 메모리가 필요하다면 복사 생성자에서 새 메모리를 할당하고 원본 데이터를 복사해야 한다.
**포인터 멤버가 있다는 사실만으로 반드시 직접 정의해야 하는 것은 아니다**. 그 포인터가 메모리를 소유하는지가 중요하다.
예로 클래스 멤버 변수에 포인터 변수가 있고 포인터 변수로 참조하는 저장 공간을 새롭게 할당하여야 하는 경우 복사 생성자를 사용자가 정의하여 메모리를 동적 할당하고 포인터 변수가 할당된 메모리를 가리키도록 하여야 한다. 

복사 생성자의 대표적인 선언 형태는 다음과 같다. 
```c++
<클래스 이름>(const <클래스이름>& <객체 이름>);  
```
```c++
Person(const Person& other);  
```
`const Person&`는 원본 객체를 복사하지 않고 참조로 전달하며, 생성자에서 원본을 변경하지 못하도록 한다. 컴파일러가 제공하는 복사 생성자는 각 멤버를 복사한다. `std::string`처럼 스스로 자원을 관리하는 멤버로 구성된 클래스라면 직접 복사 생성자를 작성하지 않아도 되는 경우가 많다.

클래스가 동적 메모리 등 자원을 **직접 소유**하고 복사할 때 별도의 자원을 만들어야 한다면 복사 생성자를 직접 구현할 수 있다. 이 경우 복사 할당 연산자와 소멸자의 동작도 함께 검토해야 한다.

```c++
<클래스 이름>(<클래스 이름>& <객체 이름>);
<클래스 이름>(const <클래스 이름>& <객체 이름>);
<클래스 이름>(volatile <클래스 이름>& <객체 이름>);
<클래스 이름>(volatile const <클래스 이름>& <객체 이름>);

<클래스 이름>(<클래스 이름>& <객체 이름>, ...기본 값들...);
```

복사 생성자의 매개변수에는 `<클래스이름>&`나 `volatile <클래스이름>&` 등의 형태도 가능하지만, 이 자료에서는 일반적인 `const <클래스이름>&` 형태를 사용한다. `volatile`은 멀티스레드 동기화 수단이 아니며, 스레드 간 공유 데이터에는 목적에 따라 `std::atomic` 또는 뮤텍스를 사용한다.

**volatile** 키워드는 다음의 3 경우에 주로 사용된다.

* MMIO(Memory-mapped I/O): I/O 디바이스가 메모리 주소에 매핑된 I/O
* 인터럽트 서비스 루틴 사용
* 멀티 스레드 환경 

인터럽트 서비스 루틴과 멀티 스레드 프로그램 작성 시 서로 공유해야 하는 전역 변수의 경우 컴파일러가 코드를 최적화하지 않고 순차적으로 모두 수행하도록 하여야 하는 경우에 **volatile**을 사용한다. 



```c++
#include <iostream>
using namespace std;

class Person {
   string name; 
   int age;      
public:
   Person(string n, int a) : name {n}, age {a} { //파러미터가 있는 생성자
      cout << "Constructor with parameter" << endl;
   }

   Person(const Person &other) : name{other.name}, age{other.age} { //복사 생성자
      cout << "User defined Copy constructor" << endl;     
   }
   void show() const {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 파러미터가 있는 생성자 호출
   Person kim {"Chul-soo Kim", 30};   // 파러미터가 있는 생성자 호출 
   Person lee = {"Soon-sin Lee", 40}; // 파러미터가 있는 생성자 호출 

   lee.show();
   Person man = hong; // 북사 생성자 호출 (man 객체는 hong 객체의 내용을 복사하여 생성)
   Person m1 {kim};

   man.show();
   m1.show();

   return 0;
}
```

프로그램 코드의 실행 결과는 다음과 같다.

```bash
Constructor with parameter
Constructor with parameter
Constructor with parameter
Soon-sin Lee, 40
User defined Copy constructor
User defined Copy constructor
Gil-Dong Hong, 28
Chul-soo Kim, 30
```

### 복사 초기화와 직접 초기화

`Person man = hong;` 는 기존 객체 `hong`으로 새 객체 `man`을 만드는 **복사 초기화**이다. `Person m1(kim);`은 **직접 초기화**이다. 
두 코드 모두 이 예제에서는 복사 생성자를 호출한다. `=` 기호가 있어도 `man`은 이 문장에서 새로 생성되므로 **복사 할당 연산자를 호출하는 것은 아니다**. 복사 할당은 `man = kim;`처럼 이미 생성된 객체에 대입할 때 일어난다.

복사 생성자에 `explicit`을 지정하면 `Person lee = hong;`과 같은 복사 초기화에는 사용할 수 없다. `Person lee(hong);`처럼 생성자를 직접 선택하는 초기화는 가능하다.

```c++
#include <iostream>
#include <string>
using namespace std;

class Person {
   string name; 
      int age;      
public:
      Person(string name, int age) { //인자가 있는 생성자
         this->name = name;
         this->age = age;
      }
      explicit Person(const Person &ref) {    //복사 생성자      
         name = ref.name;
         age = ref.age;
      }
      void show() const {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 인자가 있는 생성자 호출
   
   //Person lee = hong; // 오류: explicit 복사 생성자는 복사 초기화에 사용할 수 없음
   Person lee(hong);    // 정상: 직접 초기화
   lee.show();

   return 0;
}
```
클래스를 정의할 때 다음과 같이 복사 생성자를 호출할 수 없게 하려면 `= delete`를 사용한다. **복사 생성과 복사 할당을 모두 금지하려면** 두 함수를 각각 삭제해야 한다.

```c++
Person(const Person&) = delete;
Perso& operator=(const Person&) = delete;
```
[앞으로](https://github.com/geunkim/CPPLectures/edit/master/Class)
