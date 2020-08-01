# 생성자와 소멸자  
 
## 생성자(constructor)
C++ 클래스는 객체가 생성될 때 자동으로 호출되는 생성자라는 특수한 멤버 함수를 가진다.
일반적으로 생성자를 통해 객체가 사용되기 전에 수행하여야 할 기능(예: 멤버 변수 초기화, 동적 메모리 할당 등)을 수행한다. 
생성자를 정의하는 구문은 다음과 같다.

```cpp
class 이름::class 이름(인수 목록) {
   ....
}
```

 * 생성자의 특징
   + 생성자는 함수이다. 
   + 생성자는 객체가 생성될 때 호출되는 함수로 객체가 생성될 때 필요한 초기 작업을 한다. 
   + 객체 생성 시 생성자는 오직 한번만 자동으로 실행한다. 
   + 생성자의 이름은 클래스 이름과 **동일**하다. 
   + 생성자는 아무것도 리턴하지 않는다 (void라고도 적을 필요가 없다).
   + 생성자는 오버로딩이 가능하다.(한 클래스에서 여러 개의 생성자를 만들 수 있다.)
   + 생성자도 함수이므로 디폴트 매개변수를 가질 수 있다.
   + 생성자가 선언되지 않으면 컴파일러가 기본 생성자(default constructor)를 자동으로 생성한다.
   + 매개변수가 있는 생성자를 선언하는 경우 컴파일러는 디폴트 생성자를 자동으로 생성하지 않는다.


```cpp
class Person {
   Person();            // 기본 생성자
   Person(string name); // 생성자 오버로딩 (매개변수 한 개) 
   Person(string name, int age);  // 생성자 오버로딩 (매개 변수 두 개)
   ...
};
```
### 기본 생성자(default constructor)

클래스의 객체가 생성할 때 반드시 하나의 생성자가 호출되어야 한다.
기본 생성자는 매개 변수가 없는 생성자를 말한다. 
생성자가 하나도 선언되지 않는 클래스의 경우 컴파일러가 생성자를 기본 생성자를 자동으로 생성한다.
컴파일러가 삽입한 기본 생성자는 아무 코드도 실행되지 않고 바로 리턴한다.

* 기본 생성자를 자동 생성 

객체를 생성할 때 수행해야 할 내용이 없으며 파러미터를 가지는 생성자를 만들 필요가 없는 
경우 클래스를 정의할 때 생성자를 선언하지 않아도 된다. 
이 경우 컴파일러가 실행 코드가 없는 기본 클래스를 생성한다. 

```cpp
#include <iostream>
using namespace std;

class Person{
private:
   string name;
   int age;
public:
   void setName(string n) { name = n;}
   void setAge(int a) { age = a;}
   void show() {
      cout << name << ", " << age << endl;
   }
};

int main(int argc, char const *argv[])
{
   Person s;  // 컴파일러가 자동 생성한 기본 생성자 Person() 호출 
   s.setName("Chul-soo Lee");
   s.setAge(20);
   s.show();
   return 0;
}
```
실행 결과는 다음과 같다.

``Chul-soo Lee, 20``

* 기본 생성자를 프로그래머가 생성 

앞의 프로그램 코드에서 객체를 생성할 때 이름과 나이를 초기화하는 생성자를 다음과 
같이 선언하였다.

```cpp
#include <iostream>
using namespace std;

class Person{
private:
   string name;
   int age;
public:
   Person(string n, int a) : name(n), age(a) {}
   void setName(string n) { name = n;}
   void setAge(int a) { age = a;}
   void show() {
      cout << name << ", " << age << endl;
   }
};

int main(int argc, char const *argv[])
{
   Person father;  // [컴파일 에러 발생] 컴파일러가 기본 생성자를 생성하지 않음 
   Person son("Gil-Dong Hong", 30); //생성자 호출 
   son.show();
   return 0;
}
```

앞의 프로그램을 컴파일하면 다음과 같은 에러가 발생한다. 
```
error: no matching constructor for initialization of 'Person'
        Person father;  // [컴파일 에러 발생] 컴파일러가 기본 생성자를 생성하지 않음 
               ^
```
프로그렘에서 ```Person son("Gil-Dong Hong", 30);```는 매개 변수를 가진 생성자
```Person(string n, int a)```를  호출하기 때문에 정상적으로 컴파일된다. 
그러나 ```Person father;```는 파러미터가 없는 기본 생성자를 호출하는데 파러미터가 있는 생성자가 선언되어 있기 때문에 컴파일러가 기본 생성자를 자동적으로 만들어 주지 않는다. 
그러므로 기본 생성자를 선언 및 정의하여야 한다. 

