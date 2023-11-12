## 컨테이너 어댑터(Container Adapters)

템플릿 컨테이너 어댑터 글래스는 단순성과 명확성을 위해 인터페이스를 제한하는 시퀀스 또는 연관 컨테이너의 변형이다. 템플릿 컨테이너 어댑터는 반복자를 지원하지 않는다. 

### queue

queue 컨터이너는 선입 선출(FIFO: first-in first-out) 형태로 데이터를 입출력한다. 처음에 **push**(queue에 데이터 저장)된 요소가 처음에 **pop**(queue의 데이터 삭제) 된다. 
queue 컨테이너 어댑터 클래스 구문은 다음과 같다.

```c++
template <class Type, class Container = deque <Type>>
class queue
```
다음은 queue 를 사용한 프로그램 예이다. 

```c++
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> q;

    if(q.empty()) cout << "큐 q 는 비워 있음(1)" << endl;  // empty
    q.push(50);  //push
    q.push(40);
    q.push(30);

    int& i = q.back();  //back
    cout << "큐 q의 끝에 있는 데이터 값: " << i << endl; 
    i = 20;  
    int& i1 = q.back();
    cout << "큐 q의 끝에 있는 데이터 값: " << i1 << endl; 

    const int& i2 = q.front(); // front
    cout << "큐 q의 처음에 있는 데이터 값: " << i2 << endl; 
    cout << "큐 q에 저장된 데이터 개수: " << q.size() << endl;  // size
    q.pop();    // pop

    if(q.empty()) cout << "큐 q 는 비워있음(2)" << endl;
    else cout << "큐 q에 데이터가 있으며 데이터 개수는 " << q.size() << "개 이다" << endl;
    return 0;
}
```

### priority_queue

priority_queue 컨테이너는 최상의 우선 순위를 가진 요소가 항상 queue의 첫 번째에 존재한다. 
priority_queue 템플릿 클래스의 구문은 다음과 같다.

```c++
template <class Type, class Container= vector <Type>, class Compare= less <typename Container ::value_type>>
class priority_queue
```
다음은 ```priority_queue```를 이용한 프로그램 예이다.

```c++
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int> q1, q2;

    q1.push(1);

    if (q1.empty( )) cout << "우선순위 큐 q1은 비웠음." << endl; // empty()
    else cout << "우선순위 큐 q1에 데이터가 존재함." << endl;

    if (q2.empty( )) cout << "우선순위 큐 q2는 비웠음." << endl;
    else cout << "우선순위 큐 q2에 데이터가 존재함." << endl;

    q1.push(3); // push()
    q1.push(40);
    q1.push(5);

    cout << "우선순위 큐 q1의 데이터 개수: " << q1.size() << endl; // size()
    cout << "우선순위 큐 q1에서 우선순위가 제일 높은 데이터 값은: " << q1.top() << endl; // top()

    q1.pop();

    cout << "우선순위 큐 q1에서 pop()한 후 데이터 개수: " << q1.size() << endl;
    cout << "우선순위 큐 q1에서 pop()한 후 우선순위가 제일 높은 데이터 값은: " << q1.top() << endl; // top()

    return 0;
}
```

### stack 

stack 컨테이너는 후입 선출(LIFO: last-in first-out) 형태로 데이터를 입출력한다. stack에 **push**된 마지막 요소가 **pop**되는 첫 번째 요소이다. 
stack 템플릿 클라스의 구문은 다음과 같다.

```c++
template <class Type, class Container= deque <Type>>
class stack
```
다음은 ```stack```을 이용한 프로그램 예이다. 

```c++
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> s1, s2;

    s1.push(1);

    if (s1.empty( )) cout << "스텍 s1은 비웠음." << endl; // empty()
    else cout << "스텍 s1에 데이터가 존재함." << endl;

    if (s2.empty( )) cout << "스택 s2는 비웠음." << endl;
    else cout << "스택 s2에 데이터가 존재함." << endl;

    s1.push(3); // push()
    s1.push(4);
    s1.push(5);

    cout << "스택 s1의 데이터 개수: " << s1.size() << endl; // size()
    cout << "스택 s1에 최근 저장한 데이터: " << s1.top() << endl; // top()

    s1.pop(); // pop()
    cout << "스택 s1에 pop()한 후 저장된 데이터 개수: " << s1.size() << endl;
    return 0;
}
```

### 컨테이너 어댑터와 STL 알고리즘과의 관계

컨테이너 어댑터는 반복자를 지원하지 않기 때문에 C++ STL 알고리즘과 함께 사용할 수 없다. 
