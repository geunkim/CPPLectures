# 프로그림 실습(Labs.)

1. 다음 프로그램 코드를 실행하였을 때 출력 1, 출력 2, 출력 3, 출력 4의 결과를 추론하라. (근거와 함께)

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int ages[5] = {10, 40, 30};

	cout << ages[0] << endl; // 출력 1
	cout << ages[1] << endl; // 출력 2
	cout << ages[3] << endl; // 출력 3
	cout << ages[5] << endl; // 출력 4

	return 0;
}
```
2. 다음 프로그램 코드를 실행하였을 때 메모리에 할당되는 저정공간의 크기(바이트 단위로)와 출력 1, 출력 2, 출력 3의 결과를 추론하라. 근거와 함께) 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int ages[] = {10, 40, 30};

	cout << ages[0] << endl; // 출력 1
	cout << ages[1] << endl; // 출력 2
	cout << ages[3] << endl; // 출력 3

	return 0;
}
```
3. 다음 프로그램 코드의 출력 1 ~ 출력 6까지의 결과를 추론하고 실행 결과와 같은지 확인하라. 또한 grades, name 배열에 할당된 저장공간의 크기(바이트 단위)도 추론하고 출력 5와 출록 6의 결과를 비교하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char grades[]= {'A', 'B', 'C', 'D', 'F'};      // 문자 배열 
	char name[] = {'P', 'e', 't', 'e', 'r', '\0'}; // 문자열 배열

	cout << grades[0] << endl; // 출력 1
	cout << name[0] << endl;   // 출력 2

	cout << name[5] << endl;   // 출력 3
	cout << grades[5] << endl; // 출력 4

	cout << name << endl;      // 출력 5
	cout << grades << endl;    // 출력 6

	return 0;
}
```
4. 다음 프로그램 코드와 3번의 프로그램 코드를 비교하고 결과를 추론하고 실행 결과와 비교하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char grades[]= "ABCDF";     // 문자열 배열 
	char name[] = "Peter";       // 문자열 배열

	cout << grades[0] << endl; // 출력 1
	cout << name[0] << endl;   // 출력 2

	cout << name[5] << endl;   // 출력 3
	cout << grades[5] << endl; // 출력 4


	cout << name << endl;      // 출력 5
	cout << grades << endl;    // 출려 6

	return 0;
}
```
5. 다음 프로그램 코드는 10개의 저장 장소를 할당하는 data 배열을 선언하고 반복문을 사용하여 각 저장 장소에 값을 저장하고 있다. 
프로그램 코드 영역에 저장 장소 10개에 저장된 값을 반복문을 사용하여 출력하는 코드를 작성하고 확인하라.

```c++
using namespace std;

int main(int argc, char const *argv[])
{
	float data[10], initlal_value = 10.1;

	for(int i = 0; i < 10; i++){
		data[i] = initlal_value;
		initlal_value += 0.3;
	}

  // 프로그램 코드 영역

	cout << endl;

	return 0;
}
```

6. 5번의 반복문의 코드를 하나의 대입 연산자만 사용하는 한 줄의 코드로 작성하라. 

7. 다음 프로그램 코드의 실행에서 첫 번쨰 num 과 두 번쨰 num의 값을 추론하고 실행 결과와 같은지 확인하라. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	char name[] = "Chul-Soo Kim";
	int values[] = {10, 40, 50, 60, 80, 100};

	num = sizeof(name)/sizeof(name[0]);
	cout << "num_of_name: " << num << endl;
	num = sizeof(values)/sizeof(values[0]);
	cout << "num of values: " << num << endl;

	return 0;
}
```

8. 다음 프로그램 코드 실행 결과를 추론하고 실행 결과와 같은지 확인하라. 

```c++
include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long data[6];

	cout << "배열 저장 공간 크기: "<< sizeof(data) << endl;

	return 0;
}
```
9. 다음 프로그램 코드에서 첫 번째 반복문을 통해 각 저장 장소에 저장된 값을 추론하고 두 번쨰 반복문에서 실행되는 연산을 분석하고 출력 결과를 추론하고 실행 결과와 비교하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[10];

	for(int i = 0; i < 10; i++) {
		data[i] = (i + 1);
	}

	for(int i = 1; i < 10; i++) {
		data[0] += data[i];
	}
	
	cout << data[0] << endl;

	return 0;
}
```
