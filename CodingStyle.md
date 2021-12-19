# 코딩 스타일(Coding Style)

## 이름 규칙(Naming)

프로그램에서 가장 중요한 일관성이 요구되는 규칙은 이름 지정을 제어하는 규칙이다. 
이름의 스타일(The style of a name)은 이름이 지정된 요소(entity)가 타입, 변수, 함수, 상수 혹은 매크로 등 해당 요소의 선언을 검색하지 않고도 해당 요소가 어떤 종류인지 바로 알 수 있어야 한다. 
우리 두뇌의 패턴 매칭 엔진은 이러한 명명 규칙에 크게 의존한다.  

명명 규칙은 개인의 선호도보다 일관성이 더 중요하기 때문에 합리적인지 여부에 관계없이 정해진 규칙은 지켜야 한다.

### 일반 이름 규칙(General Naming Rules)

다른 팀의 구성원이 알아볼 수 있는 이름을 사용하여 가독성을 최적화한다. 
대상의 목적이나 의도를 설명하는 이름을 사용한다. 새로운 개발자가 코드를 즉시 이해할 수 있도록 하는 것이 중요하기 때문에 가로 공간 절약을 걱정하지 말자.
프롲게트 외부의 누구에게 알려지지 않았을 가능성이 있는 약어, 특히 두문자어(acronyms)와 이니셜(initialisms), 의 사용을 최소화하여야 한다.
단어의 글자를 삭제하여 축약하지 않는다. 
아래 예시의 코드에서 ```n```이 5줄 함수에서는 좋은 이름일 수 있으나 클래스 범위에서는 의미가 모호할 수 있다. 

```c++
class MyClass {
 public:
  int CountFooErrors(const std::vector<Foo>& foos) {
    int n = 0;  // Clear meaning given limited scope and context
    for (const auto& foo : foos) {
      ...
      ++n;
    }
    return n;
  }
  void DoSomethingImportant() {
    std::string fqdn = ...;  // Well-known abbreviation for Fully Qualified Domain Name
  }
 private:
  const int kMaxAllowedConnections = ...;  // Clear meaning within context
};
```

앞의 코드의 변수 ```n```이라는 대신 ```total_number_of_foo_errors```라는 이름을 사용하여 모호성을 없앨 수 있다.

```c++
class MyClass {
 public:
  int CountFooErrors(const std::vector<Foo>& foos) {
    int total_number_of_foo_errors = 0;  // Overly verbose given limited scope and context
    for (int foo_index = 0; foo_index < foos.size(); ++foo_index) {  // Use idiomatic `i`
      ...
      ++total_number_of_foo_errors;
    }
    return total_number_of_foo_errors;
  }
  void DoSomethingImportant() {
    int cstmr_id = ...;  // Deletes internal letters
  }
 private:
  const int kNum = ...;  // Unclear meaning within broad scope
};
``` 
반복 변수로 ```i```, 탬플릿 매개변수로 ```T```를 사용하는 것과 같이 보편적으로 알려진 특정 약어는 괜찮다. 
다음 명명 규칙의 목적을 위해 단어는 내부 공백 없이 영어로 작성한다. 이 경우에는 두문자어 및 이니셜과 같은 약어가 포함된다. 
대소문자가 혼합된 이름("카멜 표기법" 또는 "파스칼 표기법" 이라고도 함)의 경우 각 단어의 첫 글자는 대문자로 쓴다.  
혼합 대소문자에서는 StarRPC()보다는 StartRpc()와 같이 단일 단어를 대문자로 쓰는 것을 선호한다. 

제 3자에게 익숙하지 않는 약얼르 사용하지 않으며 축약하지 않는다. 

```c++

// 나쁜 예 
int n;                // 의미 없음 
int nerr;             // 모호한 축약
int n_comp_conns;     // 모호한 축약
int wgc_connections;  // 내부자만 아는 약어
int_pc_reader;        // pc의 의미?
int cstmr_id;         // 중간 단어 축약

// 좋은 예
int price_count_reader.  // 축약 없음
int num_of_errors;       // 이해 가능
```

