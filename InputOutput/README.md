# InputOutput (입출력)

이 장에서는 C++ 언어의 입력, 출력에 대해서 다룬다. 

* 입력 스트림 (input stream): 
* 출력 스트림 (output stream): 
* 입 출력 객체
* cin 객체: input strem의 객체로 파일, 콘솔 등과 같은 입력 스트림(input stream)으로 부터 입력을 얻는데 사용된다. 
* cout 객체: output stream의 객체로 출력을 나타내는데 사용된다. 

## 화면 출력
화면에 데이터를 출력하기 위해서 ``cout`` 클래스롤 사용한다.
화면에 여러 데이터를 출력할 때 사용하는 연산자는 ``<<`` 를 사용한다. 
```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	cout << "Hello" << " " << "World!" << endl;
	return 0;
}
```
## 키보드 입력
키보드로 부터 데이터를 입력받기 위해서 ``cin`` 클래스를 사용한다.
키보드로 부터 여러 데이터를 입력받아 변수에 저장하기 위해서는 ``>>`` 연산자를 사용한다.
아래의 프로그램은 정수형 변수 ``x``, ``y``를 선언한 후 키보드로 부터 입력을 받아
``x``, ``y``에 저장한다. 

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int x, y;
  cout << "정수 2개 입력하시오: ";
  cin >> x >> y;
  cout << "x: " << x << " y: " << y << endl;
  cout << "x + y: " << x + y << endl;
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
## 키보드로 부터 데이터를 입력받아 배열에 저장하기

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10];
	for (int i = 0; i < 10; i++) cin >> arr[i];
	for (int j = 0; j < 10; j++) cout << arr[j] << " ";
	cout << endl;
	return 0;
}
```

