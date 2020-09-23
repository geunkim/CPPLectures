# 예외처리 실습

다음의 문제를 해결하기 위한 프로그램을 작성하시오.

1. ``int myExp(int base, int exp)`` 함수를 구현하고 ```main()``` 함수에서 여러 경우를 검중할 수 있도록 함수를 호출하여 테스트 하시오.
* base > 0, exp >= 0  인 경우에만 동작
* 이 조건을 만족하지 않을 경우 -1을 반환
  - 호출 예) myExp(2, 0); --> 1을 반환, myExp(2, 2); --> 4을 반환
  
 
2. ``bool myExp(int base, int exp, int& ret)`` 함수를 구현하고 ```main()``` 함수에서 여러 경우를 검중할 수 있도록 함수를 호출하여 테스트 하시오.
* base > 0, exp >= 0  인 경우에만 동작 --> 이 조건을 만족할 경우 true 값을 반환하고 ret에 결과 값을 저장하여 계산 결과를 호출한 곳에 전달
* 이 조건을 만족하지 않을 경우 false를 반환하고 ret에는 -1을 저장하여 계산 결과를 호출한 곳에 전달

3. 아래의 코드를 실행시키면 에러가 발생한다. 이를 해결하는 프로그램을 작성하시오 (해결방법 최소 2개) ([참고](../SampleCodes/Exception/Exception_ex3.cc))

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

4. ``int myExp(int base, int exp)`` 함수를 구현하고 ```main()``` 함수에서 여러 경우를 검중할 수 있도록 함수를 호출하여 테스트 하시오.
* base > 0, exp >= 0  인 경우에만 동작
* 이 조건을 만족하지 않을 경우 "Error in myExp()" 를 ``throw``하고 ```main()``` 함수에서 처리하기


5. 다음의 코드를 분석하여 무엇을 하는 프로그램인지 기술하시오. 여기서 ``e``의 일반 변수인가 객체 변수인가?
* MyFunc()의 입력 데이터 타입을 short으로 변경하고 입력 데이터가 short의 범위를 넘어가면 에러가 발생하도록 MyFunc() 함수를 변경하고 main() 함수에서 예외가 발생하도록 프로그램을 변경하시오. ([참고](../SampleCodes/Exception/Exception_ex4.cc))

```cpp
#include <exception>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())
        throw invalid_argument("MyFunc argument too large.");
}

int main()
{
    try
    {
        MyFunc(256); 
    }

    catch (exception& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}
```

5. 다음 프로그램이 동작되도록 division() 함수를 정의하시오. ([참고](../SampleCodes/Exception/Exception_ex5.cc))


```cpp
#include <iostream>
#include <exception>
using namespace std;

double division(int a, int b) {

}

int main () {
   int x, y;
   cin >> x >> y;
   double z = 0;
   
   try {
      z = division(x, y);
      cout << z << endl;
   }catch (const char* e) {
      cout << e << endl;
   }catch(...)
   {
    cout << "exception" <<endl;
   }
   return 0;
}
```

6. 다음 프로그램을 실행시켜보고 어떤한 동작을 하는 것인지 프로그램을 분석하시오. MyException 클래스와 프로그램에서의 역할도 함께 기술하시오. ([참고](../SampleCodes/Exception/StandardException.cc))


```cpp
#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception {
public:
	const char* what() const throw() {
		return "C++ Exception";
	}
};


int main(int argc, char const *argv[])
{
	int i;
	cout << "Enter integer number: ";
	cin >> i;
	try{
		if(i == 0)
			throw MyException();
		else 
			throw invalid_argument("MyFunc argument too large.");

	}catch(MyException& e) {
		cout << "MyException caught" << endl;
		cout << e.what() << endl;
	}catch(exception& e){
		cout << "exception caught" << endl;
		cout << e.what() << endl;
	}
	return 0;
}

```

7. GitHub의 ``\SampleCodes\Exception`` 에 들어갈 에외처리와 관련한 프로그램을 2개 이상 작성하시오.