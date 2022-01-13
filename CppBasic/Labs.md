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
