#  입력 스트림 (input stream)

* **```istream```**: C++ 에서 정의한 클래스로 실제로 입력 수행을 담당한다.  
* **```cin```** : ```istream``` 클래스의 객체로 문자 자료형의 문자들로 표준 입력 스트림(standard input stream)을 표현한다. 

입력 스트림(input stream)의 객체로 키보드와 같은 외부로 부터 데이터를 컴퓨터로 입력하는데 사용된다.


## 키보드 입력
키보드로 부터 데이터를 입력받기 위해서 ``cin`` 클래스를 사용한다.
키보드로 부터 여러 데이터를 입력받아 변수에 저장하기 위해서는 ``>>`` 연산자를 사용한다.
아래의 프로그램은 정수형 변수 ``x``, ``y``를 선언한 후 키보드로 부터 입력을 받아
``x``, ``y``에 저장한다. 

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int x, y;
  cout << "정수 2개 입력하시오: ";
  cin >> x >> y;
  cout << "x: " << x << " y: " << y << endl;
  cout << "x + y: " << x + y << endl;
	return 0;
}
```

## 키보드로 부터 데이터를 입력받아 배열에 저장하기

```cpp
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10];
	for (int i = 0; i < 10; i++) cin >> arr[i];
	for (int j = 0; j < 10; j++) cout << arr[j] << " ";
	cout << endl;
	return 0;
}
```
