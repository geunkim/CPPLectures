# STL iterator(반복자)

반복자는 C++ STL 컨테이너에 저장된 요소에 대해서 반복할 수 있는 객체로 각 개별 요소에 대한 접근을 제공한다.
C++ STL의 모든 컨테이너는 STL 알고리즘이 컨테이너에 저장된 요소의 자료형을 고려하지 않고 표준화된 방법으로 컨테이너의 요소를 접근할 수 있도록 반복자를 제공한다.  

``begin()``과 ``end()`` 와 같은 전역 멤버 함수를 사용하여 반복자를 명사적으로 사용할 수 있고 또한 
순방향 또는 역방향으로 포인터를 이동시키기 위해 ``++``연산자와 ``--``연산자를 사용할 수 있다. 
또한 ``range 기반 for`` 문 및 [] 연산자를 사용한 for loop를 이용하여 암묵적으로 반복자를 사용할 수 있다. 

```c++
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> v1;
    vector <int>::iterator v1_itr;
 
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    v1_itr = v1.begin();
    cout << "access the data through the iterator" << endl;
    for( ; v1_itr != v1.end(); v1_itr++) cout << *v1_itr << ", ";
    cout << endl;
    
    v1_itr = v1.begin();
    cout << "add 100 to every element in the vector through the iterator" << endl;
    for( ; v1_itr != v1.end(); v1_itr++) *v1_itr += 100;

    cout << "accee the element with range-for loop in the vector" << endl;
    for(auto& e : v1) cout << e << ", ";
    cout << endl; 

     cout << "accee the element with for loop in the vector" << endl;
    for(int i = 0; i < v1.size() ; i++) cout << v1[i] << ", ";
    cout << endl;
}
```
