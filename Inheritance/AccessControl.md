# 상속과 접근지정자 

클래스 안으로 담을 때, 상속받는 멤버들을 어느만큼 보호를 강화할지 결정할 수 있다.

```
class privClass : private BaseClass, Base2, public Base3 { // BaseClass, Base2를 상속받은 후 보호수준을 private로 격상시킨다.
public:
    void func() {
        a;
        b;
        c;
        d;
    }
};
```

클래스 선언문 다음에 :을 붙이고, 접근 지정자를 붙인 뒤 상속받을 기반 클래스의 이름이 온다. (클래스가 여러 개일 경우, 쉼표로 구분한다.)
이 때, 기반 클래스로부터 상속받은 멤버는 최소한 상속의 접근 지정자 이상의 보호를 받게 된다.
예를 들어 기반 클래스가 제한이 없는 pubilc인 경우, 파생 클래스가 상속받을 때 상속 접근 지정자를 private로 지정한 경우 상속받은 멤버 변수는 파생 클래스 내부에서만 사용할 수 있다는 것이다.
또 이는 다른 클래스가 다시 상속을 할 때, 이렇게 제한 접근이 강화된 것은 public 상속 접근 지정자를 사용 하여도 그대로 유지된다.


아래는 이를 정리한 것이다.

상속 접근 지정자가 private이면
* 기반 클래스가 private일 때 접근 불가능
* 기반 클래스가 protected일 때 private
* 기반 클래스가 public일 때 private

상속 접근 지정자가 protected이면
* 기반 클래스가 private일 때 접근 불가능
* 기반 클래스가 protected일 때 protected
* 기반 클래스가 public일 때 protected

상속 접근 지정자가 private이면
* 기반 클래스가 private일 때 접근 불가능
* 기반 클래스가 protected일 때 protected
* 기반 클래스가 public일 때 public

예제 코드
```
#include <iostream>
using namespace std;


class BaseClass {
private:
    int a;
protected:
    int b;
public:
    int c;
};
class Base2 {
protected:
    int d;
};


class privClass : private BaseClass { // BaseClass를 상속받은 후 멤버의 최소 보호수준을 private로 격상시킨다.
public:
    void func() {
        //a; //접근 불가능
        b;
        c;
        d;
    }
};
class privClassDerived : public privClass {
public:
    void func() {
        //a; //접근 불가능
        //b; //접근 불가능
        //c; //접근 불가능
    }
};


class protClass : protected BaseClass { // BaseClass를 상속받은 후 멤버의 최소 보호수준을 protected로 격상시킨다.
public:
    void func() {
        //a; //접근 불가능
        b;
        c;
    }
};
class protClassDerived : public protClass {
public:
    void func() {
        //a; //접근 불가능
        b;
        c;
    }
};


class publClass : public BaseClass { // BaseClass를 public으로 상속받는다.
public:
    void func() {
        //a; //접근 불가능
        b;
        c;
    }
};
class publClassDerived : public publClass {
public:
    void func() {
        //a; //접근 불가능
        b;
        c;
    }
};


int main() // 외부의 메인 함수
{
    std::cout << "Hello World!\n";
    protClassDerived A;
    //A.a = 10; //접근 불가능 private
    //A.b = 10; //접근 불가능 private
    //A.c = 10; //접근 불가능 private

    protClassDerived B;
    //B.a = 10; //접근 불가능 private
    //B.b = 10; //접근 불가능 protected
    //B.c = 10; //접근 불가능 protected

    publClassDerived C;
    //C.a = 10; //접근 불가능 private
    //C.b = 10; //접근 불가능 protected
    C.c = 10;
}
```

기본적으로 class는 상속받을 때 상속 접근 지정자를 적어놓지 않았을 때 private 접근 지정자로 간주한다.
따라서 상속이 직렬로 2차례 이상 일어 날 때 접근 지정자를 적어놓지 않으면 기반 클래스의 멤버가 접근이 되지 않는다.
protected 혹은 public 접근 지정자를 사용하면 원본 멤버를 건너받을 수 있다.
