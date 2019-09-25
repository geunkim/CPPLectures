# Exception (예외)

프로그램 실행 중에 메모리 등 컴퓨팅 자원 부족이나 사용자의 잘못된 입력 등 여러 원인으로 프로그램이 비정상적으로 종료하는 
경우가 있다. 이는 프로그램이 문법적으로 작성이 잘못된 것이 아니라 프로그램의 외적인 요인으로 발생하는 것으로 이러한 예외를 
올바르게 처리하지 못해 오류로 이이진다면 이는 프로그래머의 잘못이기 때문에 예외 상황을 적절하게 대처하는 프로그램을 작성하는 것이 필요하다. 

### Compile errors (컴파일 에러)
컴퓨터 프로그램에서 컴파일 에러는 구문 에러(syntax error)라고도 하며 작성된 프로그램 코드가 프로그램 언어의 문법에
위배되는 경우에 발생한다. 

### Logic errors (논리 에러)
컴퓨터 프로그래밍에서 논리 에러는 프로그램이 비정상적으로 종료되지 않으나 올바르지 않게 동작되는 프로그램의 버그로 
의도되지 않거나 원하지 않는 결과 또는 동작이 발생한다. 

```
double average (double a, double b) {
  return a + b / 2;
}
```

### Runtime errors (런타임 에러)
컴퓨터 프로그래밍에서 런타임 에러는 프로그램 실행 중에 발생하는 프로그램의 버그로 프로그램 중 0으로 나누기 에러, 
동적 메모리 할당 시 메모리 부족 에러, 배열에서 범위를 벗어난 영역의 접근 에러가 예이며 컴파일 과정에서는 검출되지 않는다.
이 에러는 프로그램이 종료되거나 잘못된 결과가 나온다.

## Exception

프로그램 실행 중 프로그램의 오동작이나 원하지 않는 결과에 영향을 미치는 예상치 못하는 상황을 예외라 하고 
일반적으로 논리 에러 및 런타임 에러에 해당한다. 예외는 오류를 감지하여 정보를 호출 스택에  정보를 전달하는 코드에 대한
공식적이고 잘 정의된 방법을 제공한다. 

모던 C++에서는 예외를 선호한다 (ref: https://docs.microsoft.com/ko-kr/cpp/cpp/errors-and-exception-handling-modern-cpp?view=vs-2019#basic-guideline). 

* 예외는 호출 코드가 오류 조건을 인식하고 처리하도록 한다. 예외가 처리되지 않으면 프로그램 실행이 중지된다.
* 예외 오류를 처리할 수 있는 호출 스택의 위치로 이동한다. 중간 함수는 예외를 전파할 수 있다. 다른 레이어와 조정 필요가 없다.
* 예외 스택 언와인딩 메커니즘은 예외가 발생된 후 잘 정의된 규칙에 따라 범위의 모든 개체를 제거한다.
* 예외는 오류를 감지하는 코드 및 오류를 처리하는 코드를 분명히 구분할 수 있다.

다음 예제는 C++에서 예외를 발생(throw)하고 처리(catch) 하는데 필요한 구문을 보여준다. 

```
#include <iostream>
#include <exception>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   } 
   else if ( b < 0) {
      throw 2;
   }
   return ((double)a/b);
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
