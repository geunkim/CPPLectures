# Labs - Basic Programming

1. 다루려는 정수의 값의 범위가 60,000 이하의 양수인 데이터를 저장할 변수 ```a```, ```b```를 선언 시 적절한 자료형을 결정하고, 
두 수를 더한 결과와 두 수를 곱한 결과를 저장할 수 있는 변수 ```result``` 를 선언하고 연산 결과를 저장한 후 저장된 값을 출력하는 프로그램을 작성하고자 한다.

다음 프로그램 코드를 완성하라.
   
```c++  
#include <iostream>
using namespace std;
   
int main(int argc, char const *argv[])
{
	// 다음 줄에 두 수를 더하고 result 변수에 저장하는 연산 코드를 작성  

	cout << "두 수 덧셈 결과: " << result << endl;

	// 다음 줄에 두 수를 곱하고 result 변수에 저장하는 연산 코드를 작성

	cout << "두 수 곱셈 결과: " << result << endl;

	return 0;
}
```
프로그램 실행 결과는 다음과 같아야 한다. 

```bash
두 수 덧셈 결과: 350
두 수 곱셈 결과: 30000
```
      
2. 1번 문제에서 변수 ```a```, ```b``` 각각에 1500, 2000 을 저장한 후 프로그램 실행 결과를 확인하고 문제가 발생하는지 확인하시오. 또한 15000, 20000 을 저장한 후에 실행 결과도 함께 확인하라.

3. 다음 코드를 실행시키면 화면에 ```15/4 = 3``` 가 출력된다. 그러나 프로그램의 실행 결과로 화면에 ```15/4 = 3.75```가 출력되어야 한다. 프로그램 실행 결과가 원하는 결과가 나오는지 확인하고 원하는 결과가 나오지 않는다면 이유를 추론하고 화면에 정확한 결과가 출력되도록 프로그램 코드를 수정하고 .

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int dividend = 15;
	int divisor = 4;
	double result;

	result = dividend / divisor;

	cout << dividend << "/" << divisor << " = " << result << endl;


	return 0;
}
```
4.  다음 코드의 실행 결과가 ```a: 100, b: 400```가 출력되도록 프로그램 코드 추가 영역 아래에 변수 ```a```와 ```b```에 대하 다음 기능을 수행하도록 코드를 추가하라. (a에 100을 대입하고 b에는 a에 저장된 값의 4배한 값을 대입하는 코드를 추가하라.) 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	// 프로그램 코드 추가 영역 
	
	
	cout << "a: " << a << ", ";
	cout << "b: " << b << endl;

	return 0;
}
```
5. 다음 프로그램 코드를 실행하고 실행 결과를 분석하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 100, b = 200;
	double c = 10.123, d = 20.456;

	cout << "a: " << a << ", ";
	cout << "b: " << b << ", ";
	cout << "c: " << c << ", ";
	cout << "d: " << d << endl;

	a = c;
	b = d;

	cout << "a: " << a << ", ";
	cout << "b: " << b << endl;

	return 0;
}
```
6. 다음 프로그램 코드를 실행하기 전 각 연산을 수행한 결과를 추론해 보고 추론한 결과로 출력이 되는지 확인해 보고 프로그램을 실행하여 확인하라. 
또한 프로그램 코드 내의 질문 1에서 부터 질문 5까지 질문에 대한 답을 기술하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 2, b = 3, c = 4;

	// 질문 1: +, * 의 연산 우선순위
	// 출력 1
	cout << "[출력 1] " << a + b * c << endl;
	// 출력 2
	cout << "[출력 2] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 질문 2: +=, *= 연산자 의미
	a += b;
	b *= c++;

	// 출력 3
	cout << "[출력 3] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	c %= a;

	// 출력 4
	cout << "[출력 4] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 질문 3: =, +,-- 순서 
	c = b + --a;

	// 출력 5
	cout << "[출력 5] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 질문 4: =, +, -- 순서 
	c = b + a--;

	// 출력 6
	cout << "[출력 6] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	// 잘문 5: 후위 증가와 전위 증가의 차이점 
	b = c++;  // 후위 증가
	c = ++a;  // 전위 증가
	// 출력 7
	cout << "[출력 7] a: " << a << ", " << "b: " << b << ", " << "c: " << c << endl;

	return 0;
}
```

7. 다음 프로그램 코드의 연산 결과를 추론하고 실행 결과와 같은지 확인하고 결과 값의 근거를 설명하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a = 100, b = 200, c = 300;
	char d ='a', e = 'A', f = 'b';


	cout << (d == f) << endl;
	cout << (d == (f -1)) << endl;
	cout << (a > b) << endl;
	cout << (a < c) << endl;
	cout << (e != f) << endl;

	return 0;
}
```
8. 다음 프로그램 코드의 연산 결과를 추론하고 실행 결과와 같은지 확인하고 결과 값의 근거를 설명하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	bool a = true, b = false;
	int c = 10, d = 20;


	cout << "[출력 1]: " << !b << endl;      		// 논리 부정
	cout << "[출력 2]: " << (a && b) << endl;  		// 논리 곱 
	cout << "[출력 3]: " << (a || b) << endl;  		// 논리 합

	cout << "[출력 4]: " << (c != d || a) << endl;  // 관계 연산과 논리 합
	cout << "[출력 5]: " << (c < d && b) << endl;   // 관계 연산과 논리 곱

	cout << "[출력 6]: " << (c > 5 && c < 15) << endl; 	// 관계 연산자와 논리 곱
	cout << "[출력 7]: " << (c <= 5 || c >=15) << endl;   // 관계 연산자와 논리 합

	return 0;
}
```

