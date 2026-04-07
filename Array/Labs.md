# 프로그램 실습(Labs.)
프로그램 실습을 하면서 각 줄의 기능이 무엇인지 분석하여 리포트를 제출하사오.

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
2. 다음 프로그램 코드를 실행하였을 때 메모리에 할당되는 저장공간의 크기(바이트 단위로)와 출력 1, 출력 2, 출력 3의 결과를 추론하라. (근거와 함께) 

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
3. 다음 프로그램 코드의 출력 1 ~ 출력 6까지의 결과를 추론하고 실행 결과와 같은지 확인하라. 또한 grades, name 배열에 할당된 저장공간의 크기(바이트 단위)도 추론하고 출력 5와 출력 6의 결과를 비교하라. 

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
	cout << grades << endl;    // 출력 6

	return 0;
}
```
5. 다음 프로그램 코드는 10개의 저장 장소를 할당하는 data 배열을 선언하고 반복문을 사용하여 각 저장 장소에 값을 저장하고 있다. 
프로그램 코드 영역에 저장 장소 10개에 저장된 값을 반복문을 사용하여 출력하는 코드를 작성하고 확인하라.

```c++
using namespace std;

int main(int argc, char const *argv[])
{
	float data[10], initial_value = 10.1;

	for(int i = 0; i < 10; i++){
		data[i] = initial_value;
		initial_value += 0.3;
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
#include <iostream>
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
10. 다음 프로그램의 실행 결과를 추론하고 실행 결과와 같은지 확인해라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data[] = {1, 2, 3, 4, 5};

	for(auto& e : data) {
		e *= 15;
	}

	for(const auto& e : data) {
		cout << e << "  ";
	}
	cout << endl;
	
	return 0;
}

11. 다음 프로그램 코드의 실행 결과를 추론하고 실행 결과와 같은지 확인하라. scores 배열의 모든 원소의 합을 계산하는 로직을 분석하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int scores[] = {85, 90, 78, 95, 88, 92};
	int sum = 0;
	int count = sizeof(scores) / sizeof(scores[0]);

	for(int i = 0; i < count; i++) {
		sum += scores[i];
	}

	cout << "총합: " << sum << endl;
	cout << "평균: " << sum / count << endl;
	cout << "평균(실수): " << (double)sum / count << endl;

	return 0;
}
```

12. 다음 프로그램은 2차원 배열의 개념을 다룬다. 실행 결과를 추론하고 각 요소에 저장된 값을 확인하라. 또한 matrix 배열의 메모리 크기(바이트 단위)를 계산하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int matrix[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	cout << "행렬의 원소들:" << endl;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "메모리 크기: " << sizeof(matrix) << " bytes" << endl;

	return 0;
}
```

13. 다음 프로그램 코드를 완성하라. 배열의 최댓값을 찾는 로직을 구현하고 실행 결과를 확인하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int numbers[] = {34, 12, 78, 45, 23, 89, 56, 39};
	int max_value = numbers[0];
	int count = sizeof(numbers) / sizeof(numbers[0]);

	// 최댓값을 찾는 코드를 작성하세요.
	// for 반복문을 사용하여 배열의 모든 요소와 비교하세요.

	cout << "최댓값: " << max_value << endl;

	return 0;
}
```

14. 다음 프로그램은 배열의 순서를 역으로 출력한다. 실행 결과를 추론하고 프로그램을 실행하여 결과를 확인하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char word[] = "programming";
	int length = sizeof(word) / sizeof(word[0]);

	cout << "원본 문자열: " << word << endl;
	cout << "역순 출력: ";

	for(int i = length - 2; i >= 0; i--) {
		cout << word[i];
	}
	cout << endl;

	return 0;
}
```

15. 다음 프로그램 코드에서 두 배열의 모든 원소를 하나의 새로운 배열로 병합하는 코드를 작성하고 실행 결과를 확인하라.

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int array1[] = {10, 20, 30, 40};
	int array2[] = {50, 60, 70};
	int size1 = sizeof(array1) / sizeof(array1[0]);
	int size2 = sizeof(array2) / sizeof(array2[0]);
	int *merged = new int[size1 + size2];

	// 두 배열을 merged 배열로 병합하는 코드를 작성하세요.
	// 먼저 array1의 모든 원소를 복사하고, 그 다음 array2의 모든 원소를 복사하세요.

	cout << "병합된 배열: ";
	for(int i = 0; i < size1 + size2; i++) {
		cout << merged[i] << "  ";
	}
	cout << endl;

	return 0;
}
```
