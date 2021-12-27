# Problems

1. 다음 프로그램 코드를 다운로드 한 후 화면에 Hello World!! 가 출력되도록 프로그램을 완성하시오([problem1](../SampleCodes/CPPBasic/problem1.cc))

```c++
#include <iostream>

int main(int argc, char const *argv[])
{
	
	return 0;
}
````

2. 키보드로 부터 정수 두 개를 입력받아 변수 ```first```, ```second```에 저장하고 화면에 출력하는 프로그램을 완성하시오.
```c++
#include <iostream>

int main(int argc, char const *argv[])
{
	int first, second;


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
	

	cout << buf << endl;

	return 0;
}
