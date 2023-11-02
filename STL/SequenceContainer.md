## Sequence Container
시퀀스 컨테이너는 사용자가 지정한 데이터의 순서가 유지되는 컨테이너이다.

### vector
``vector`` 컨테이너는 데이터 저장공간의 크기가 가변인 배렬처럼 동작하며 임의의 위치의 데이터를 직접 접근하며 연속적으로 저장된다. 
이러한 이유 때문에 대부분의 애플리케이션에서 주로 사용되는 시퀀스 퀀테이너 이다. 이떠한 시퀀스 컨테이너를 사용할지 명확치 않을 때는 ``vector`` 컨테이너를 사용한다.

C++ 표준 라이브러리 ``vector``클래스는 시퀀스 컨테이너의 클래스 템플릿이다. ``vector``는 주어진 자료형의 데이터(객체) 요소를 선형적으로 저장하고 
임의의 요소를 빠른 랜덤 액세스를 가능하게 한다. 

```c++
template <class Type, class Allocator = allocator<Type>>
class vector;
```

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

``vector`` 클래스의 멤버 함수는 다음과 같다. 

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
| resize | vector의 새 크기를 지정 |
| shrink_to_fit | 초과 용량을 페기 |
| size | vector의 요소수를 반환 |
| swap | 두 vector의 요소를 교환 |

``vector`` 클래스의 연산자는 다음과 같다.

|연산자 이름| 설명 |
|:---:|:---:|
| operator[] | 지정된 위치에 있는 vector 요소에 대한 참조를 반환 |
| operator= | vector 요소를 다른 vector의 복사본으로 바꿈 |

### arraay
``array`` 컨테이너는 ``vector`` 컨테이너의 장점을 가지나 크기가 고정되어 있다.

```c++
template <class Type, std::size_t N>
class array;
```
``array`` 클래스의 멤버 함수는 다음과 같다. 

|함수 이름| 설명 |
|:---:|:---:|
| array | array 객체의 생성자 |
| assign | 사용되지 않으며 (fill로 대체) 모든 요소를 대체 |
| at | array의 지정된 위치에 있는 요소에 대한 참조를 반환 |
| back | array의 마지막 요소에 대한 참조를 반환 |
| begin | array의 첫번째 원소에 대한 임의 엑세스 반복자를 반환 |
| cbegin | array의 첫 번째 요소에 대한 임의 액세스 const 반복자를 반환 |
| cend | varray 끝 바로 다음을 가르키는 임의 액세스 const 반복자를 반환 |
| crbegin | 반전된 arraydml 첫 번쨰 요소에 const 반복자를 반환 |
| crend | 반전된 array의 끝 요소에 const 반복자를 반환 |
| data | array의 첫 번쨰 요소에 대한 포인터를 반환 |
| empty | array에 요소가 있는지 테스트 |
| end | array의 끝을 가리키는 임의 액세스 반복자를 반환 |
| fill | array의 모든 요소를 지정된 값으로 변경 |
| front | array의 첫 번째 요소에 대한 참조를 반환 |
| max_size | array의 최대 킬이를 반환 |
| rbegin | 역방향 array의 첫 번쨰 요소에 대한 반복자를 반환 |
| rend | 역방향 array의 끝에 반복자를 반환 |
| size | array의 요소수를 반환 |
| swap | 두 array의 요소를 교환 |

``array`` 클래스의 연산자는 다음과 같다.

|연산자 이름| 설명 |
|:---:|:---:|
| array::operator[] | 지정된 위치에 있는 array 요소에 대한 참조를 반환 |
| array::operator= | array 요소를 다른 array의 복사본으로 바꿈 |


### deque
``deque``(double-ended queue) 컨테이너는 컨테이너의 앞과 뒤에서 데이터(객체)를 빠르게 삽입 삭제할 수 있도록 하는 컨테이로 랜덤 액세스와 저장공간의 크기가 
가변이라는 점에서 ``vector``의 장점을 가지나 데이터의 저장공간의 연속적이지 않다. 

```c++
template <class Type, class Allocator = allocator<Type>>
class deque;
```

