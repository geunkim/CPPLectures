# **배열과 문자열**

## 

문자열(string)은 단어와 문장과 같이 문자들의 모임으로 문자형 배열에 저장을 하고 처리를 한다. 
문자열 리터럴은 쌍 따움표(" ")를 이용하여 표현한다.
다음은 문자열 리터럴의 예이다.

```C++
"A"
"School"
"Hello World!"
"How are you!"
```
문자 리터럴과 문자열 리터럴과 달리 문자 한 개를 표현한다. C++에서 문자는 문자열과 달리 
일반 따옴표('')로 묶어서 표현한다. 

문자열을 프로그램에서 사람들의 이름, 주소, 학과 이름, 학교 이름 등 모두 문자열로 저장된다. 
쌍 따움표를 사용하여 표시되는 문자열은 문자열 상수로 변경이 불가능하다. 

문자열은 "Hello World!" 와 같이 연속된 문자로 C++에서는 다음과 같이 문자형(char) 배열에 
저정된다. 

```C++
char str[20] = "Hello World!";   // char형 배열 선언과 초기화
```
문자형 배열 str은 20개의 문자를 저장할 수 있는 공간이며 다음과 같이 str[0]에는 문자 'H', str[1]에는 'e' 가
차례로 저장된다. 

![image](./charArray.png)

문자열 리터럴이 메모리에 저장될 때는 마지막에 NULL 문자('\0')가 저장된다. C++에서 NULL 문자는 문자열의 마지막을 
나타내는 문자이다. 그러므로 문자열을 저장하기 위해서 문자열의 문자의 수보다 하나 큰 저장공간이 요구된다. 
즉 "Hello World!" 문자열의 문자의 수는 12개 이나 NULL 문자까지 메모리에 저장해야 하기 때문에 총 13 바이트의 저장공간이 요구한다. 
즉 문자열을 저장하기 위해서 최소한 "문자열의 길이 + 1" 개의 저장공간이 필요하다.

문자열을 컴퓨터에 저장하기 위해서 다음 사항을 이해해야 한다.
* 문자열을 저장하기 위해서는 char형 배열을 선언하여야 한다.
* 최소한 '문자열의 길이 + 1' 크기 만큼의 저장공간이 요구된다.
* 문자열 배열의 마지막 요소는 NULL('\0')문자이어야 한다.

## **문자열 배열 초기화**

문자열은 다음과 같이 초기화하여 char형 배열에 저장할 수 있다.

```C++
char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  // (1)
char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};   // (2)
char str[6] = "Hello";                          // (3)
char str[] = "Hello";                           // (4)
```

(1)과 (2)처럼 문자열 초기화는 char형 배열의 각 저장공간에 문자를 하나씩 저장하는 방법과 
(3)과 (4)와 같이 문자열 리터럴을 사용하여 배열의 처음부터 문자열을 복사하는 방법이 있다. 

## **문자열 출력**

char 배열에 저장된 문자열의 출력은 cout을 이용하여 아래와 같이 출력한다. 

```C++
char str[] = "Hello";
cout << str << endl;    // Hello 출력
```
cout에 전달되는 것은 str로 배열의 이름으로 배열을 위해 할당받은 저장 공간의 시작주소가 전달된다.
cout은 문자열의 경우 시작주소로 부터 NULL 문자가 나올 때 까지 출력을 한다. 

아래의 프로그램과 같이 네 번째 저장 장소에 NULL 문자를 

```C++
char str[] = "Hello";
cout << str << endl;	// Hello 출력

str[3] = '\0';
cout << str << endl; 	// Hel 출력

str[3] = 'l';
str[5] = 'H';
cout << str << endl;	// HelloH 이후 이상한 문자들 
```

## **문자열 복사**

일반 변수의 경우 대입 연사자를 이용해서 값의 복사가 이루어진다. 
일반 배열을 포함한 문자열 배열과 같이 기본 자료형의 배열의 경우 
대입연산자로 한 배열의 저장된데이터를 다른 배열에 저장하는 것은 불가능하다.

즉 다음과 같은 코드로는 str1 배열에 저장된 문자열이 str2로 복사되지 않는다. 
```C++
char str1[] = "Hello World!";
char str2[20];

str2 = str1;  // str1에 저장된 문자열이 str2에 복사되지 않음
```
문자열의 복사는 다음과 같이 char 형 배열에 저장된 문자를 모두 하나씩 복사할 배열에 저장하여야 한다.

```C++
int i; 				// 배열의 인덱스로 사용하기 위한 변수 
char str1[] = "Hello World!";
char str2[10];

for(i = 0; str1[i] != '\0'; i++)  // str1 문자열을 st2에 복사 
	str2[i] = str1[i];

str2[i] = '\0';

if(&str1[0] == &str2[0]) 
	cout << "str1 address equals to str2 address." << endl;
else
	cout << "str1 address does not equal to str2 address." << endl; 
	
cout << str2 << endl;
```
## 문자열의 길이

문자열의 길이는 문자열을 구성하는 문자의 개수로 C++ 프로그램의 char형 배열에서 NULL 전까지의 문자 개수를 카운트하여 
문자열의 길이를 얻을 수 있다.

