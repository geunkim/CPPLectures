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

2. 

