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

4. 다음 프로그램 코드를 컴파일하여 실행 파일을 만든 후 명령창(command) 에서 다음과 같이 3 형식으로 실행한 후 결과를 확인하고 결과로 부터 프로그램 코드의 ```argc``` 의 의미를 추론하라.

```bash
$Lab4 first
$Lab4 first second
$Lab4 first second third
```

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "# of input parameters: " << argc << endl;
	return 0;
}
```
5. 다음 프로그램 코드는 4번 프로그램 코드에서 ```argv```를 통해 전달 받은 값을 출력하려는 것이다. 프로그램을 실행하고 ```argv[]```와 ```argc```와의 관계를 추론하라. 프로그램의 실행은 4번과 같이 명령창에서 명령어를 입력하여 확인하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "# of input parameters: " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << argv[i] << endl;
	return 0;
}
```

6. 다음 프로그램 코드를 컴파일하여 발생하는 에러를 해결하라. 컴파일에서 발생하는 예러의 이유를 추론하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float x, y;

	cout << "실수 두개를 입력하시오: " << endl;
	cin >> x >> y;
	
	cout << mul(x, y) << endl;
	return 0;
}

void mul(float a, float b) {
	return a * b;
}
```

7. 다음 프로그램 코드를 실행하였을 때 화면에 ```출력: 11``` 이 출력되도록 ```increase``` 함수를 포함하여 (가장 적인 코드를 추가하여)수정하라. 수정한 근거도 함께 기술하라.

```c++
#include <iostream>
using namespace std;


void increase(int x){
	x++;
}

int main(int argc, char const *argv[])
{
	int x = 10;

	increase(x);

	cout << "출력: " <<  x << endl;

	return 0;
}
```


8. 다음 프로그램 코드를 실행하였을 때 화면에 출력될 각 결과를 추론하고 실제 프로그램 실행 결과와 비교하라. 


```c++
#include <iostream>
using namespace std;

void swap1(int x, int y){
	cout << "(swap1 연산 전 출력) x:" << x <<", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap1 연산 후 출력) x:" << x <<", y: " << y << endl;
}


void swap2(int &x, int &y){
	cout << "(swap2 연산 전 출력) x:" << x <<", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap2 연산 후 출력) x:" << x <<", y: " << y << endl;
}


int main(int argc, char const *argv[])
{
	int x = 10, y = 20;

	cout << "(출력 1) x: "  << x << ", y: " << y << endl;
	swap1(x, y);
	cout << "(출력 2) x: "  << x << ", y: " << y << endl;
	swap2(x, y);
	cout << "(출력 3) x: "  << x << ", y: " << y << endl;

	return 0;
}
```

10.

