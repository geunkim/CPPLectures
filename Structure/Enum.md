# 공용체(union data type)

공용체(union data type)는 구조체와 유사하게 사용자 정의 자료형으로 형태도 유사하나 여러 자료형의 데이터를 위한 저장공간을 각각 할당하는 것이 아니라 
여러 자료형 중 가장 큰 저장공간을 할당한 후 이 저장공간을 여러 변수가 공유하는 것이다.

공용체의 자료형을 정의하는 것은 구조체의 자료형을 정의하는 것과 유시하나 공용체의 자료형을 정의하기 위해서 ```struct```키워드 대신에 ```union``` 키워드가 사용된다.
공용체가 구조체와 다른 점은 구조체에서는 여러 데이터를 동시에 저장할 수 있는데 반해 한 시점에 한 자료형의 데이터만을 저장할 수 있다. 공용체는 구조체에 비해 활용도가 낮다. 
다음은 ```union``` 키워드를 사용하여 공용체 자료형을 정의하는 형식으로 C++ 언어에서는 ```<자료형 이름>``` 에 사용되는 이름이 자료형으로 사용되고 C 언어에서는 ```union <자료형 이름>``` 이 자료형이 된다.  

```c++
union <자료형 이름>{
  자로형 변수1;
  자료형 변수2;
  자료형 변수3;
}; 
```
다음 그림은 int 자료형의 데이터와 short 자료형 데이터, char 자료형의 데이터가 포함되는 공용체의 변수가 할당되었을 떄의 메모리 할당 모습이다.

<img src="./images/union_figure.png" width="300" height="100" />

다음 코드는 ```Student```라는 공용체를 정의한 것으로 ```char grade```, ``ìnt id```, ```short score```의 서로 다른 자료형의 데이터 세 개가 
메모리를 공유하는 것으로 할당된 메모리 크기를 ```sizeof(peter)```를 통해서 얻으면 ```4```가 출력된다. 즉 ```char```, ```ìnt```, ```short``` 자료형 중 ```ìnt```자료형의 크기인 4 바이트가 할당된다. 

```peter.id = 0;```으로 공용체 변수 peter의 저장장소 초기화를 한 후 
```peter.grade = 'A';``` 로 peter의 1 바이트의 값만을 변경하고
```peter.score = 512 + 66;```로 peter의 2 바이트의 값을 변경하고  
```peter.id = 65536 + 1024 + 67;``` 로 peter의 4바이트의 값을 변경한 후 
 공용체 peter의 각 변수에 저장된 값을 출력하면 4 바이트 중 1 바이트, 2바이트, 4바이트에 해당되는 값을 출력함을 확인할 수 있다. 

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
	peter.id = 0;  // 공용체 변수 peter의 저장장소 초기화
	cout << "할당된 메모리 크기: " << sizeof(peter) << endl;

	peter.grade = 'A';

	cout << "grade: " << peter.grade << endl;
	cout << "grade(code 값): " << (int) peter.grade << endl;

	cout << "id: " << peter.id << endl;
	cout << "score: " << peter.score << endl;
	cout << "grade: " << peter.grade << endl;

	peter.score = 512 + 66;

	cout << "id: " << peter.id << endl;
	cout << "score: " << peter.score << endl;
	cout << "grade: " << peter.grade << endl;

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
id: 65
score: 65
grade: A
id: 578
score: 578
grade: B
id: 66627
score: 1091
grade: C
````
  
  

