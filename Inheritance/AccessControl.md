# 상속과 접근지정자 

자식 클래스가 부모 클래스로부터 상속을 받을 때, 자식 클래스는 부모 클래스로부터 상속받은 멤버들을
즉, 부모 클래스의 멤버와 부모 클래스로부터 상속받은 멤버는 다른 것이다.
```C++
// BaseClass, Base2를 상속받은 후 보호수준을 private로 격상시킨다, Base3은 그냥 상속받는다.
class privClass : private BaseClass, Base2, public Base3 {
public:
    void func() {
        a;
        b;
        c;
        d;
    }
};
```

클래스 선언문 다음에 :을 붙이고, 접근 지정자를 붙인 뒤 상속받을 부모 클래스의 이름이 온다. (클래스가 여러 개일 경우, 쉼표로 구분한다.) 여기서 사용하는 상속 접근 지시자는 public, private, protected가 있다.

부모 클래스에서 멤버의 접근 제한자와 자식 클래스가 설정한 상속 접근 제한자가 다른 경우 제한이 더 센 접근 제한을 따른다.
여기서, 접근 제한자의 제한 강도는 아래와 같다.
```
private > protected > public
```
예를 들어 부모 클래스의 멤버의 접근 지정자가 제한이 없는 pubilc인 경우, 자식 클래스가 상속받을 때 상속 접근 지정자를 private로 지정한 경우 상속받은 멤버 변수는 자식 클래스 내부에서만 사용할 수 있다는 것이다.
또 이는 다른 클래스가 다시 상속을 할 때, 이렇게 제한 접근이 강화된 것은 public 상속 접근 지정자를 사용 하여도 그대로 유지된다.

## 자식 클래스의 접근 가능 여부
부모 클래스에서 상속 접근 지정자를 통해서 받을 때 자식 클래스가 접근이 가능한 지, 불가능한지가 있다





public인 멤버는 외부 접근 제한이 없고, private인 멤버는 클래스 내부에서만 사용하도록 제한이 되어 있다. 이때 보호 수준이 중간 정도인 접근 지정자가 있는데 protect이 있다.
protect은 자기 자신 클래스 내부 뿐만 아니라, 자신을 상속할 자식 클래스에게 멤버 접근이 가능하도록 되어 있다.



* protect인 


*


##

아래는 이를 정리한 것이다.
부모 클래스의 private 멤버는 이미 부모 클래스 내부에서만 사용할 수 있도록 설정되어 있기 때문에 접근 할 수 없다.
|:---|:---|:---|:---|
|상속 접근 지정자|부모 클래스가||

|------|---|---|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|

