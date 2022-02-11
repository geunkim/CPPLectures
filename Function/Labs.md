# 프로그램 실습(Labs)

1. 다음은 main 함수와 sum 함수로 구성된 프로그램 코드이다. main 함수에서 sum 함수를 호출하고 결과를 반환받아 화면에 출력한다. 
 프로그램 결과를 추론하고 함수 sum을 정의하여야 할 영역에 sum 함수를 정의한 후 결과를 확인하고 비교하라.

```c++
#include <iostream>
using namespace std;

// sum: 입력 매개변수로 전달받은 두 정수를 더하고 결과를 반환하는 함수
int sum(int a, int b);   // 함수 선언 (function declaration)


int main(int argc, char const *argv[])
{
	int x = 10, y = 30;

	int result = sum(x, y);  // 함수 호출 (function call)

	cout << x << " + " << y << " = " << result << endl;

	return 0;
}

// 함수 sum을 정의하여야 하는 영역

```
