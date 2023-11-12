## 연관 컨테이너(Associative Container)

### map 
map은 보통 키(key)/값(value)의 쌍(pair)으로 구성된 사전(dictionary)이라고도 한다. map은 키-값(key-value) 쌍으로 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. 컨테이너 내의 key 값은 유일하여야 하며 key 값은 저장된 데이터를 졍렬(sort)하는데 사용되고 값은 해당 key에 연결된다. 주어진 문서에서 나타난 단어에 해당하는 key와 문서에 각 단어가 몇 개 있는지를 표현하는 값(value)으로 구성하는 것이 ```map```의 에이다. ```map```의 정렬되지 않는 버전은 ```unorderd_map```이다.   

```map``` 클래스 템플릿의 원형은 아래와 같다. 

```c++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;
```
```key```는 ```Compare```비교 함수를 이용하여 정렬된다. 탐색, 삭제, 삽입 연산은 지수적 시간 복잡도(logarithmic complexity)[O(log n)]롤 가진다.
```map```은 일반적으로 ```Red-black``` tree로 구현된다. 


### set 
고유한 요소(element)(key에 해당)가 오름차순으로 저장된 컨테이너로 클래스 템플릿(class template)이다. 컨테이너 내의 데이터 값이 정렬을 위한 key에 해당하며 유일하여야 하며 key 값으로 졍렬(sort)된다. ```set```의 정렬되지 않은 버전으로 ```unordered_map```이 있다. 

```c++
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;
```
```map```과 ```set```은 컨테이너에 저장되는 요소 또는 key가 유일하여야 한다. 같은 값의 요소 또는 key의 여러 개의 데이터를 저장하려면 
```multimap``` 또는 ```multiset```을 사용한다. 
정렬된 ```map``` 과 ```set```은 양뱡향의 반복자를 지원하고 정렬되지 않는 ```map```과 ```set``` 은 순뱡향의 반복자를 지원한다. 


#### 연관 컨테이너에서의 이종 조회(Heterogeneous Lookup) (C++14)

정렬된 연관 컨터이너(map, multimap, set, multiset)은 이종 조회(heterogenous lookup)으 지원한다. 이종 조회는 ```find()```와 ```lower_bound()```와 같은 
멤버 함수 내의 key 또는 요소(element)가 동알한 자료형의 객체를 매개 변수로 전달하지 않아도 된다. 동일한 자료형의 객체 대신에 key의 자료형과 비교할 수 있도록
 ```operator<```의 오버로드가 정의된 모든 자료형의 객체를 전달할 수 있다.  

다음과 같이 컨테이너 변수를 선언할 때 ```std::less<>``` 또는 ```std::greater<>``` "diamond functor" 비교기를 지정하면 이종 조회는 opt-in 방식으로 활성화된다. 
```c++
std::set<BigObject, std::less<>> myNewSet;
```

다음 프로그램 예에서는 ```std::set``` 컨테이너 사용자가 각 객체의 ```BigObject::id``` 멤버와 비교하기 위해서 단순하게 문자열을 전달할 수 있도록 ```operator<```의 오버로드하는 
방법을 보인다. 즉 myNewSet의 key인 BigObject와 string을 비교한다. BigObject는 기본적으로 자신의 id와 임시 객체 string의 비교 연산을 지원한다. 

기본 비교기를 사용하면 컨테이너는 C++11 및 이전 버전과 같이 동작한다.

```c++
#include <set>
#include <string>
#include <iostream>

using namespace std;

class BigObject
{
    string id;
public:   
    explicit BigObject(const string& s) : id(s) {}
    const string getid() const { return id; }
    bool operator< (const BigObject& other) const
    {
        return this->id < other.id;
    }
    friend bool operator<(const string& otherId, const BigObject& obj);
    friend bool operator<(const BigObject& obj, const string& otherId);
};

inline bool operator<(const string& otherId, const BigObject& obj)
{
    return otherId < obj.id;
}

inline bool operator<(const BigObject& obj, const string& otherId)
{
    return obj.id < otherId;
}

int main()
{
    // Use C++14 brace-init syntax to invoke BigObject(string).
    // The s suffix invokes string ctor. It is a C++14 user-defined
    // literal defined in <string>
    BigObject b1{ "42F"s };
    BigObject b2{ "52F"s };
    BigObject b3{ "62F"s };
    set<BigObject, less<>> myNewSet; // C++14
    myNewSet.insert(b1);
    myNewSet.insert(b2);
    myNewSet.insert(b3);
    auto it = myNewSet.find(string("62F"));
    if (it != myNewSet.end())
        cout << "myNewSet element = " << it->getid() << endl;
    else
        cout << "element not found " << endl;
    return 0;
}

//Output: myNewSet element = 62F
```

이종 조회를 지원하기 위해서 map, multimap, set, multiset의 다음 멤버 함수가 오버로드 되었다. 

* find
* count
* lower_bound
* upper_bound
* equal_range

### multimap
키-값(key-value) 쌍으로 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. ``map``과 같이 key 값으로 정렬되나 컨테이너 내의 key 값이 종복되어도 딘다. 

```c++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class multimap;
```

### multiset
키(key)로 이루어진 데이터를 저장하는 컨테이너로 클래스 템플릿(class template)이다. 컨테이너 내의 key 값은 중복이 되어도 되나 key 값으로 졍렬(sort)된다. 

```c++
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class multiset;
```
