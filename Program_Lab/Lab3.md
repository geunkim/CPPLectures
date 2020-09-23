# 예외처리 실습

다음의 문제를 해결하기 위한 프로그램을 작성하시오.

1. ``int myExp(int base, int exp)`` 함수를 구현하고 ```main()``` 함수에서 여러 경우를 검중할 수 있도록 함수를 호출하여 테스트 하시오.
* base > 0, exp >= 0  인 경우에만 동작
* 이 조건을 만족하지 않을 경우 -1을 반환
  - 호출 예) myExp(2, 3); --> 8을 반환 
  
 
2. ``bool myExp(int base, int exp, int& ret)`` 함수를 구현하고 ```main()``` 함수에서 여러 경우를 검중할 수 있도록 함수를 호출하여 테스트 하시오.
* base > 0, exp >= 0  인 경우에만 동작 --> 이 조건을 만족할 경우 true 값을 반환하고 ret에 결과 값을 저장하여 계산 결과를 호출한 곳에 전달
* 이 조건을 만족하지 않을 경우 false를 반환하고 ret에는 -1을 저장하여 계산 결과를 호출한 곳에 전달

3. 아래의 코드를 실행시키면 

```cpp
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	try{
  		throw 1.1;
  	}
  	catch(int e) {
  		cout <<  e << endl;
  	}
	return 0;
}
```
