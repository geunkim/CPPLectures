# 프로그램 실습(Program Lab.)

1. 다음 프로그램 코드를 다운로드 한 후 화면에 Hello World!! 가 출력되도록 프로그램을 완성하시오([problem1](../SampleCodes/CPPBasic/problem1.cc))

```c++
#include <iostream>

int main(int argc, char const *argv[])
{
	// 다음 줄에 화면에 Hello World!! 를 출력하는 코드 작성
	
	return 0;
}
````

2. 키보드로 부터 정수 두 개를 입력받아 변수 ```first```, ```second```에 저장하고 화면에 출력하는 프로그램을 완성하시오.
```c++
#include <iostream>

int main(int argc, char const *argv[])
{
	int first, second;
	// 다음 줄에 앞에서 선언된 변수 first, second에 각각 10, 20을 저장하는 코드 작성

	cout << first << ", " << second << endl;
	return 0;
}
```

3. 키보드에서 Hello World! 를 입력한 것을 변수 buf에 저장하고 buf에 저장된 내용을 화면에 출력하는 프로그램을 완성하시오.

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char buf[255];
	
	// 다음 줄에 키보드로 부터 Hello World! 를 입력받아 buf 에 저장하는 코드 작성

	cout << buf << endl;

	return 0;
}
````
4. 다음 프로그램의 ```main``` 함수에서 10이 저장된 value와 20이 저장된 value를 출력하여 10과 20이 화면에 출력되도록 프로그램을 완성하시오.

```c++
#include <iostream>
#include <string>

using namespace std;
//

namespace my {
	int value = 10;
}

namespace your {
	int value = 20;
}

int main(int argc, char const *argv[])
{
	
	// 다음 줄에 10이 저장된 변수 value 값을 화면에 출력하는 코드 작성 


	// 다음 줄에 20이 저장된 변수 value 값을 화면에 출력하는 코드 작성

	return 0;
}
```

5. 아래의 프로그램을 실행하였을 때 아래와 같은 결과를 얻고자 한다. 실행 후 원하는 결과가 나오도록 수정하라.

원하는 결과

```bash
Hello
World
```

프로그램 코드 
```c++
#include <iostream>

int main()
{
	cout << "Hello";
	cout << "World";

	return 0;
}
```
6. 다음 프로그램 코드는 변수 ```a```에 저장된 값을 출력하고자 한다. 다음 프로그램을 컴파일하고 오류를 수정하고 원하는 결과가 나오도록 프로그램을 수정하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 20;

	cout << "a" 

	return 0;
}
```

7. 다음 프로그램 코드으 실행 결과과 다음과 같이 나오도록 변수 ```ch```를 선언하고 변수 ```value```의 값을 ```ch```에 복사하는 코드를 추가하시오.
```bash
65
A
```

```c++
int main(int argc, char const *argv[])
{
	int value = 65;  // 'A' 의 ASCII 값은 65 임 
	cout << value << endl;

	// value에 저장된 값을 변수 ch를 선언하고 value의 값을 ch에 복사하는 코드를 작성

	cout << ch << endl;

	return 0;
}
```

