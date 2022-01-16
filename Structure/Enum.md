# 공용체(union data type)

공용체(union data type)는 구조체와 유사하게 사용자 정의 자료형으로 형태도 유사하나 여러 자료형의 데이터를 위한 저장공간을 각각 할당하는 것이 아니라 
여러 자료형 중 가장 큰 저장공간을 할당한 후 이 저장공간을 여러 변수가 공유하는 것이다.

공용체의 자료형을 정의하는 것은 구조체의 자료형을 정의하는 것과 유시하나 공용체의 자료형을 정의하기 위해서 ```struct```키워드 대신에 ```union``` 키워드가 사용된다.
공용체가 구조체와 다른 점은 구조체에서는 여러 데이터를 동시에 저장할 수 있는데 반해 한 시점에 한 자료형의 데이터만을 저장할 수 있다. 공용체는 구조체에 비해 활용도가 낮다. 

다음 그림은 int 자료형의 데이터와 short 자료형 데이터, char 자료형의 데이터를 저장할 수 있는 공용체의 메모리 할당 모습이다.

<img src="./images/union-figure.png" />

```c++
union <자료형 이름>{
  자로형 변수1;
  자료형 변수2;
  자료형 변수3;
}; 
```


```c++
#include <iostream>

using namespace std;


union Student {
	char grade;
	int id;
	short score;
};

int main(int argc, char const *argv[])
{
	Student peter;

	cout << "할당된 메모리 크기: " << sizeof(peter) << endl;

	peter.grade = 'A';

	cout << "grade: " << peter.grade << endl;
	cout << "grade(code 값): " << (int) peter.grade << endl;

	peter.score = 512 + 66;
	cout << "score: " << peter.score << endl;

	cout << "grade: "  << peter.grade << endl;

	peter.id = 65536 + 1024 + 67;

	cout << "id: " << peter.id << endl;
	cout << "score: " << peter.score << endl;
	cout << "grade: " << peter.grade << endl;

	return 0;
}
````
  
프로그램의 실행 결과는 다음과 같다.

```bash
할당된 메모리 크기: 4
grade: A
grade(code 값): 65
score: 578
grade: B
id: 66627
score: 1091
grade: C
````
  
  