|함수 이름| 설명 |
|:---:|:---:|
| assign | deque를 지우고 지정된 요소를 빈 deque에 복사 |
| at | deque의 지정된 위치에 있는 요소에 대한 참조를 반환 |
| back | deque의 마지막 요소에 대한 참조를 반환 |
| begin | deque의 첫번째 원소에 대한 임의 엑세스 반복자를 반환 |
| cbegin | deque의 첫 번째 요소에 대한 임의 액세스 const 반복자를 반환 |
| cend | deque 끝 바로 다음을 가르키는 임의 액세스 const 반복자를 반환 |
| clear | deque 요소를 지움 |
| crbegin | 반전된 deque의 첫 번쨰 요소에 const 반복자를 반환 |
| crend | 반전된 deque의 마지막 요소에 const 반복자를 반환 |
| emplace | 생성된 요소를 deque의 지정된 위치에 삽입 |
| emplace_back | deque의 끝에 생성된 요소를 추가 |
| emplace_front | deque의 시작 부분에 생성된 요소를 추가 |
| empty | deque 내에 데이터가 없으면 true, 하사 이상의 요소가 존재하는 경우 false 반환 |
| end | deque의 끝을 가리키는 임의 액세스 반복자를 반환 |
| erase | 지정된 위치에서 deque의 요소 또는 요소의 범위를 제거 |
| front | deque의 첫 번째 요소에 대한 참조를 반환 |
| get_allocator | ``allocator``  deque가 사용하는 클래스에 객체를 반환 |
| insert | deque의 지정된 위치ㅔ 하나 이상의 요소를 삽입 |
| max_size | deque의 최대 킬이를 반환 |
| pop_back | deque끝에 있는 요소를 삭제 |
| push_back | deque 끝에 요소를 추가 |
| rbegin | 역방향 deque의 첫 번쨰 요소에 대한 반복자를 반환 |
| rend | 역방향 deque의 끝에 반복자를 반환 |
| resize | deque의 새 크기를 지정 |
| shrink_to_fit | 초과 용량을 페기 |
| size | deque의 요소수를 반환 |
| swap | 두 deque의 요소를 교환 |

``deque`` 클래스의 연산자는 다음과 같다.

|연산자 이름| 설명 |
|:---:|:---:|
| operator[] | 지정된 위치에 있는 deque 요소에 대한 참조를 반환 |
| operator= | deque 요소를 다른 deque의 복사본으로 바꿈 |


### list
``list`` 컨테이너는 양방향 연결 리스트(double linked list)로 컨터이너로 데이터의 삽입과 삭제가 연결 리스트의 어디에서나 빠르게 이루이 질 수 있으나 
컨테이너 내의 데이터를 랜덤 액세스 할 수 없다.  

```c++
template <class Type, class Allocator = allocator<Type>>
class list;
```

|함수 이름| 설명 |
|:---:|:---:|
| assign | list를 지우고 지정된 요소를 빈 deque에 복사 |
| at | list의 지정된 위치에 있는 요소에 대한 참조를 반환 |
| back | list의 마지막 요소에 대한 참조를 반환 |
| begin | list의 첫번째 원소에 대한 임의 엑세스 반복자를 반환 |
| cbegin | list의 첫 번째 요소에 대한 임의 액세스 const 반복자를 반환 |
| cend | list 끝 바로 다음을 가르키는 임의 액세스 const 반복자를 반환 |
| clear | list 요소를 지움 |
| crbegin | 반전된 list의 첫 번쨰 요소에 const 반복자를 반환 |
| crend | 반전된 list의 마지막 요소에 const 반복자를 반환 |
| emplace | 생성된 요소를 list의 지정된 위치에 삽입 |
| emplace_back | list의 끝에 생성된 요소를 추가 |
| emplace_front | list의 시작 부분에 생성된 요소를 추가 |
| empty | list 내에 데이터가 없으면 true, 하사 이상의 요소가 존재하는 경우 false 반환 |
| end | liste의 끝을 가리키는 임의 액세스 반복자를 반환 |
| erase | 지정된 위치에서 list의 요소 또는 요소의 범위를 제거 |
| front | list의 첫 번째 요소에 대한 참조를 반환 |
| get_allocator | ``allocator``  list가 사용하는 클래스에 객체를 반환 |
| insert | list의 지정된 위치에 하나 이상의 요소를 삽입 |
| max_size | list의 최대 킬이를 반환 |
| merge | 인수 리스트에서 요소를 제고하고 대상 list에 삽입한 다음 새롭게 결합된 요소들을 오름차순 또는 기타 지정한 순서로 정렬 |
| pop_back | list끝에 있는 요소를 삭제 |
| pop_front | list의 시작 부분에 있는 요소를 삭제 |
| push_back | list 끝에 요소를 추가 |
| push_front | list 시작 부분에 요소를 추가 |
| rbegin | 역방향 list의 첫 번쨰 요소에 대한 반복자를 반환 |
| remove | 지정된 값과 일치하는 list의 요소를 삭제 |
| remove_if | list에서 지정된 조건자가 총종되는 요소를 삭제 |
| rend | 역방향 list의 끝에 반복자를 반환 |
| resize | list의 새 크기를 지정 |
| reverse | list에서 요소가 나타나는 순서를 반대로 바꿈 | 
| size | list의 요소 수를 반환 |
| sort | 오름차순이나 다른 순서 관계에 따라 list의 요소를 정렬 |
| splice | 인수 리스트에서 요소를 제거하고 대상 list에 삽입 |
| swap | 두 list의 요소를 교환 |
| unique | list에서 다른 이진 조건자를 만족하는 인접한 요소 또는 인접한 종복 요소를 제거 |

