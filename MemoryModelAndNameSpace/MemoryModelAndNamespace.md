## 메모리 모델

메모리의 구조: 프로그램이 실행되기 위해서는 프로그램이 메모리에 로드되어야 한다.
컴퓨터의 운영체제는 프로그램의 실행을 위해 다양한 메모리 공간을 제공한다.
프로그램이 운영체제로부터 할당받는 대표적인 메모리 영역은 코드, 데이터, 힙, 스텍이 있다.

![메모리 구조jpg](https://user-images.githubusercontent.com/59677943/89748498-80763400-dafe-11ea-9fb5-d16844f1f0d6.jpg)

코드 영역은 실행할 프로그램의 코드가 저장되는 영역, 텍스트 영역이라고도 부른다. CPU는 코드 영역에 저장된 명령어를 하나씩 가져가서 처리를 한다.
이 영역의 정보는 read only로 절대 변경되지 않아야 한다, 그리고 컴파일 할 때 그 크기가 정해진다.

데이터 영역은 프로그램의 전역 변수와 정적 변수가 저장되는 영역이다. 프로그램의 시작과 함께 할당되며 프로그램이 종료되면 소멸한다.
데이터 영역은 초기화된 static, 초기화된 전역변수 부분으로 나뉜다.
Bss 영역은 초기화되지 않은 전역변수, 0으로 초기화된 전역변수, 초기화되지 않은 static 변수, 0으로 초기화된 static 변수가 올라오는 부분이며, 여기로 올라오는 모든 변수는 0으로 초기화된다.
데이터 영역과 Bss 영역은 그 크기가 정해진다.

힙 영역은 사용자가 직접 관리해야만 하는 메모리 영역이다. 사용자에 의해 메모리 공간이 동적으로 할당되고 해제된다(new 등으로). 힙 영역은 메모리의 낮은 주소에서 높은 주소의 방향으로 할당된다
먼저 들어간 데이터가 가장 먼저 나온다

스택 영역은 함수의 호출과 관계되는 지역 변수와 매개 변수가 저장되는 영역입니다. 함수의 호출과 
함께 할당되며, 함수의 호출이 완료되면 소멸한다.
지역변수와 매개변수들이 임시적으로 할당되는 공간이다(auto, cpu 메모리에 들어가지 못한 register 등). 먼저 들어간 데이터가 가장 나중에 나온다.

예제 코드
```
#include <iostream>
using namespace std;

extern int num004 = 10;

void fun(int a) {
    auto num001 = a;
    int num002 = a;
    static int num003 = a;
    register int num005 = a;

    // 각 변수들의 값과 주소값을 출력합니다.
    printf(" auto   num001 = %d, &num001 = %d \n", num001, &num001);
    printf("        num002 = %d, &num002 = %d \n", num002, &num002);
    printf(" static num003 = %d, &num003 = %d \n", num003, &num003);
    printf(" extern num004 = %d, &num004 = %d \n", num004, &num004);
    printf(" register  num005 = %d, &num005 = %d \n", num005, &num005);
}

int main()
{
    fun(10);

    return 0;
}
```
실행 결과
```
 auto   num001 = 10, &num001 = 9434804
        num002 = 10, &num002 = 9434792
 static num003 = 10, &num003 = 1880404
 extern num004 = 10, &num004 = 1880064
 register  num005 = 10, &num005 = 9434780
```
auto, 미표기, register 변수는 높은 공간에 존재하고, static, extern 변수는 낮은 공간에 존재한다.
일반적인 지역변수는 auto 변수처럼 작동한다. register변수는 주소를 사용해버려서 auto 변수처럼 작동한다.
extern과 static 변수는 데이터/bss 영역에 들어갔을 것으로 추론할 수 있다.

register 변수에 대한 추가 정보
* register 변수는 CPU에 들어가는 변수의 개수가 제한적이여서 컴파일러에게 register 제안이 무시될 수 있다.
* C++11에서는 register 키워드가 앞으로 사용되지 않을 것이다.
* C언어에서는 register의 주소값이 없으므로 가지고 올 수 없다. 다만 C++에서 이 제한이 사라져 주소를 사용하면 이 변수가 register 변수로 되지 않도록 보장된다.

### 스택 오버플로우
데이터를 정적할당할 때 힙 또는 스택에 저장할 수 있는데,
스택은 일반적으로 CUP 캐시에 있는 것처럼 선호되므로 스택에 저장된 객체와 관련된 작업이 더 빠른 경향이 있다.
그러나 스택은 용량이 어느 정도로 한정되어있다. 만약에 스택에 들어간 변수들중 일부의 크기가 너무 커져버리면
스택 영역에 있어야 할 지역변수의 공간이 인접한 다른 메모리 영역을 침범하게 되어 메모리 접근 오류가 발생하게 된다.

## 이름 공간
공간에 이름을 주는 행위이다. 특정 영역에 이름을 주어 변수나 함수가 이름이 같아 충돌하는 일을 방지하기 위해 만들어졌다.


### 이름 공간 정의하기
선언 구역 안에 함수나 변수, 구조체나 클래스 그리고 내부 이름 공간을 정의할 수 있다.
이름 공간은 함수 몸체 안에서 정의할 수 없다.
```
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
```
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
### 개체 참조하기
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
```
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

#### using 지시어
using 지시어를 사용하면 이름공간 안에 정의된 모든 개체들은 하나하나 using 선언이 된 것 처럼 사용된다.
using 지시어는 한 이름공간 안에 있는 모든 이름을 반입하는 빠른 방법이다. 하지만 특정 코드 블록 안에 실제로 어떤 개체가 사용중인지 좀 명확하지 않다.
즉, 불러온 이름공간의 멤버중에 이름이 같아 일부분에 의도와 다른 멤버가 호출될 수 있다.

#### 쾨닉 검색
간단히 말하면 함수 인자의 자료형을 가지고 이름공간을 추론한다.
이름 공간을 지정하지 않고 함수를 호출하면 인자 유형의 이름공간을 따라 함수의 이름공간을 결정한다.
이는 함수를 호출할때 일일히 ::을 사용하지 않아도 되는 편리함을 가지고 있다.
```
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
##
https://younggwan.tistory.com/9
https://youngq.tistory.com/64
https://dev.to/wes5510/c-c-2p3i
https://m.blog.naver.com/PostView.nhn?blogId=jins8611&logNo=110177543529&proxyReferer=https:%2F%2Fwww.google.com%2F
