# 다중상속
자식(child/derived/sub) 클래스가 2개 이상의 부모(parent/base/super) 클래스로부터의 상속을 받는 경우이다. 기존 상속과 같이 자식 클래스는 상위 클래스와 같은 이름의 멤버를 가질 수 있다. 다중 상속은 독립적인 라이브러리에 있는 클래스 n개를 하나의 클래스로 만들고자 할 때 쓰인다. 다중상속 시 클래스의 선언은 `class <자식클래스 이름> : <접근 지정자> <부모 클래스 이름>, <부모 클래스 이름>`처럼 `, (콤마)`로 상속받을 클래스들을 나열한다. 중괄호 안에는 상속받은 클래스에서 추가할 멤버 변수와 함수를 추가한다.

```
#include <iostream>
using namespace std;

class BaseOne{
public:
    void bs1() {
        cout << "One";}
};

class BaseTwo {
public:
    void bs2() {
        cout << "Two";}
};

class Derived : public BaseOne, BaseTwo {
public:
    void show() {
        bs1();
        bs2();
    }
};

int main()
{
    Derived drv;
    drv.show();
    return 0;
}
```
위의 코드를 실행하면 `OneTwo`가 출력된다.
## 다중상속의 문제점
[![죽음의 다이아몬드(the Deadly Diamond of Death)](http://www.dbguide.net/images/know/tech/071116_02.jpg)](https://www.kdata.or.kr/info/info_04_view.html?field=&keyword=&type=techreport&page=242&dbnum=127418&mode=detail&type=techreport)
다중상속에는 자식 클래스가 간접 기본 클래스들로부터 중복된 멤버를 물려받는 '죽음의 다이아몬드(the Deadly Diamond of Death)'라는 문제점이 있다. 위의 코드에서 BaseOne, BaseTwo의 멤버가 bs1, bs2가 아닌 bs일 때 bs라는 중복된 멤버에 접근할 때 상속받은 간접 기본 클래스 BaseOne, BaseTwo 중 어느 클래스의 bs에 접근해야 하는지 판단할 수 없게되어 컴파일 에러가 뜨게 되는 것이다. 이를 객체 지향 프로그래밍에선 '모호하다'고 표현한다. 다이아몬드를 해결하는 데에는 두가지 방법이 있다.

**1. 스코프 해결 연산자(::)**
중복된 멤버를 가진 간접 기본 클래스에 일반적인 접근 방식인 '<자식 클래스>.멤버'와 같은 식으로 접근하면  어느 간접 기본 클래스의 멤버 에 접근할지 판단할 수 없게 되어 컴파일 에러가 나게 된다. 이때 스코프 해결 연산자로 어떤 클래스의 멤버인지 지정할 수 있다.
```
//전략
class Derived : public BaseOne, BaseTwo {
public:
    void show() {
        BaseTwo::bs();
    }
};
//후략
```

위처럼 스코프 해결 연산자로 상속받을 클래스를 명시적으로 표현 가능하다. 결과로는 BaseTwo 클래스의 `Two`가 출력된다. 마찬가지로 간접 기본 클래스를 BaseOne으로 명시하면 `One`이 출력된다.


**2. 가상 기본 클래스(virtual base class)**

다중상속의 모호성을 해결하기 위해 기본 클래스를 가상 기본 클래스로 만든다. 간접 기본 클래스에서 기본 클래스를 `virtual 키워드`를 사용하여 가상 기본 클래스로 상속을 받게 되면 파생 클래스에서 가상 기본 클래스로부터 상속받은 멤버에 접근이 가능하게 된다.

```
//전략
class BaseOne : virtual BaseZero{
public:
    void bs() {
        cout << "One";}
};

class BaseTwo : virtual BaseZero {
public:
    void bs() {
        cout << "Two";}
};
//후략
```

간접 기본 클래스 BaseOne, BaseTwo가 가상 기본 클래스 BaseZero를 상속 받으면서 BaseZero의 멤버를 호출하게 된다.

