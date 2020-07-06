# 출력스트림(Output Stream)

* ```cout``` 객체: output stream의 객체로 출력을 나타내는데 사용된다. 
* ```endl```
```endl```은 manipulator(조정자)이다. 조정자는 출력과 입력 값의 형식을 제어하는데 사용되는 C++ 구문이다. 



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



