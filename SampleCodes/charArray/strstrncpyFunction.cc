str2에 str1의 문자열을 복사하시오.

### 1. 제어문 사용
```cpp
#include <iostream>

using namespace std;

int main()
{
    char str1[27] = "programming is interesting";
    char str2[27] = "difficult";
    
    for (i = 0; str1[i] != '\0'; i++)
    {
        str2[i] = str1[i];
    }
    cout << "str2 : " << str2 << endl;

    return 0;
}
```

### 2. strcpy 사용
```cpp
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
    char str1[27] = "programming is interesting";
    char str2[27] = "difficult";

    cout << "str2: " << strcpy(str2, str1) << endl;

    return 0;
}
```


문자열이 담긴 배열 str1에서 ```interesting```을 찾아 다른 단어로 변경하고 변경됨을 확인할 수 있게 출력하시오.

```cpp
#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

int main(void)
{
    char str1[] = "programming is interesting";
    char str2[] = "difficult";
    char str3[] = "interesting";

    char* ptr = strstr(str1, str3);

    
    cout << "str1 : " << str1 << endl;

    strncpy(ptr, str2, 11);

    cout << "str1 : " << str1 << endl;

    return 0;
}
```


```#pragma warning(disable : 4996)``` 'str~'을 사용했을 때 unsafe라는 오류가 뜸을 방지하기 위함.
