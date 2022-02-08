# Labs - 제어문 

1. 다음 프로그램 코드를 실행 시켰을 때 90을 입력하였을 때 ```100 이하 정수이다```만 화면에 출력되고 110을 입력하였을 때 ```100 초과 정수이다```만 화면에 출력되는지 확인하라. 
결과가 지정한대로 출력되지 않는다면 이유를 추론하라.

```c++
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int input;
	cout << "정수를 입력하시오: ";
	cin >> input;

	if(input <= 100) {
		cout << "100 이하 정수이다" << endl;
	}

	cout << "100 초과 정수이다" << endl;

	return 0;
}
```

2. 1의 결과가 원하는대로 출력이 되도록 프로그램 코드를 수정하라.

3. 다음 프로그램 코드는 입력 값이 15일 때 ```입력한 값은 15, 10보다 큰 정수이다``` 라고 출력이 되고 입력 값이 5 일 때 ```10보다 각은 정수이다``` 가 출력이 되도록 작성한 것이다.
   컴파일 시 에러가 발생한다. 원인을 추론하고 원하는 결과가 나오도록 프로그램을 수정하라.  

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int value;

	cout << "정수를 입력하시오: ";
	cin >> value;

	if(value > 10) 	
		cout << "입력한 값은 " << value << endl;
		cout << "10보다 큰 정수이다" << endl;
	else 
		cout << "10보다 작은 정수이다" << endl;

	return 0;
}
```

4. 다음 프로그램 실행 시 짝수가 입력되면 ```짝 수 이다.``` 가 출력되고 홀수가 입력되면 ```홀수 아다.``` 가 출력되도록 ```A``` 또는 ```B```출력 부분을 수정하라. 그리고 프로그램 결과를 분석하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int value;

	cout << "정수를 입력하시오: ";
	cin >> value;

	if(value % 2)
		cout << " A " << endl;
	else 
		cout << " B " << endl;
	return 0;
}
```

4. 다음 프로그램 코드를 실행 시 반복되는 문장이 무엇인지 답하고 반복되는 횟수를 추론할 수 있는가? 또한 반복의 종료 조건은 무엇인가?

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int input;
	do {
		cout << "정수를 입력하시오: ";
		cin >> input;
		cout << "입력값: " << input << endl;
	}while(input != 0);
	
	return 0;
}
```

2. 다음 프로그램 코드를 실행하고 반복 횟수만큼 실행이 되는지 확인하고 반복 횟수보다 둘 적은 횟수로 반복되도록 코드를 수정하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count = 0, num;
	cout << "반복 횟수를 입력하시오: ";
	cin >> num;

	while(count < num) {
		cout << "repeat (" << count << ")" << endl;
		count++;
	}
	return 0;
}
```

