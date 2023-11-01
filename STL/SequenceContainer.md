## Sequence Container
시퀀스 컨테이너는 사용자가 지정한 데이터의 순서가 유지되는 컨테이너이다.

### vector
``vector`` 컨테이너는 데이터 저장공간의 크기가 가변인 배렬처럼 동작하며 임의의 위치의 데이터를 직접 접근하며 연속적으로 저장된다. 
이러한 이유 때문에 대부분의 애플리케이션에서 주로 사용되는 시퀀스 퀀테이너 이다. 이떠한 시퀀스 컨테이너를 사용할지 명확치 않을 때는 ``vector`` 컨테이너를 사용한다.

C++ 표준 라이브러리 ``vector``클래스는 시퀀스 컨테이너의 클래스 템플릿이다. ``vector``는 주어진 자료형의 데이터(객체) 요소를 선형적으로 저장하고 
임의의 요소를 빠른 랜덤 액세스를 가능하게 한다. 

```c++
template <class Type, class Allocator = allocator<Type>>
class vector
```
``vector`` 클래스의 멤버 함수는 다음과 같다. 

#### 클래스 텦플릿 ``vector``의 정의가 있는 C++ 표준 라이브러리 해터 파일 vector의 내용 일부
```c++
namespace std {
template <class Type, class Allocator = allocator<Type>>
class vector {
public:
    typedef T                                        value_type;
    typedef typename allocator_type::size_type       size_type;
    ...
    vector() noexcept(is_nothrow_default_constructible<allocator_type>::value);
    ~vector();
    // functions

    void push_back(const value_type& x);
    void push_back(value_type&& x);

    // operator
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
            noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    void assign(size_type n, const value_type& u);
    ...
    iterator begin() noexcept;
    iterator end() noexcept;
    ...
    reference front();
    reference back();
    패ㅑd resize(size_type sz);
    value_type* data() noexcept:
    ...
    };

} // namespace std
```

|함수 이름| 설명 |
|:---:|:---:|
| assign | vector를 지우고 지정된 요소를 빈 벡터에 복사 |
| at | vector의 지정된 위치에 있는 요소에 대한 참조를 반환 |
| back | vector의 마지막 요소에 대한 참조를 반환 |
| begin | vector의 첫번째 원소에 대한 임의 엑세스 반복자를 반환 |
| capacity | 추가 저장 광간을 활당하지 않고 vector에 포함될 수 있는 요소 수를 봔환|
| cbegin | vector의 첫 번째 요소에 대한 임의 액세스 const 반복자를 반환 |
| cend | vector 끝 바로 다음을 가르키는 임의 액세스 const 반복자를 반환 |
| crend | 반전된 vector의 첫 번쨰 요소에 const 반복자를 반환 |
| clear | vector 요소를 지움 |
| data | vector의 첫 번쨰 요소에 대한 포인터를 반환 |
| emplace | 생성된 요소를 vector의 지정된 위치에 삽입 |
| emplace_back | vector의 끄에 생성된 요소를 추가 |
| end | vector의 끝을 가리키는 임의 액세스 반복자를 반환 |
| erase | 지정된 위치에서 vector의 요소 또는 요소의 범위를 제거 |
| front | vector의 첫 번째 요소에 대한 참조를 반환 |
| get_allocator | ``allocator``  vector가 사용하는 클래스에 객체를 반환 |
| insert | vector의 지정된 위치ㅔ 하나 이상의 요소를 삽입 |
| max_size | vector의 최대 킬이를 반환 |
| pop_back | vector끝에 있는 요소를 삭제 |
| push_back | vector끝에 요소를 추가 |
| rbegin | 역방향 vector의 첫 번쨰 요소에 대한 반복자를 반환 |
| rend | 역방향 vector의 끝에 반복자를 반환 |
| reserve | vector 객체에 대한 최소 저장 길이를 예약 |
| resize | vector의 새 크기를 지정 
| shrink_to_fit | 초과 용량을 페기 |
| size | vector의 요소수를 반환 |
| swap | 두 vector의 요소를 교환 |

``vector`` 클래스의 연산자는 다음과 같다.

|연산자 이름| 설명 |
|:---:|:---:|
| operator[] | 지정된 위치에 있는 vector 요소에 대한 참조를 반환 |
| operator= | vector 요소를 다른 vector의 복사본으로 바꿈 |

### arraay
``array`` 컨테이너는 ``vector`` 컨테이너의 잔점을 가지나 크기가 고정되어 있다.

### deque
``deque``(double-ended queue) 컨테이너는 컨테이너의 앞과 뒤에서 데이터(객체)를 빠르게 삽입 삭제할 수 있도록 하는 컨테이로 랜덤 액세스와 저장공간의 크기가 
가변이라는 점에서 ``vector``의 장점을 가지나 데이터의 저장공간의 연속적이지 않다. 

### list
``list`` 컨테이너는 양방향 연결 리스트(double linked list)로 컨터이너로 데이터의 삽입과 삭제가 연결 리스트의 어디에서나 빠르게 이루이 질 수 있으나 
컨테이너 내의 데이터를 랜덤 액세스 할 수 없다.  

### forward_list
``forward_list`` 컨테이너는 단방형 연결 리스트(singly linked list)로 ``list``의 순방향 접근 버전이다. 

