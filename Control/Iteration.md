# 반복문 

컴퓨터 프로그램을 작성하다보면 동일한 작업을 원하는 조건이 될 때까지 반복해야 하는 경우가 있다. 
일반적으로 한 작업은 하나 이상의 프로그램 문장으로 이루어진다. 동일한 문장을 반복하기 위해서는 똑같은 문장을 복사하여 붙여넣기 하는 방법이 있다. 

아래의 예는 "Hello World!"를 화면에 5번 출력하는 프로그램 문장을 작상한 것이다.

```C++
cout << "Hello World!" << endl;
cout << "Hello World!" << endl;
cout << "Hello World!" << endl;
cout << "Hello World!" << endl;
cout << "Hello World!" << endl;
```

앞의 예와 같이 5번 반복 횟수가 5번 정도라면 복사\/붙여넣기가 가능하겠지만 10,000번 반복하거나 특정 조건(키보드로 부터 특정 문자가 입력된 경우)을
만족할 때 까지 반복을 하여야 하는 경우는 복사\/붙여넣기로 문제를 해결하는 것은 어렵거나 불가능하다. 

C++에서는 이러한 문제를 해결하기 위해 반복문 구조를 정의하고 있다. 반복문을 활용하면 프로그램에서 똑같은 문장을 여러번 코딩하는 
중복성을 제거하여 소스코드를 간결하게 표현할 수 있으며 프로그램에 필요한 시간을 줄이고 프로그램의 효율적인 유지, 보수할 수 있다.  


## 반복문의 종류 

반복문에서 **while 문** 과 **for 문** 이 있다.  **for 문** 은 반복 횟수을 알고 있을 때 **while 문** 은 반복횟수를 
알지 못하고 특정 조건이 만족되어야 하는 경우에 주로 사용한다. 
 
### while  문 

```while```문의 구조는 다음과 같다.
```C++
while(condition) {
  문장들
}
```
```while```문은 condition의 조건식이 참이면 중괄호안의 문장들이 순차적으로 실행되고 닫힘 중괄호를 만다면 다시 _condition_ 의 조건식이 참인지, 거짓인지 검사한 후 
참이면 다시 중괄호 안의 문장을 실행하고 거짓이면 중괄호 안의 문장을 실행하지 않고  ```while```문 다음의 문장을 실행하게 된다. 
중괄호 안의 문장의 개수는 하나 이상이여야 하고 하나인 경우는 중괄호를 생략할 수 있다. 

다음은 키보드로 부터 문자 하나를 계속 입력 받아 화면에 출력하는 프로그램으로 ```while```문을 활용하고 있다.
반복해서 문자를 입력 받던 중 'z'가 입력되면 화면에 출력하고 더 이상 입력 작업을 하지 않는 프로그램이다. 

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char in;                //변수 선언
	cout << "input: ";      // 문자열 출력
	cin >> in;                 // 키보드로 부터 데이터 입력

	while (in != 'z') {
		cout << "data: " << in << endl;
		cout << "input: ";        // 키보드로 부터 데이터 입력
		cin >> in;
	}

	return 0;
}
```
앞의 프로그램은 단순하게 키보드로 부터 문자가 입력될 것이라는 가정을 하고 작성이 된 것이다. 또한 키보드로 부터 입력받는 프로그램 코드가 두번 사용되었다. 
이는 ```do while```문을 활용하거나 ```while```문 전에 변수 **in**에 임의의 문자로 초기화를 하게 되면 ```while```문에서만 입력과 출력 코드가
필요하다.

다음 프로그램 코드는 화면에 "Hello World!"를 ```while```문을 활용하여 10번 출력하는 프로그램 코드이다.

```C++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0;
	while (count < 10) {
		cout << count << ":  " << "Hello World!" << endl;		
		count++;
	}
	
	return 0;
}
```
## do~while 문 

```do~while```문은 ```while```문과 비슷하나 반복 조건식을 검사하는 것이 반복해야할 문장들 다음에 위치한다는 것이 다르다. 그러므로 ```while```문과 달리
반복 문장이 최소한 한번은 실행된다. 따라서 ```do~while```문은 반복 문장이 적어도 한번은 실행되어야 하는 경우에 사용하는 것이 바람직하다.  

```do~while```문의 구조는 다음과 같다.

```C++
do {
  문장들
}whle(condition);
```

```while```문을 활용하여 키보드로 부터 문자를 입력받는 프로그램을 ```do~while```문을 활요앟여 작성하면 다음과 같다. 
		
```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char in;
	do {
		cout << "input: ";
		cin >> in;
		cout << "data: " << in << endl;
	}while(in != 'z');

	return 0;
}
```

앞에서도 설명하였듯이  ```do~while```문을 사용하면 반복 문장을 ```do~while```문 안에 한번만 작성하면 된다. 다음은 ```do~while```문을 활용하여 "Hello World!" 를 10번 출력하는 프로그램이다. 

```C++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0;
	do {
		cout << count << ":  " << "Hello World!" << endl;
		count++;
	}while(count < 10);
	
	return 0;
}
```

## for 문

```for```문의 구조는 다음과 같다. ```for```문은 일정한 횟수만큼 반복할 때 유용하다. 

```C++
for (초기식; 조건식; 증감식) {
   문장들
}
```

```for```문은 ```while```문, ```do~while ```문과 달리 초기식, 조건식, 증감식을 하나의 줄에서 표현되고 있다.

```for```문의 동작은 먼저 **초기식**이 한번 실행된다. 다음 **조건식**을 검사하고 참이면 문장들을 실행하고 **증감식**을 실행한 후 다시 **조건식**을 검사한다.
**조건식** 검사 결과가 거짓이면 반복을 종료한다. 

다음은 앞의 "Hello World!" 문장을 10번 반복 출력하는 것을 ```for```문을 활용하여 작성한 프로그램이다. 

```C++

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{	
	for(int count = 0; count < 10; count++) {
		cout << count << ":  " << "Hello World!" << endl;
	}

	return 0;
}
```

다음은 앞의 ```while```문, ```do~while```문을 활용하여 키보드로 부터 문자를 입력받고 출력하는 프로그램을 ```for```문으로 작성한 것이다.
마지막에 'z'를 출력하지 않도록 하기 위해서는 'z'가 출력되지 않도록 조건식을 추가하여야 한다. 


```C++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char in;
	for (in = 'a'; in != 'z'; ) {
		cout << "input: ";
		cin >> in;	
		if(in != 'z') cout << "data: " << in << endl;
	}

	return 0;
}
```
## break 문  continue 문 




## 무한 반복

* ```for```문의 세 부분이 모두 비워있는 경우 ```for```문은 무한 반복된다.
* ```while```문과 ```do~while```문을 사용하여 무한 반복문을 작성하기 위해서는 조건식 부분에 **true**로 명시하면 된다.


