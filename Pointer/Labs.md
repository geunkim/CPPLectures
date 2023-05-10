# Pointr 변수 실습

1. 다음 프로그램의 결과를 분석하라. myswap 함수가 하는 일과 출력 결과가 나오는 이유를 기술하라.  

```c++
#include <iostream>
using namespace std;

void myswap(int a, int b){
	cout << "(before) a: " << a << ", b: " << b << endl;
	int tmp = a;
	a = b;
	b = a;
	cout << "(after) a: " << a << ", b: " << b << endl;
}

int main(int argc, char const *argv[])
{
	int x, y;
	cout << "정수 두 개를 입력하시오: ";
	cin >> x >> y;

	cout << "(main before) x: " << x << ", y: " << y << endl;

	myswap(x, y);

	cout << "(main after) x: " << x << ", y: " << y << endl;

	return 0;
}
```

2. 다음 프로그램의 에러를 수정하고 왜 에러가 발생하였는지 분석하고 실행 결과를 1번과 비교하라. 

```c++
#include <iostream>
using namespace std;

void myswap(const int &a, const int &b){
	cout << "(before) a: " << a << ", b: " << b << endl;
	int tmp = a;
	a = b;
	b = a;
	cout << "(after) a: " << a << ", b: " << b << endl;
}

int main(int argc, char const *argv[])
{
	int x, y;
	cout << "정수 두 개를 입력하시오: ";
	cin >> x >> y;

	cout << "(main before) x: " << x << ", y: " << y << endl;

	myswap(x, y);

	cout << "(main after) x: " << x << ", y: " << y << endl;

	return 0;
}
````

3. 다음 프로그램의 에러를 수정하고 왜 에러가 발생하였는지 분석하고 실행 결과를 1번과 2번과 비교하라. 
```c++
#include <iostream>
using namespace std;

void myswap(int *a, int *b){
	cout << "(before) a: " << *a << ", b: " << *b << endl;
	int tmp = *a;
	*a = *b;
	*b = *a;
	cout << "(after) a: " << *a << ", b: " << *b << endl;
}

int main(int argc, char const *argv[])
{
	int x, y;
	cout << "정수 두 개를 입력하시오: ";
	cin >> x >> y;

	cout << "(main before) x: " << x << ", y: " << y << endl;

	myswap(x, y);

	cout << "(main after) x: " << x << ", y: " << y << endl;

	return 0;
}
````

4. 다음 프로그램에서 에러가 발생하면 에러가 왜 발생하였는지 확인하고 에러가 발생하지 않도록 수정하라. 힌트: (1)의 두 줄을 주석처리하고 (2)의 네 줄에 대한 주석을 해지하고 실행시킨 내용과 비교하라.)

```c++
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	// (1)
	int *a;
	cout << *a << endl;


	// (2)
	// double *b;
	// b = new double(10.4);   
	// cout << *b << endl;
	// delete b;               

	return 0;
}
```

5. 정수가 저장된 배열과 배열의 크기를 전달받아서 배열에 저장된 값 중 세 번째로 작은 값을 찾아 반환하는 함수를 정의하시오. (함수 내의 연산은 포인터 변수 darr을 이용하여 작성하라.)
```c++
   함수의 원형: int thirdValueinArray(double *darr, int len);
```

6. 다음 함수를 수행한 결과를 추론하라.

``` c++

#include <iostream>
using namespace std;

int recursive(int a){
   if(a == 0) return 0;
   else return a + recursive(a-1);
}

int main(int argc, char const *argv[])
{
   int a, result;
   cin >> a;
   result = a + recursive(a-1);

   cout << result << endl;
   return 0;
}

7. SampleCode 디렉토리의 프로그램을 실행하고 분석하라.  