9. 다음 프로그램 코드의 실행 결과를 추론한 후 실행 결과와 같은지 확인하고 결과 값의 근거를 설명하라.

```c++
include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	unsigned short value = 0xffff;
	unsigned short mask1 = 0x00ff;
	unsigned char mask2 = 0x77;
	unsigned char mask3 = (unsigned char)01010101;
	unsigned char mask4 = (unsigned char)10101010;


	cout << "[출력 1]: " << value << endl;
	cout << "[출력 2]: " << mask1 << endl;
	cout << "[출력 3]: " << (int)mask2 << endl;
	cout << "[출력 4]: " << (int)mask3 << endl;
	cout << "[출력 5]: " << (int)mask4 << endl;		

	cout << "[출력 - 1]: " << (value & mask1) << endl;
	cout << "[출력 - 2]: " << (value & mask2) << endl;
	cout << "[출력 - 3]: " << (mask3 & mask4) << endl;
	cout << "[출력 - 4]: " << (mask3 | mask4) << endl; 
	cout << "[출력 - 5]: " << (mask3 ^ mask4) << endl; 
	cout << "[출력 - 6]: " << (mask3 | !mask4) << endl; 

	return 0;
}
```

10. 다음 프로그램 코드의 실행 결과를 추론한 후 실행 결과와 같은지 확인하고 결과 값의 근거를 설명하라.

```c++
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	
	int value1 = 2;
	int value2 = 256;

	cout << "[value1 << 1]" << (value1 << 1) << endl;
	cout << "[value1 << 2]" << (value1 << 2) << endl;
	cout << "[value1 << 3]" << (value1 << 3) << endl;

	cout << "[value2 << 1]" << (value2 << 1) << endl; 
	cout << "[value2 >> 1]" << (value2 >> 1) << endl; 
	cout << "[value2 >> 2]" << (value2 >> 2) << endl; 
	cout << "[value2 >> 3]" << (value2 >> 3) << endl; 

	return 0;
}
```
11. 다음 프로그램 코드를 실행하고 ```sizeof()``` 는 무엇을 하는 함수이고 입력 데이터와 출력 데이터의 의미를 확인하고 실핼 결과의 의미를 설명하라.

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "char(byte): " << sizeof(char) << endl;

	cout << "bool(byte): " << sizeof(bool) << endl;

	cout << "short(bytes): " << sizeof(short) << endl;
	cout << "long(bytes): " << sizeof(long) << endl;
	cout << "long long(bytes): " << sizeof(long long) << endl;

	cout << "float(bytes): " << sizeof(float) << endl;
	cout << "double(bytes): " << sizeof(double) << endl;
	cout << "long double(bytes): " << sizeof(long double) << endl;

	cout << "string(bytes): " << sizeof(string) << endl;

	return 0;
}
```

12. 다음 프로그램 코드를 실행하고 ```static_cast<short>()```의 의미와 ```cout.setf(ios::fixed)```, ```cout.precision()```, ```typeid().name()```의 기능을 추론하라.


```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int someInteger = 987654321;
	short someShort = static_cast<short>(someInteger);
	long someLong = someShort * 10000;
	double someDouble = someLong + 35.987654321;
	float someFloat = someShort + 35.987654321f;
	float castFloat = static_cast<float>(someDouble);

	auto autoValue = someLong;

	cout << someInteger << endl;
	cout << someShort << endl;
	cout << someLong << endl;

	cout.setf(ios::fixed);
	cout.precision(10); 
	cout << "double: ";
	cout << someDouble << endl;

	cout.setf(ios::fixed);
	cout.precision(10); 	
	cout << "float: ";
	cout << someFloat << endl;

	cout << "cast float:";
	cout << castFloat << endl;

	cout << typeid(someShort).name() << endl;
	cout << typeid(autoValue).name() << endl;

	return 0;
}
```
13. 다음 프로그램 코드를 실행 결과로 부터 ```unsigned short```, 와 ```short``` 자료형의 차이점을 추론하라. 또한 ```short``` 을 ```int```로 변경한 후 싱행 결과와 
```short``` 일 때의 결과를 비교하고 유사점과 차이점을 추론하라.

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	short SomeShort = 32750;
	unsigned short unShort = 32750, count = 0;

	cout << (SomeShort == unShort) << endl;

	while(SomeShort > 0 || SomeShort < -32760) {
		SomeShort+= 1;
		unShort += 1;
		cout << "(" << count << ")SomeShort: " << SomeShort << endl;
		cout << "(" << count << ")UnSighedShort: " << unShort <<endl;
		count++;
	}
	return 0;
}
```
14. 다음 프로그램 코드를 실행하고 참조 변수(reference variable)와 일반 변수의 관계를 추론하라. 

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int GeneralValue = 100;		  // 일반 변수
	int& refValue = GeneralValue; // 참조 변수

	cout << "GeneralValue(before): " << GeneralValue << endl;
	
	refValue = 300;

	cout << "GeneralValue(after): " << GeneralValue << endl;

	GeneralValue = 500;

	cout << "refValue: " << refValue << endl;

	return 0;
}
```
