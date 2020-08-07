# Exception (예외)



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
