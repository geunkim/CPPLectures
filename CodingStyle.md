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

```c++
class TableInfo {
  ...
 private:
  std::string table_name_;  // OK - underscore at end.
  static Pool<TableInfo>* pool_;  // OK.
};
```

####  구조체 데이터 멤버(Struct Data Members)

구조체의 데이터 멤버(static 과 non-static)는 일반 비멤버 변수처럼 이름이 지정되지만 클래스의 데이터 멤버와 달리 이름 뒤에 밑줄을 사용하지 않는다. 

```c++
struct UrlTableProperties {
  std::string name;
  int num_entries;
  static Pool<UrlTableProperties>* pool;
};
````

### 상수 이름(Constant Names)

```constexpr``` 또는 ```const```로 선언되고 프로그램이 실행되는 동안 값이 고정된 변수들은 변수 앞에 문자 "k"로 시작되고 대소문자를 붙인다. 분리를 위해 대문자를 할 수 없는 경우 밑줄을 구분자로 사용할 수 있다. 

```c++
const int kDaysInAWeek = 7;
const int kAndroid8_0_0 = 24;  // Android 8.0.0
``

정적 저장공간에 저장되어 프로그램 실행동안 저장공간을 유지하는 변수는 이러한 방식으로 몀명한다. 자동 변수와 같은 다른 저장 장소 클래스의 변수는 이 규칙이 선택사항이며 그 외에는 일반적인 변수의 규칙을 적용한다.

### 함수 이름(Function Names)

정규 함수는 대소문자를 혼합하여 사용되며 접근자와 변경자는 변수와 같이 이름을 지정할 수 있다. 
일반적으로 함수는 대문자로 시작하고 새로운 단어마다 대문자로 사용한다.

```c++
AddTableEntry()
DeleteUrl()
OpenFileOrDie()
```

동일한 명명 규칙이 API의 일부로 노출되어 함수처럼 보이는 클래스 및 이름공간 범위 상수에 적용된다. 
접근자 및 변경자(get 그리고 set함수)는 변수처럼 명명될 수 있다. 이 경우 실제 멤버 변수와 일치하지만 
반드시 일치할 필요는 없다. 예를 들어 ```int count()```와 ```void set_count(int count)```가 가능하다.

### 이름공간 이름(Namespace Names)

이름공간 이름은 소문자를 사용하며 밑줄로 단어를 분리한다. 최상위 레벨 이름공간 이름은 프로젝트 이름에 기반하여 중첩된 이름공간과 잘 알려진 이름공간 간의 충동을 피하여야 한다.
최상위 레벨 이름공간의 이름은 일반적으로 해당 이름공간에 코드가 포함된 프로젝트 또는 팀의 이름이어야 한다. 해당 이름공간의 코드는 일반적으로 기본 이름이 이름공간 이름과 일치하는 디렉토리 (또는 그 하위 디렉토리)에 있어야 한다. 

축약된 이름에 대한 규칙은 변수 이름만큼 이름공간에도 적용된다는 점을 명심해야 한다. 이름공간 내부의 코드는 이름공간 이름을 언급할 필요가 거의 없기 때문에 일반적으로 어쩄든 약어를 필요하지 않는다. 

잘 알려진 최상위 이름공간과 일치하는 중첩된 이름공간을 피해야 한다. 이름공간 이름 간의 충돌은 이름 조회 규칙 때문에 빌드가 중단될 수 있다. 특히 중첩된 std 이름공간을 생성하지 말아야 한다. ```websearch::util```과 같이 충돌하기 쉬운 이름보다 고유한 프로젝트 식별자(```webserarch::index```, ```websearch::index_util```)를 선호한다. 또한 지나치게 깊은 중첩의 이름공간은 피해야 한다.

내부 이름공간의 경우 충돌을 일으키는 동일한 내부 이름공간에 다른 코드가 추가되지 않도록 주의해야 한다. 이러한 상황에서 파일 이름을 사용하여 고유한 내부 이름을 만드는 것이 도움이 된다. 

### 열거형 이름(Enumerator names)

범위가 지정된 열거형과 범위가 지정되지 않은 열거형은 모두 매크러가 아닌 상수처럼 이름을 지정되어야 한다. 즉 ```ENUM_NAME```이 아닌 ```kEnumName```을 사용한다. 


```c++
enum class UrlTableError {
  kOk = 0,
  kOutOfMemory,
  kMalformedInput,
};
```

```c++
enum class AlternateUrlTableError {
  OK = 0,
  OUT_OF_MEMORY = 1,
  MALFORMED_INPUT = 2,
};
```
2009년 1월까지 매크로와 같이 열거값의 이름을 붙이는 방식이 사용되었다. 이 때문에 열거값과 매크로 간의 이름 충돌 문제가 발생했다.
따라서 상수 스타일의 명명을 선호하는 변경 사항이 적용되었다. 새로운 코드는 상수 스타일 명명을 사용해야 한다. 

### 매크로 이름(Macro Names)

매크로 이름은 모두 대문자와 밑줄로 이름을 지정해야 한다. 

```c++
#define ROUND(x) ...
#define PI_ROUNDED 3.0
```

### 명명 규칙의 예외(Exceptions to Naming Rules) 

기존 C 또는 C++ 엔티티와 유사한 것에 명명을 하는 경우 기존 명명 규칙 체계를 따를 수 있다. 

```bigopen()```: ```open()```형식을 따르는 함수 이름 

```uint```: typedef

```bigpos```: ```pos```형식을 따르는 구조체, 클래스

```sparse_has_map```: STL 명명 규칙을 따르는 STL 유사한 엔티티

```LONGLONG_MAx```: ```INT_MAX```와 같은 상수


## 주석 (Comments)

### 주식 스타일

### 파일 주석

### 타입 주석

### 함수 주석

### 변수 주석

### 구현 주석

### 구두점, 철자 및 문법


### TODO 주석

## 함수 (Functions)


## 클래스 (Class)














 ## 참고자료 
 
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
  - Google에서 C++를 이용하여 개발된 대부분의 오픈소스 프로젝트에서 따르고 있는 C++ 코딩 지침으로 C++17을 대상으로 한다.
  - 지정된 초기화를 제외하고 C++2x 기능을 사용하지 않는다.
  - 비표준 확장(non-standard exensions)을 사용하지 않는다. 
  - 프로젝트에서 C++14와 C++17의 기능을 사용하기 전에 다른 환경으로 이식성을 고려할 필요가 있다. 
 
