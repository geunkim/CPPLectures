# 복사 생성자(Copy Constructor)

복사 생성자는 동일한 자료형의 객체의 멤버 변수의 값을 복사하여 객체를 초기화한다. 즉 선언되는 객체와 같은 자료형의 객체의 복사가 필요할 때 사용되는 생성자이다. 클래스의 멤버 변수가 값을 저장하는 간단한 행태라면 컴파일러에서 생성하는 복사 생성자로 충분하여 사용자가 직접 복사 생성자를 정의할 필요는 없으나 객체 복사 시 복잡한 초기화가 필요한 경우에는 사용자 정의 복사 생성자를 정의하여야 한다. 
예로 클래스 멤버 변수에 포인터 변수가 있고 포인터 변수로 참조하는 저장 공간을 새롭게 할당하여야 하는 경우 복사 생성자를 사용자가 정의하여 메모리를 동적 할당하고 포인터 변수가 할당된 메모리를 가리키도록 하여야 한다. 

복사 생성자를 정의할 때 복사 할당 연산자(=)도 정의해야 한다. 

복사 생성자 정의하는 구문은 다음 중 하나이다. .

```c++
<클래스 이름>(<클래스 이름>& <변수 이름>);
<클래스 이름>(const <클래스 이름>& <변수 이름>);
<클래스 이름>(volatile <클래스 이름>& <변수 이름>);
<클래스 이름>(volatile const <클래스 이름>& <변수 이름>);

<클래스 이름>(<클래스 이름>& <변수 이름>, ...기본 값들...);
```
여기서 입력 파라미터의 **```const```** 키워드는 복사하려는 원본의 값을 함수 내에서 변경시키지 않도록 한다. 
**volatile** 키워드는 **volatile** 키워드를 사용하여 선언된 변수는 프로그램 실행 중 외부적인 요인으로 메모리에 저장된 값이 언제든지 바뀔 수 있는 변수라는 것으로 컴파일러에게 알리기 위한 키워드이다. 컴파일러는 **volatile** 로 선언된 변수에 대해서 최적화하지 않는다. **volatile** 변수를 내용을 참조할 경우 CPU의 레지스터에 로도딘 값을 사용하지 않고 매번 메모리를 직접 참조한다. 
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
   Person(const Person &ref) { //복사 생성자
      cout << "User defined Copy constructor" << endl;     
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
   Person m1 {kim};
   man.show();
   m1.shlow();
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

### 묵시적 변환

앞의 코드 중 ```Person man = hong;``` 코드는 ```Person man(hong);```로 묵시적 변환이 되어 ```hong```객체를 매개변수로 받을 수 있는 복사 생성자가 호출되어 ```man``` 객체가 생성된다. 이처럼 자동으로 묵시적 변환되어 객체가 생성되는 것을 막기 위헤서 ```explicit``` 키워드가 사용된다. 복사 생성자 앞에 **explicit** 키워드를 적어주면 대입연산자를 이용하여 복사 생상자 호출 및 초기화가 불가능하여 묵시적 변환을 막을 수 있다.

```c++
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
클래스를 정의할 때 다음가 간치 복사 생성자를 삭제된 것으로 정의하여 객체가 복사되지 않도록 방지할 수 있다.

```c++
Person(const Person& p) = delete;
```
[앞으로](https://github.com/geunkim/CPPLectures/edit/master/Class)
