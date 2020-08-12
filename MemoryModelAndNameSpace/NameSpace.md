# 이름 공간(Name Space)

공간에 이름을 주는 행위이다. 특정 영역에 이름을 주어 변수나 함수가 이름이 같아 충돌하는 일을 방지하기 위해 만들어졌다.


## 이름 공간 정의하기
선언 구역 안에 함수나 변수, 구조체나 클래스 그리고 내부 이름 공간을 정의할 수 있다.
이름 공간은 함수 몸체 안에서 정의할 수 없다.
```cpp
namespace example {
    int func() { return 0; }
    int a;
    struct MyStruct
    {
        int b;
    };
    class MyClass
    {
    public: MyClass(int val) { a = val; }
    private: int a;
    };
    namespace newNamespace {
        //...
    }
}
```

* 이름이 있는 이름 공간
여러 번 namespace 선언하여 이름공간을 정의할 수 있다. 같은 namespace을 여러 번 정의함으로서 개체(언급한 선언 구역안에 들어가는 것)들을 추가할 수 있다.
그리고 이름이 있는(이름이 없는 경우는 아래에) 이름 공간은 열려 있어서 다른 파일에서도 같은 이름 공간을 정의할 수 있다.
이렇게 여기저기에 똑같은 이름으로 정의된 이름 공간들은 같은 이름끼리 통합된다.

* 이름이 없는 익명 이름 공간
이름 공간을 정의할 때 이름 없이 정의할 수 있다. 익명 이름공간에 정의된 객체들은 static 함수나 변수와 같다고 볼 수 있다.
이름이 없는 익명 이름 공간은 닫혀 있다. 따라서 다른 파일과 독립적으로 작동한다. 익명 공간에 개체를 추가하더라도 다른 파일의 익명 공간에 보이지 않는다.

이름공간 안에서 선언된 개체는 이름공간 밖에 정의할 수 있다.
```cpp
#include <iostream>
using namespace std;

namespace bean { // 이름 공간
    string grow();
}
string bean::grow() {
    return "I am big bean stalk.";
}
namespace { // 익명 이름 공간
    int noNameFunc();
    int thisISGame = 57;
}
int ::noNameFunc() {
    return 7;
}

int main()
{   
    cout << bean::grow() << endl << endl;
    cout << ::noNameFunc() << endl;
}
```
## 개체 참조하기
이름공간과 개체가 주어지면 영역 지정 연산자 ::을 이용하여 그 개체를 참조할 수 있다.(위에서 보았던 예)
특정 개체가 자주 사용될 경우 선언 후 간략한 형태를 사용하면 된다.
```
// (생략)
using bean::grow;
int main()
{   
    cout << grow() << endl << endl;
}
```
이름 공간에 정의된 함수와 이름 공간 바깥에 일반적으로 정의된 함수가 이름이 같은경우 그 이름을 호출하면 
기본적으로는 이름 공간 바깥에 정의된 함수가 나오지만, using 선언을 한 이후에는 자동으로 바깥에 정의된 함수 대신 이름 공간에 정의된 함수가 나오게 된다.
이에 영역 지정 연산자를 사용하면 이름공간 안쪽 함수와 바깥 함수 중 어떤 함수를 호출할 것인지 확실히 할 수 있다.
만약에 중괄호 안에 using 선언을 사용하게 되면, using 선언을 했던 중괄호가 끝나는 지점에 그 선언의 효력이 끝난다.(using 선언하기 전으로 되돌아감)
```cpp
#include <iostream>
using namespace std;

namespace heyyy {
    string shout() { return "this is inside of namespace"; }
}
string shout() { return "this is outside of namespace"; }

int main()
{   
    cout << shout() << endl;
    cout << ::shout() << endl;
    cout << heyyy::shout() << endl;
    
    using heyyy::shout; // heyyy 이름 공간의 shout 멤버를 사용할 것을 확실히 함.(using 선언이라고 함)

    cout << shout() << endl;
    cout << ::shout() << endl;
    cout << heyyy::shout() << endl;

    // 출력 결과
    // this is outside of namespace
    // this is outside of namespace
    // this is inside of namespace
    // this is inside of namespace
    // this is outside of namespace
    // this is inside of namespace
}
```

### using 지시어
using 지시어를 사용하면 이름공간 안에 정의된 모든 개체들은 하나하나 using 선언이 된 것 처럼 사용된다.
using 지시어는 한 이름공간 안에 있는 모든 이름을 반입하는 빠른 방법이다. 하지만 특정 코드 블록 안에 실제로 어떤 개체가 사용중인지 좀 명확하지 않다.
즉, 불러온 이름공간의 멤버중에 이름이 같아 일부분에 의도와 다른 멤버가 호출될 수 있다.

### 쾨닉 검색
간단히 말하면 함수 인자의 자료형을 가지고 이름공간을 추론한다.
이름 공간을 지정하지 않고 함수를 호출하면 인자 유형의 이름공간을 따라 함수의 이름공간을 결정한다.
이는 함수를 호출할때 일일히 ::을 사용하지 않아도 되는 편리함을 가지고 있다.
```cpp
namespace example {
    struct pen
    {

    };
    pen myPen;
    void func(pen a) {
        cout << "example func active" << endl;
    }
    void food() {
        cout << "Hi, I am random food." << endl;
    }
}

int main()
{
    func(example::myPen); // 쾨닉 검색을 통해 using 선언을 사용하지 않고도 func를 사용할 수 있습니다.
    // food(); // Error : 식별자 "food"가 정의되어 있지 않습니다.(쾨닉 검색이 작동하지 않았습니다.)
}
```

