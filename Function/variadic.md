# 가변 매개 변수 함수 (Variadic Funciton)

지금까지 공부한 함수 정의는 함수의 입력 매개변수의 개수가 정해져 있는 경우의 함수 정의와 호출에 대해서 학습하였다. 함수를 정의할 때 매개변수의 개수를 정하지 않고 함수를 호출할 때 전달되는 인자의 개수와 형식을 변경할 수 있는 일반적인 함수를 만들어야 하는 경우가 있은데 이 때 가변 매개변수 목록을 사용할 수 있다.

가변 인수를 사용하는 함수를 호출하기 위해서는 ```<cstdarg>``` 헤더 파일이 필요하고 함수 정의 시 마지막 멤버로 줄임표(...)를 사용하여 함수 선언이나 호출 시 복수의 인수를 사용할 수 있다. 

가변 인수를 사용하는 함수 몸체에서 인수의 값들은 ```<cstdarg>``` 내의 다음의 매크로 함수(macro fuction)를 사용하여 접근할 수 있다.  

* va_list: 인수들의 리스트를 저장
* va_start: 리스트를 초기화
* va_arg: 리스트의 다음 인수를 반환
* va_end: 변수 인수 리스트를 정리

<table>
<th>함수</th><th>설명</th>
<tr> 
    <td>va_start</td><td> 인수 리스트를 접근할 수 있도록 함 (인수 리스트를 초기화함) </td>
</tr>
<tr> 
    <td>va_arg</td><td> 인수 리스트의 다음 인수를 접근할 수 있도록 반환 </td>
</tr>
<tr> 
    <td>va_copy</td><td> 인수 리스트의 복사본을 복사 </td>
</tr>
<tr> 
    <td>va_end</td><td> 인수 리스트의 순회(traversal)을 종료 (인수 리스트를 정리) </td>
</tr>
<tr> 
    <td>va_list</td><td> va_start, va_arg, va_end, va_copy 가 필요한 인수 정보를 저장</td>
</tr>
</table>


아래의 샘플 코드는 다음과 같습니다.

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