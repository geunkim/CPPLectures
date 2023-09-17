# 복사 생성자(Copy Constructor)


선언되는 객체와 같은 자료형의 객체의 복사가 필요할 때 사용되는 생성자이다.
복사 생성자를 정의하는 구문은 다음과 같다.

```cpp
class 이름::class 이름(const class <클래스 이름>& <변수 이름>) {
   ....
}
```

여기서 입력 파라미터의 **```const```** 는 복사하려는 원본의 값을 함수 내에서 변경시키지 않도록 한다. 

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


