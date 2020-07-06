#  Stream Class (스트림 클래스)

C++ 언어는 추상화 개념을 적용하여 스크린, 키보드 또는 파일과 같은 순차적인 미디어에서 입/출력 작업을 수행한다. 
C++ 언어에서 입/출력을 위한 기본 데이터 타입이 스트림(stream)이다. C++ 언어는 스트림 유형들의 복잡한 계층을 통합한다. 

```istram cin```: 빌트-인 입력스트림 변수; 기본적으로 키보드에 연결 
```ostream cout```: 빌트-인 출력스트림 변수; 기본적으로 콘솔에 연결

스트림은 데이터 시퀀스로 볼 수 있는 파일과 같은 객체를 초기화하는 프로세스와 객체 간의 연결을 제공한다. 
간단한 예로 스트림 객체는 단순하게 다른 객체의 직렬화된 것이다. 

스트림(Stream) 객체는 프로세스가 데이터에 접근할 수 있는 인터페이스를 제공한다. 즉, 스트림 프로그램이 문자를 삽입하거나 추출할 수 있도록 하는 클래스이다. 

추상화 덕분에 프로그래머는 스트림 관련 미다어에 대한 상세 정보 또는 내부 명세를 알 필요가 없다. 
스트림은 문자의 입력 소스 이머 출력 대상으로 문자를 순차적(차례로) 입력되고 출력된다. 

표준 라이브러리는 프로그램이 실행되는 환경에서 문자의 표준 입력 소스와 출력 대상으로 고려되는 것을 액세스하는데 사용될 수 있는 
다음과 같은 스트림 객체를 정의한다. 
``cin``과 ``cout``은 C++ ``istream``과 ``ostrem`` 클래스의 객체이다. 

<table align = "center">
<tr align = "center"><td>스트림(stream)</td><td>설명</td></tr>
<tr align = "center"><td>cin</td><td>표준 입력 스트림</td></tr>
<tr align = "center"><td>cin</td><td>표준 출력 스트림</td></tr>
<tr align = "center"><td>cerr</td><td>표준 에러 (출력) 스트림</td></tr>
<tr align = "center"><td>clog</td><td>표준 로깅 (출력) 스트림</td></tr>
</table>

* cin 객체: input strem의 객체로 파일, 콘솔 등과 같은 입력 스트림(input stream)으로 부터 입력을 얻는데 사용된다. 
* cout 객체: output stream의 객체로 출력을 나타내는데 사용된다. 

## 출력: 삽입 연산자(insertion operator)

파일 또는 프로그램에서 정보를 얻기 위해서는 컴퓨터가 원하는 정보를 출력하도록 명시적으로 지시하여야 한다. 
이것을 C++ 에서 구현하는 방법 중 하나가 출력스트림(output stream)을 사용하는 것이다. 

표준 입출력 스트림을 사용하기 위해서 우리의 프로그램은 아래와 같이 사전에 컴파일된 지시어를 포함하여야 한다.
```cpp
#include <iostream>
```

콘솔 화면에 출력하기 위해서는 다음과 같은 명령어를 사용하기만 하면 된다.

```cpp
cout << "x: " <<  x;
```
x 라는 변수 또는 상수에 저장된 내용을 화면에 출력하기 위해 사용하는 명령어이다.

출력스트림에 대한 삽입 연산은 여러 개를 체인으로 연결할 수 있다. 삽입 연산 명령문의 가장 왼쪽은 ```cout```과 같은 
출력스트림 변수의 이름이어야 한다. 

### 화면 출력
변수 또는 상수의 이름을 삽입하는 것은 객체의 값을 스트림에 쓰여지게 한다. 
```cpp
#include <iostrem>
using namespace std;
int main(int argc, char const *argv[])
{
  const string Label = "The count value: ";
  int count = 200;
	cout << Label << count << endl;
	return 0;
}
```

화면에 데이터를 출력하기 위해서 ``cout`` 클래스롤 사용한다.
화면에 여러 데이터를 출력할 때 사용하는 삽입 연산자(``<<``) 를 사용한다. 

cout 출력할 때 기본적으로 정렬, 줄바꿈 등과 같은 특수 형식을 제공되지 않는다. 특수한 출력 형식의 지정은 프로그래머에 의해서 
제어되어야 한다. 

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	cout << "Hello" << " " << "World!" << endl;
	return 0;
}
```

## 배열 데이터 출력

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10];
	for(int i = 0; i < 10; i++)  arr[i] = 2 * i;
	for(int j = 0; j < 10; j++) cout << arr[j] << " " ;
	cout << endl;
	return 0;
}
```



