2월달이 29일까지 있는 윤년을 판독하는 문제. -> 4년에 한 번씩, 100년 단위는 윤년에 해당하지 않음. 그러나 400년 단위일 때는 무조건 윤년에 해당.

1. 조건문 사용

```cpp
#include <iostream>

using namespace std;

int main()
{

    int year;

    cin >> year;

 
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        cout << year << "년은 윤년입니다." << endl;
    }
    else
    {
        cout << year << "년은 윤년이 아닙니다." << endl;
    }
}
```

2. 배열&조건문 사용

```cpp
#include <iostream>

using namespace std;

int main()
{

    int year;

    cin >> year;

    char str1[] = "년은 윤년입니다.";
    char str2[] = "년은 윤년이 아닙니다.";
 
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        cout << year << str1 << endl;
    }
    else
    {
        cout << year << str2 << endl;
    }
}
```
