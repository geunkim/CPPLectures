# 프로그램 실습(Labs)

1. 다음은 main 함수와 add_10 함수로 구성된 프로그램 코드이다. add_10 함수는 입력 매개변수로 하나의 정수를 입력받고 입력된 값에 10을 더한 결과를 반환하는 함수이다. 
add_10 함수를 정의하라. 

```c++
#include <iostream>
using namespace std;

/**
 * add_10: 입력하는 정수 값에 10을 더해서 반환하는 함수
 * @param {int} in [정수 매개변수]
 * @return {int}
 */
int add_10(int in) {               // 함수 정의

}

int main(int argc, char const *argv[])
{
	int data;

	cout << "정수를 입력하시요: ";
	cin >> data;

	cout <<	add_10(data) << endl;  // 함수 호출 

	return 0;
}
```

2. 다음 프로그램 코드가 컴파일 에러 없이 실행파일을 생성할 수 있도록  (1), (2), (3), (4) 의 순서와 위치를 추론하고 실행 결과를 확인하라.  

```c++
#include <iostream>
using namespace std;

cout << min_value(3, 5) << endl;   // (1) 함수 호출 

int main(int argc, char const *argv[]) // (2) main 함수 정의
{

	return 0;
}

int min_value(int x, int y){ return x > y ? y : x;} // (3) min 함수 정의

int min_value(int a, int b);  // (4) min 함수 호출
```


3. 다음은 main 함수와 sum 함수로 구성된 프로그램 코드이다. main 함수에서 sum 함수를 호출하고 결과를 반환받아 화면에 출력한다. 
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

4. 다음 프로그램 코드를 