상속 접근 지정자가 private이면 [case 1. private](####-상속-접근-지정자가-private이면)
* 부모 클래스의 멤버가 private일 때 접근 불가능(자식 클래스도 사용할 수 없음)
* 부모 클래스의 멤버가 protected일 때 private(자식 클래스 자신만 허용)
* 부모 클래스의 멤버가 public일 때 private(자식 클래스 자신만 허용)

상속 접근 지정자가 protected이면 [case 1. protected](####-상속-접근-지정자가-protected이면)
* 부모 클래스의 멤버가 private일 때 접근 불가능(자식 클래스도 사용할 수 없음)
* 부모 클래스의 멤버가 protected일 때 protected(자식 클래스 자신과 자식 클래스를 상속받는 클래스는 허용)
* 부모 클래스의 멤버가 public일 때 protected(자식 클래스 자신과 자식 클래스를 상속받는 클래스는 허용)

상속 접근 지정자가 public이면 [case 1. public](####-상속-접근-지정자가-public이면)
* 부모 클래스의 멤버가 private일 때 접근 불가능(자식 클래스도 사용할 수 없음)
* 부모 클래스의 멤버가 protected일 때 protected(자식 클래스 자신과 자식 클래스를 상속받는 클래스는 허용)
* 부모 클래스의 멤버가 public일 때 public(외부에서도 접근이 가능함)

### 예제 코드

#### 상속 접근 지정자가 private이면

Derived 클래스가 부모 클래스 Base의 맴버들을 private로 상속받았다. 이런 식으로 상속을 받게 된다면 Derived 클래스의 자식 클래스들은 Derived의 부모 클래스의 멤버들에 접근할 수 없게 된다.
(Derived의 자식 클래스가 Derived의 부모 클래스를 public으로 상속받는다고 표기하여도 모호함이 발생하게 된다.)
```C++
#include <iostream>
using namespace std;

class Base {
private:
    int a;
protected:
    int b;
public:
    int c;
};
class Derived : private Base {
public:
    void func() {
        //a; //접근 불가능
        b; //자식 클래스는 접근 허용 (protected)
        c; //접근 허용
    }
};

// Derived의 자식 클래스가 접근
class Derived2 : public Derived {
public:
    void func() {
        //a; //접근 불가능
        //b; //접근 불가능
        //c; //접근 불가능
    }
};
//외부에서 접근
int main() {
    Derived A;
    //A.a = 10; //외부에서 접근 불가능 (private)
    //A.b = 10; //외부에서 접근 불가능 (private)
    //A.c = 10; //외부에서 접근 불가능 (private)
    return 0;
}
```

#### 상속 접근 지정자가 protected이면

Derived 클래스가 부모 클래스 Base의 맴버들을 protected로 상속받았다. 이런 식으로 상속받게 된다면 외부에서는 (부모로부터 상속받은) 멤버에 접근할 수 없지만, 상속받은 관계에서는 부모 클래스의 private 멤버를 제외한 멤버들에 접근할 수 있게 된다.
```C++
#include <iostream>
using namespace std;

class Base {
private:
    int a;
protected:
    int b;
public:
    int c;
};
class Derived : protected Base {
public:
    void func() {
        //a; //접근 불가능
        b; //자식 클래스는 접근 허용 (protected)
        c; //접근 허용
    }
};

// 자식의 자식 클래스
class Derived2 : public Derived {
public:
    void func() {
        //a; //접근 불가능
        b; //자식 클래스는 접근 허용 (protected)
        c; //자식 클래스는 접근 허용 (protected)
    }
};
//외부에서 접근
int main() {
    Derived A;
    //A.a = 10; //외부에서 접근 불가능 (private)
    //A.b = 10; //외부에서 접근 불가능 (protected)
    //A.c = 10; //외부에서 접근 불가능 (protected)
    return 0;
}
```

#### 상속 접근 지정자가 public이면

Derived 클래스가 부모 클래스 Base의 맴버들을 public으로 상속받았다. 이런 식으로 상속받게 되면 외부에서는 public 멤버만 접근할 수 있게 된다.
```C++
#include <iostream>
using namespace std;

class Base {
private:
    int a;
protected:
    int b;
public:
    int c;
};
class Derived : public Base {
public:
    void func() {
        //a; //접근 불가능
        b; //자식 클래스는 접근 허용 (protected)
        c; //접근 허용
    }
};

// 자식의 자식 클래스
class Derived2 : public Derived {
public:
    void func() {
        //a; //접근 불가능
        b; //자식 클래스는 접근 허용 (protected)
        c; //접근 허용
    }
};
//외부에서 접근
int main() {
    Derived A;
    //A.a = 10; //외부에서 접근 불가능 (private)
    //A.b = 10; //외부에서 접근 불가능 (protected)
    A.c = 10; //접근 허용
    return 0;
}
```
기본적으로 class는 상속받을 때 상속 접근 지정자를 적어놓지 않았을 때 private 접근 지정자로 간주한다.
따라서 상속이 직렬로 2차례 이상 일어 날 때 접근 지정자를 적어놓지 않으면 기반 클래스의 멤버가 접근이 되지 않는다.
protected 혹은 public 접근 지정자를 사용하면 원본 멤버를 건너받을 수 있다.