```cpp
#include <iostream>
using namespace std;

class Person{
private:
   string name;
   int age;
public:
   Person(){}            // 기본 생성자
   Person(string n) : name(n){}      // 생성자 1
   Person(string n, int a) : name(n), age(a) {} // 생성자 2
   void setName(string n) { name = n;}
   void setAge(int a) { age = a;}
   void show() {
      cout << name << ", " << age << endl;
   }
};

int main(int argc, char const *argv[])
{
   Person dad; // 기본 생성자 호출
   Person mom("Young-Hee Park");  // 생성자 1 호출
   Person son("Gil-Dong Lee", 20); // 생성자 2 호출
   dad.setName("Chul-soo Lee"), dad.setAge(52);
   mom.setAge(50);
   dad.show(), mom.show(), son.show();
   return 0;
}
```
앞의 프로그램은 여러 생성자를 중복 선언한 것이다. 
```main``` 함수에서 ```Person dad;```, ```Person mom("Young-Hee Park");```
```Person son("Gil-Dong Lee", 20);``` 의 세 개의 객체를 생성하고 있으며 
각 객체가 생성될 때 호출되는 생성자는 기본 생성자, 생성자 1, 생성자 2 이다. 
프로그램의 실행 결과는 다음과 같다.
``
Chul-soo Lee, 52
Young-Hee Park, 50
Gil-Dong Lee, 20
``

### 복사 생성자(Copy constructor)
   
선언되는 객체와 같은 자료형의 객체의 복사가 필요할 때 사용되는 생성자이다.
복사 생성자를 정의하는 구문은 다음과 같다.

```cpp
class 이름::class 이름(const class 이름 &참조이름) {
   ....
}
```

여기서 ```const```는 복사하려는 원본의 값을 변경시키지 않도록 한다. 

```cpp
#include <iostream>
using namespace std;

class Person {
   string name; 
   int age;      
public:
   Person(string name, int age) { //파러미터가 있는 생성자
      this->name = name;
      this->age = age;
   }
   Person(const Person &ref) { //복사 생성자      
      name = ref.name;
      age = ref.age;
   }
   void show() {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 파러미터가 있는 생성자 호출
   Person kim {"Chul-soo Kim", 30};   // 파러미터가 있는 생성자 호출 
   Person lee = {"Soon-sin Lee", 40}; // 파러미터가 있는 생성자 호출 
   
   lee.show();
   Person man = hong; // 북사 생성자 호출 (man 객체는 hong 객체의 내용을 복사하여 생성) 
   man.show();

   return 0;
}
```

프로그램 코드의 실행 결과는 다음과 같다.

``
Soon-sin Lee, 40
Gil-Dong Hong, 28
``

### 묵시적 변환

앞의 코드 중 ```Person man = hong;``` 코드는 ```Person man(hong);```로 묵시적 변환이 되어 ```hong```객체를 매개변수로 받을 수 있는 복사 생성자가 호출되어 ```man``` 객체가 생성된다. 이처럼 자동으로 묵시적 변환되어 객체가 생성되는 것을 막기 위헤서 ```explicit``` 키워드가 사용된다. 복사 생성자 앞에 ```explicit``` 키워드를 적어주면 대입연산자를 이용하여 복사 생상자 호출 및 초기화가 불가능하여 묵시적 변환을 막을 수 있다.

```cpp
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
      void show() {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 인자가 있는 생성자 호출
   
   //Person lee = hong; // 묵시적 변환의 불가능으로 컴파일 에러 발생
   Person lee(hong); // 복사 생성자를 통한 lee 객체 생성
   lee.show();

   return 0;
}
```

## 소멸자(destructor)

객체가 소멸되면 객체에 할당된 메모리는 반환된다. 
또한 객체가 소멸 시 소멸자 함수가 반드시 호출된다.
소멸자는 객체가 소멸되는 시점에 자동으로 호출되는 클래스의 멤버 함수이다. 
소멸자를 정의하는 구문은 다음과 같다.

```cpp
class 이름::~class 이름(인수 목록) {
   ....
}
```
* 소멸자의 특징
   + 소멸자는 함수이다.
   + 소멸자는 객체가 사라질 때 필요한 마무리 작업을 하게 된다.
   + 소멸자의 이름은 클래스 이름 앞에 ~를 붙인다.
   + 소멸자는 반환 자료형(리턴 타입)이 없으며 아무것도 반환하지 않는다 
   + 소멸자는 **오직 한 개**만 존재하고 매개 변수는 가질 수 없다.
   + 소멸자가 선언되어 있지 않으면 컴파일러가 기본 소멸자(default destructor)를 자동으로 생성한다. 
   
다음은 소멸자 호출을 확인하는 프로그램이다. 

```cpp
#include <iostream>
using namespace std;

class Person{
private:
   string name;
   int age;
public:
   void setName(string n) { name = n;}
   void setAge(int a) { age = a;}
   void show() {
      cout << name << ", " << age << endl;
   }
};

int main(int argc, char const *argv[])
{
   Person s;  // 컴파일러가 자동 생성한 기본 생성자 호출 
   s.setName("Chul-soo Lee");
   s.setAge(20);
   s.show();
   return 0;
}
```

```main```함수에서 ```s.show()```를 호출 한 후 ```main```함수가 종료되면서 
객체 ```s```의 소멸자가 호출되어 "소멸자 호출"이라는 문자열이 출력된다. 
실행 결과는 다음과 같다.

``
Chul-soo Lee, 20
소멸자 호출
``
