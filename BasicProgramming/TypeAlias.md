# 자료형 별칭(Type Alias)

C++ 표준 버전인 C++11에서 자료형에 대한 별칭으로 ```typedef```키워드 이외에 ```using``` 키워드를 이용하여 자료형(type) 및 기타 구조체에 대한 별칭(Alias)을
```using``` 키워드 사용이 가능해졌다. 길고 복잡한 자료형 이름을 간단하게 쓰기위한 용도로 만이 사용한다. 
별칭 선언은 이전에 선언된 자료형에 대해 동의어(synonym)으로 사용할 이름을 선언하는데 사용할 수 있다. 
사용자 지정 할당자에 유용할 수 있는 별칭 템플릿(alias template)을 생성하기 위해 이 메커니즘을 사용할 수 있다.

C와 이전 버전의 c++ 에서는 자료형에 대해서 별칭을 선언하기 위해서 ```typedef``` 키워드를 사용하였다. 
C++11 에서 등장한 ```using``` 키워드를 이용한 자료형 별칭은 기존의 ```typedef``` 키워드보다 개선된 방식이다.

```using``` 키워드를 사용한 별칭 선언의 구문을 다음과 같다.

```c++
using identifier attr(optional) = type;

template <template-parameter-list>
using identifier attr(optional) = type;
```

여기서 *identifer* 는 별칭의 이름이고 *type*은 별칭을 만드는 자료형의 식별자이다. 
별칭은 새로운 자료형을 만들지 않으며 기존 자료형 이름의 의미를 변경할 수 없다. 

다음은 C++03의 ```typedef``` 메커니즘과 동일한 별칭의 단순한 형식이다. 두 경우 모두 "counter" 자료형의 변수를 생성할 수 있도록 한다.

```c++
// C++11
using counter = long;

// C++03 equivalent:
typedef long counter;
```
```typedef```는 긴 자료형 이름을 짧은 자료형 이름을 줄이는 모습에 가까우며 ```using```을 이용한 별칭은 선언의 모습에 가깝다. 
가독성 측면에서는 ```usng```이 ```typedef```보다 더 좋아진다.

더 유용한 것은 ```std::ios_base::fmtflags```에 대한 다음과 같은 자료형 별칭이다. 

```c++
// C++11
using fmtfl = std::ios_base::fmtflags;
using UserMap = std::unordered_map<int, std::string>>;

// C++03 equivalent:
typedef std::ios_base::fmtflags fmtfl;
typedef std::unordered_map<int, std::string>> UserMap;

fmtfl fl_orig = std::cout.flags();
fmtfl fl_hex = (fl_orig & ~std::cout.basefield) | std::cout.showbase | std::cout.hex;
// ...
std::cout.flags(fl_hex);
```

## 함수 포인터 별칭 

별칭은 함수 포인터에서 사용될 수 있으며 ```typedef```보다 가독성이 뛰어나다. 

```c++
// C++11
using func = void(*)(int);

// C++03 equivalent:
typedef void (*func)(int);

// func can be assigned to a function pointer value
void actual_function(int arg) { /* some code */ }
func fptr = &actual_function;
```

## 템블릿 별칭

```typedef``` 메커니즘의 제약사항은 템플릿과 동작하지 않는 것이다. 그러나 C++11 의 
자료형 별칭 구문은 템플릿 별칭을 만들 수 있도록 한다. 

```c++
//C++11
template <typename T>
using xvector = vector<T, xallocator<T>>;

xvector<int> idList {1, 2, 3};


// C++03 equivalent;
template <typename T>
struct xvector
{
  typedef vector<T, xallocator<T>> type;    
}
// 
xvector<int>::type idList {1, 2, 3};
```

```c++
// C++11
template<typename T> using ptr = T*;
// the name 'ptr<T>' is now an alias for pointer to T
ptr<int> ptr_int;

// C++03 equivalent:
template<typename T>
struct ptr
{
  typedef T* type;
};
ptr<int>::type ptr_int;
```

## 예(Example)




참고자료

* [Aliases and typedefs (C++)](https://docs.microsoft.com/en-us/cpp/cpp/aliases-and-typedefs-cpp?redirectedfrom=MSDN&view=msvc-170)
* [Type alias, alias template (in cppreference.com](https://en.cppreference.com/w/cpp/language/type_alias)
