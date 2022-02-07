# Labs - 제어문 

1. 다음 프로그램 코드를 실행 시 반복되는 문장이 무엇인지 답하고 반복되는 횟수를 추론할 수 있는가? 또한 반복의 종료 조건은 무엇인가?

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

