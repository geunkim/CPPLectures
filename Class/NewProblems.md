### 1. 해당 코드에서 코드를 추가하여 함수 show()를 호출할 시 다음과 같은 결과가 나오도록 하라
(단, 접근 지정자의 범위를 수정하지 않으며 '홍길동'과 '10'은 각 클래스의 멤버 변수로 출력한다.)

```c++
#include <iostream>

using namespace std;

class Man
{
	string name = "홍길동";
public:
	void show(int);
};

void Man::show(int book)
{

}

class Book
{
	int num = 10;
public:

};

int main(int argc, const char* argv[])
{


	return 0;
}
```

출력 결과
```
홍길동 has 10 books
```