### 파일 이름(File Names)

* 파일 이름은 모두 소문자이어야 하며 밑줄(\_) 또는 대시(\-)를 포함할 수 있다. 프로젝트에서 사용하는 규칙을 따르는데 일관된 로컬 패턴이 없으면 밑줄(\_)을 사용한다.
사용가능한 파일 이름의 예는 다음과 같다. 

 - my_useful_class.cc
 - my-useful-class.cc
 - myusefulclass.cc
 - myusefulclass_test.cc

* C++ 파일은 ```.cc``로 끝나야 하고 해더 파일은 ```.h```로 끝나야 한다. 특정 지점에 텍스트로 포함되어야 하는 파일은 ```.inc```로 끝나야 한다. 

* 이미 존재하는 파일 이름은 사용하지 않는다. 예로 ```/usr/include```에 이미 존재하는 파일 이름은(예: db.h, error.h 등)를 사용하지 않는다. 

* 일반적으로 파일 이름을 구체적으로 만든다. 
예를 들어 ```log.h```대신 ```http_server_logs.h```를 사용한다. 
매우 일반적인 경우 ```foo_bar.h```와 ```foo_bar.cc``라는 이름의 파일 쌍을 갖는다. 

* 인라인 함수는 헤더파일에 정의한다. 
인라인 함수의 코드가 짧으면 ```.h```헤도 파일 안에 정의하고 길면 ```-ini.h``` 헤더 페일안에 정의한다.



### 타입 이름(Type Names)

타입 이름은 대문자로 시작하고 MyExcitingClass, MyExcitingEnum가 같이 밑줄이 없는 각 세 단어에 대해 대문자로 시작한다.
클래스(class), 구조체(struct), 형식 별명(type alias), 열거형(enums) 및 형식 템플릿 매개변수(type template parameter)와 같은 모든 타입의 이름에는 
동일한 몀명 규칙이 있다. 타입 이름은 대문자로 시작하고 각 단어마다 대문자를 사용하며 밑줄은 없다.

예는 다음과 같다.

```c++
// classes and structs
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...

// typedefs
typedef hash_map<UrlTableProperties *, std::string> PropertiesMap;

// using aliases
using PropertiesMap = hash_map<UrlTableProperties *, std::string>;

// enums
enum class UrlTableError { ...
```

### 변수 이름(Variable Names)

함수 매개변수를 포함한 변수의 이름과 데이터 멤버는 모두 소문자로 적상하며 단어 사이에 밎줄(\_)을 사용한다.
지역변수, 전역변수, 구조체 변수 모두 동일하다. 
클래스의 데이터 멤버(구조체는 제외)는 추가로 후행 밑줄이 있다. 
예는 다음과 같다. 

```c++
a_local_variable
a_struct_data_member
a_class_data_member_
```

##### 공통 변수 이름(Common Variable names)

```c++
std::string table_name;  // 좋음 - 밑줄을 사용한 소문자
std::string tableName;   // 나쁨 - 대소문자 혼합 사용
```

#### 클래스 데이터 멤버(Class Data Members)

클래스의 데이터 멤버(static 과 non-static)는 일반 비멤버 변수처럼 이름이 지정되지만 뒤에 밑줄을 표시한다.


### 상수 이름(Constant Names)

### 함수 이름(Function Names)

### 이름 공간 이름(Namespace Names)

### 열거형 이름(Enumerator names)

### 매크로 이름(Macro Names)

### 명명 규칙의 예외(Exceptions to Naming Rules) 



## 함수 (Functions)


## 클래스 (Class)














 ## 참고자료 
 
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
  - Google에서 C++를 이용하여 개발된 대부분의 오픈소스 프로젝트에서 따르고 있는 C++ 코딩 지침으로 C++17을 대상으로 한다.
  - 지정된 초기화를 제외하고 C++2x 기능을 사용하지 않는다.
  - 비표준 확장(non-standard exensions)을 사용하지 않는다. 
  - 프로젝트에서 C++14와 C++17의 기능을 사용하기 전에 다른 환경으로 이식성을 고려할 필요가 있다. 
 