```C++
char str[] = "Hello World!!!";
int len = 0;

// str의 길이를 구하기
for(int i = 0; str[i] != '\0'; i++)
	len += 1;

cout <<"length of str: " << len << endl;
```
## 문자열 연결하기 

두 개의 문자열이 주어졌을 때 두 개의 문장을 연결하여 하나의 배열에 저장하는 기능이 요구된다. 

```C++
char str1[20] = "Hello";
char str2[] = " World!";

cout << str1 << endl;
// 두 문자열 연결하기
int i, j;
for(i = 0; str1[i] != '\0'; i++);
for(j = 0; str2[j] != '\0'; j++)
	str1[i+j] = str2[j];
str1[i+j] = '\0';

cout << str1 << endl; 
```

두개의 문자열의 내용이 같은지를 확인하는 기능도 생각해 보자. 
일단 길이가 같이야 하고 길이가 다르면 내용을 확인할 필요도 없다.
길이가 같은 경우에 내용 각각을 확인하고 저장된 내용이 모두 같아야 두 문자열이 같다고 판단하고 그렇지 않으면 다르다고 판단한다. 

## 표준라이브러리 

문자열과 관련해서는 앞에서 살펴본 문자열 관련 처리 기능 외에 여러 처리 기능이 있다. 
이처럼 문자열을 처리하기 우한 표준적인 함수가 이미 제공되고 있다.
이 함수들을 표준 라이브러리(standard library)라고 한다. 
표준 라이브러리에는 다양한 문자열 처리 함수가 정의되어 있다. 
앞에서 논의했던 문자열의 길이 측정, 문자열의 복사, 문자열을 합치는 함수 등이 있다.  
이들 함수를 C++에서 사용하기 위해서 <cstring> 헤더 파일을 포함하여야 한다. 
(참고사이트: [programiz 페이지](https://www.programiz.com/cpp-programming/library-function/cstring)
	
* ```C++ =size_t strlen(const char * s);```: 문자열 s에서 NULLL 문자를 제외한 길이를 반환
* ```C++ char* strcpy(char* s1, const char* s2);```: 문자열 s2를 문자열 배열 s1에 복사한 후 s1을 반환
* ```C++ char* strncpy(char* s1, const char* s2);```: 문자열 s2를 문자열 배열 s1에 문자 n 개를 복사한 후 s1을 반환
* ```C++ char* strcat(char* s1, const char* s2);```: 문자열 s2를 문자열 s1 끝에 붙이고 s1을 반환
* ```C++ int strcmp(const char* s1, const char* s2);```: 문자열 s1과 문자열 s2를 비교하여 s1<s2 이면 음수, s1\==s2 이면 0
* ```C++ int strncmp(const char* s1, const char* s2);```: 문자열 s1과 문자열 s2의 n개의 문자를 비교하여 s1<s2 이면 음수, s1\==s2 이면 0


s1\>s2 이면 양수 반환 
* ```char* strtok(char *s, const char *delimeer)```: 문자열 s에서 기준 구분자들을 이용하여 문자열을 나눈 문자열들을 반환

```C++
#include <iostream>
#include <cstring>  // 문자열 함수와 string 클래스를 위해 사용

using namespace std;

int main(int argc, char const *argv[])
{
	
	char str1[20] = "Hello";
	char str2[20] = " World!";
	char str3[20];
	
	// 문자열 길이 구하기 
	cout << "length of str1: " << strlen(str1) << endl;

	// 문자열 복사하기
	cout << "str3: " << strcpy(str3, str1) << endl;

	// 문자열 비교 
	cout << "compare st1 and str3: " << strcmp(str1, str3) << endl;

	// 문자열 붙이기 
	cout << "str1: " << strcat(str1, str2) << endl;
	cout << "length of str1(after concat): " << strlen(str1) << endl;

	// 문자열 비교 
	cout << "compare st1 and str3(after concat): " << strcmp(str1, str3) << endl;
	cout << "compare str3 and str1(afer concat): " << strcmp(str3, str1) << endl;
	// 문자열 분리 
	char *str = strtok(str1, " ");
	
	while (str != NULL) {
		cout << str << endl;
		str = strtok(NULL, " ");  //이전 strtok 함수에서 처리했던 문자열 다음 문자로 부터 처리 
	}

	return 0;
}
```

실행 결과는 다음과 같다.
 ```C++
length of str1: 5
str3: Hello
compare st1 and str3: 0
str1: Hello World!
length of str1(after concat): 12
compare st1 and str3(after concat): 32
compare str3 and str1(afer concat): -32
Hello
World!
```

## C++의 문자열 처리를 위한 std::string 클래스

객체 지향 언어인 C++에서는 문자열을 저장하고 처리기능(멤버 함수)을 가진 std::string 클래스를 정의하고 있다. 
문자열을 처리할 경우 string 클래스의 객체를 생성하고 멤버 함수를 사용하면 앞에서 살펴보았던 기능을 이용할 수 있다.
















