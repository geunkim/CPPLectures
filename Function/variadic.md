# 가변 매개변수 함수 (Variadic funciton)

지금까지 함수 입력 매개변수의 개수가 정해져 있는 함수의 정의와 호출에 대해서 학습하였다. 함수를 정의할 때 매개변수의 개수를 정하지 않고 함수를 호출할 때 전달되는 인자의 개수와 형식을 변경할 수 있는 일반적인 함수를 만들어야 하는 경우가 존재하는데 이 때 가변 매개변수 목록을 사용할 수 있다.

가변 인자를 사용하는 함수를 호출하기 위해서는 ```<cstdarg>``` 헤더 파일이 필요하고 함수를 정의할 때 마지막 매개 변수로 줄임표(...)를 사용하여 함수 선언이나 호출 시 복수의 인수를 사용할 수 있다. 
가변 인자를 사용하는 함수 몸체에서 인수의 값들은 ```<cstdarg>``` 내의 다음의 매크로 함수(macro fuction)가 정의되어 있다. 

* va_start: 리스트를 초기화. (```#define vs_start __crt_va_start```)
* * va_arg: 리스트의 다음 인수를 반환 (```#define vs_arg __crt_va_arg```)
* va_end: 변수 인수 리스트를 정리 (```#define vs_end __crt_va_end```)
* va_copy: 인수들의 리스트를 저장 (```#define va_copy(destation, source) ((destination) = (source)```)

매크로 함수를 사용하기 위해서는 먼저 ```va_list```라는 타입이 필요하다.

```c++
#typedef char* va_list;
```

<table>
<th>함수</th><th>설명</th>
<tr> 
    <td>va_start</td><td> 인자 리스트를 접근할 수 있도록 함 (인수 리스트를 초기화) (enable access to variadic function arguments) </td>
</tr>
<tr> 
    <td>va_arg</td><td> 인자 리스트의 다음 인자를 접근 (accesses th next variadic function argument) </td>
</tr>   
<tr> 
    <td>va_end</td><td> 인자 리스트의 순회(traversal)를 종료 (인수 리스트를 정리) (ends traversal of the variadic fuction arguments </td>
</tr>
<tr> 
    <td>va_copy</td><td> 인자 리스트의 복사본을 복사 (make a copy of variadic function arguments) </td>
</tr>
<tr>
    <td>va_list</td><td> va_start, va_arg, va_end, va_copy에서 필요한 정보롤 보유 (holds the information needd by va_start, va_arg, va_end, va_copy) </td>
</tr>
</table>

```va_start```매크로 함수는 다음과 같은 두 인자를 가진다. 

```c++
va_start(va_list ap, T prev);
```
```va_start```매크로 함수의 ```ap``` 는 가변 매개변수로 전달된 값들의 첫 번쨰 주소를 가리킬 수 있도록 ```va_list``` 자료형을 가진다. 첫 번쨰 주소의 기준은 ```prev``` 변수에 따라 달라지며 ```prev```의 다음 매개변수를 ```va_list```가 가리키도록 한다. ```prev```는 레퍼런스(참조형 변수), 함수, 배열이 될 수 없다. ```va_list```를 사용하기 전에 반드시 해당 매크로 함수를 통해 초기화해야 한다. 아래 함수에서 ```vlist```는 ```_var``` 다음에 오는 첫 매개변수를 가킨다.

```c++
void func(int _var, ...) {

    va_list vlist;
    va_start(vlist, _var);
}
```

```va_arg```매크로는 ```va_list``` 타입의 변수와 저장된 데이터의 자료형을 매개변수로 받는다. 앞의 코드의 ```vlist```에 저장된 데이터의 자료형이 ```int```이면 아래와 같이 적는다. 

```c++
va_arg(vlist, int);
```` 

```va_end``` 매크로는 입력 매개 변수로 ```va_list```자료형의 변수를 받으며 변수를 초기화 전의 상태로 만든다. 다음의 코드는 ```vlist```를 초기화 전 상태로 만드다 

```c++
va_end(vlist);
```

```va_copy```매크로는 ```va_list``` 자료형의 변수 두 개를 매개 변수을 입력 받으며 첫 번째 변수에서 두변쨰 변수로 복사한다. 
다음의 코드는 ```list1```에 저장된 값을 ```list2```로 복사한다. 

가변 

```c++
va_copy(vlist1, vlist2);
```

가변 매개변수 함수의 경우 전달받은 매개 변수의 개수를 반환하는 매크로는 따로 정의되어 있지 않아 반복문을 사용하기 위해 다음의 두 가지 방법을 고려할 수 있다.

* 첫 번째 인자에는 전달하는 변수의 개수, 두 번째 인자부터는 가변의 변수들을 전달한다. (배열을 함수에 전달하는 방법과 유사)

```c++
sum(5, 1.1, 2.2, 3.3, 4.4, 5.5); // 첫 번쨰 인자 5는 다음에 나타나는 {1.1, 2.2, 3.3, 4.4, 5.5} 데이터의 개수를 의미   
```
* 마지막 인자에는 처리 데이터에 포함되지 않는 값(예:NULL, -1)을 넣어 전달되는 데이터의 끝을 나타내도록 한다. (NULL 문자로 문자열의 끝에 나타내는 배열을 함수에 전달하는 방법과 유사) 





### 가변 매개변수 함수의 예 

아래의 샘플 코드는 함수로 전달되는 데이터들의 평균을 구하는 ```average()``` 함수 정의의 예야다. 

```c++
#include <cstdarg>
#include <iostream>
 
using namespace std;
 
// this function will take the number of values to average
// followed by all of the numbers to average
double average ( int num, ... )
{
  va_list arguments;                     // A place to store the list of arguments
  double sum = 0;
 
  va_start ( arguments, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( arguments, double ); // Adds the next value in argument list to sum.
  va_end ( arguments );                  // Cleans up the list
 
  return sum / num;                      // Returns the average
}
int main()
{
    // this computes the average of 12.2, 22.3 and 4.5 (3 indicates the number of values to average)
  cout<< average ( 3, 12.2, 22.3, 4.5 ) <<endl;
    // here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
  cout<< average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) <<endl;
}  
```










## Reference
* [가변 인수 목록을 사용하는 함수](https://docs.microsoft.com/ko-kr/cpp/cpp/functions-with-variable-argument-lists-cpp?view=msvc-160)
* [가변 인수(variadic arguments)](https://en.cppreference.com/w/cpp/language/variadic_arguments)
* 