``list`` 클래스의 연산자는 다음과 같다.

|연산자 이름| 설명 |
|:---:|:---:|
| operator= | deque 요소를 다른 deque의 복사본으로 바꿈 |


### forward_list
``forward_list`` 컨테이너는 단방형 연결 리스트(singly linked list)로 ``list``의 순방향 접근 버전이다. 

```c++
template <class Type, class Allocator = allocator<Type>>
class forward_list;
```

|함수 이름| 설명 |
|:---:|:---:|
| assign | forward list를 지우고 지정된 요소를 빈 deque에 복사 |
| before_begin |       |
| begin | list의 첫번째 원소에 대한 임의 엑세스 반복자를 반환 |
| cbefore_begin |    |
| cbegin | list의 첫 번째 요소에 대한 임의 액세스 const 반복자를 반환 |
| cend | list 끝 바로 다음을 가르키는 임의 액세스 const 반복자를 반환 |
| clear | list 요소를 지움 |
| emplace_after |  |
| emplace_front | list의 시작 부분에 생성된 요소를 추가 |
| empty | list 내에 데이터가 없으면 true, 하사 이상의 요소가 존재하는 경우 false 반환 |
| end | liste의 끝을 가리키는 임의 액세스 반복자를 반환 |
| erase_after |  |
| front | list의 첫 번째 요소에 대한 참조를 반환 |
| get_allocator | ``allocator``  list가 사용하는 클래스에 객체를 반환 |
| insert_after |  |
| max_size | list의 최대 킬이를 반환 |
| merge | 인수 리스트에서 요소를 제고하고 대상 list에 삽입한 다음 새롭게 결합된 요소들을 오름차순 또는 기타 지정한 순서로 정렬 |
| pop_front | list의 시작 부분에 있는 요소를 삭제 |
| push_front | list 시작 부분에 요소를 추가 |
| rbegin | 역방향 list의 첫 번쨰 요소에 대한 반복자를 반환 |
| remove | 지정된 값과 일치하는 list의 요소를 삭제 |
| remove_if | list에서 지정된 조건자가 총종되는 요소를 삭제 |
| resize | list의 새 크기를 지정 |
| reverse | list에서 요소가 나타나는 순서를 반대로 바꿈 | 
| sort | 오름차순이나 다른 순서 관계에 따라 list의 요소를 정렬 |
| splice_after |  |
| swap | 두 list의 요소를 교환 |
| unique | list에서 다른 이진 조건자를 만족하는 인접한 요소 또는 인접한 종복 요소를 제거 |

``forward_list`` 클래스의 연산자는 다음과 같다.

|연산자 이름| 설명 |
|:---:|:---:|
| operator= | deque 요소를 다른 deque의 복사본으로 바꿈 |
