# STL 실습 2

1. 다음 프로그램을 분석하고 컨테이너에 저장된 데이터를 출력하도록 프로그램을 완성하라.

```c++
#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> deq;
    for (int count=0; count < 10; ++count)
    {
        deq.push_back(count); // insert at end of array
        deq.push_front(10 - count); // insert at front of array
    }

    // 출력하는 코드 추가 
}
```

2. 키보드로 부터 0이 입력될 때까지 정수를 입력받고 입력된 정수가 홀수 이면 deque 컨테이너의 뒤에 추가하고 짝수이면 deque 컨테이너의 앞에 추가하고 데이터가 다 출력되면 저장된 데이터 값을 화면에 출력하는 프로그램을 작성하라.

3. 1 번 프로그램 코드에 deque의 메소드를 추가하여 deque 컨테이너 기능을 검증하라.

4. 다음 프로그램을 실행하고 분석하고 저장된 데이터를 화면에 출력하도록 프로그램을 완성하라. 

```c++
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> s;

    cout << s.empty() << endl
  
    s.push(4); 
    s.push(7); 
    s.push(8); 
    s.push(2);
 
    
    cout << s.size() << endl;
    cout << s.top() << end;
    cout << s.pop() << endl;
    cout << s.size() << endl;
  
    // s에 저장된 모든 데이터를 화면에 출력하는 코드를 여기에 추가
    
    return 0;
}
```

5. 키보드로 부터 1, 2, 3, 4, 5를 입력 받고 stack 컨테이너를 이용하여 5, 4, 3, 2, 1. 의 순서로 출력하도록 프로그램을 작성하라.

6. 다음 프로그램을 실행하고 분석하라.

```c++
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
    
    priority_queue<int> q;
    q.push(7);
    q.push(6);
    q.push(3);
    q.push(5);
    q.push(1);
  
   
    cout << q.size() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
  
}
```

7. 다음 프로그램에서 priority_queue에 저장된 데이터를 모두 출력하도록 프로그램을 완성하라. 
 
```c++
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
    
    priority_queue<int> q;
    q.push(7);
    q.push(6);
    q.push(3);
    q.push(5);
    q.push(1);
  
}
```

8 7번의 priority_queue를  queue로 변경하어 데이터를 저장하고 저장된 데이터를 출력하는 프로그램을 작성하라.

9. STL map container를 사용하는 프로그램을 작성하라. 


 
