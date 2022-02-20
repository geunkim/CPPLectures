# 메모리 주소(Memory Address)

컴퓨터에서 프로그램이 실행되면 운영체제는 데이터와 프로그램 코드를 위한 메모리 공간을 할당한다. 할당해주는 메모리 공간은 크게 코드(Code), 데이터(Data), 스택(Stack), 힙(Heap)의 네 영역으로 구성된다. 
컴퓨터에서 운영체제가 프로그램을 실행하는 절차는 [다음](https://github.com/geunkim/CPPLectures/blob/master/MemoryModelAndNameSpace/Memory_Model.md#%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8-%EC%8B%A4%ED%96%89)을 참조하라.

컴퓨터 하드웨어를 구성하는 RAM(Random Access Memory)가 여기서 이야기 하는 메모리에 해당하는 것으로 컴퓨터에서 여러 애플리케이션을 수행하는데 필요하며 일반적으로 메모리의 용량이 클수록 좋다. 
메모리에서 저장공간(위치)을 구별하기 위해 주소(address)라는 용어가 사용된다. 일반적인 집 주소, 메일 주소, 사무실 주소 같은 개념으로 메모리의 주소는 메모리의 저장 장소를 구별하는데 사용된다.
컴퓨터 메모리의 구별은 **바이트 단위**로 이루어 진다. 컴퓨터 메모리에 저장되는 데이터는 한 바이트마다 서로 다른 주소 값을 가진다. 

프로그램에서 변수가 선언되면 컴퓨터 메모리(RAM)에 변수에 해당하는 저장공간을 할당된다. 변수에 특정 값을 대입하며 그 값이 할당된 메모리의 저장공간에 저장된다. 
변수와 관련하여 할당된 메모리의 저장공간은 주소 값을 가진다. 
다음 프로그램은 ```int```, ```char```, ```short```, ```long long```, ```long double``` 자료형의 변수 10개를 선언하는 프로그램으로 10 개의 변수에 대한 메모리 공간을 할당하고
각 변수에 대해 할당된 메모리 공간의 시작 주소를 출력하고 있다.   

```c++
int main(int argc, char const *argv[])
{

	char cvar1, cvar2;
	int ivar1, ivar2;
	short svar1, svar2;
	long long lvar1, lvar2;
	long double dvar1, dvar2;
	
	cout << "변수 ivar1, ivar2에 할당된 메모리 주소: " << &ivar1 << ", " << &ivar2 << endl;
	cout << "변수 cvar1, cvar2에 할당된 메모리 주소: " << &cvar1 << ", " << &cvar2 << endl;
	cout << "변수 svar1, svar2에 할당된 메모리 주소: " << &svar1 << ", " << &svar2 << endl;
	cout << "변수 lvar1, lvar2에 할당된 메모리 주소: " << &lvar1 << ", " << &lvar2 << endl;
	cout << "변수 dvar1, dvar2에 할당된 메모리 주소: " << &dvar1 << ", " << &dvar2 << endl;

	return 0;
}
```
프로그램의 실행 결과는 다음과 같이 메모리 주소 값을 출력한다.

```bash
변수 ivar1, ivar2에 할당된 메모리 주소: 0x7ffeed7019ec, 0x7ffeed7019e8
변수 cvar1, cvar2에 할당된 메모리 주소: 0x7ffeed7019e7, 0x7ffeed7019e6
변수 svar1, svar2에 할당된 메모리 주소: 0x7ffeed7019e4, 0x7ffeed7019e2
변수 lvar1, lvar2에 할당된 메모리 주소: 0x7ffeed7019d8, 0x7ffeed7019d0
변수 dvar1, dvar2에 할당된 메모리 주소: 0x7ffeed7019c0, 0x7ffeed7019b0
```
앞의 프로그램 코드의 변수 선언이 메모리에 할당된 모습은 다름 그림과 같다. ```dvar1```과 ```dvar2```는 메모리에 16bit가 할당되는 자료형으로 
```dvar2```는 ```0x7ffeed7019b0 ~ 0x7ffeed7019bf```까지의 저장공간, ```dvar1```는 ```0x7ffeed7019c0 ~ 0x7ffeed7019cf```까지의 저장공간을 할당받아 사용한다. 
다른 변수들도 자료형에 따른 저장공간을 연속적으로 할당받게 된다. 이처럼 메모리의 저장 공간은 바이트 단위로 식별할 수 있는 주소 값을 가진다.

<img width = 300pt src=./memory_alloc.png>

C++에서 다음과 같이 변수 ```data```를 선언하면 ```data```에 해당하는 저장공간이 할당된다. ```data``` 변수의 값을 할당된 메모리의 주소 값을 이용하여 참조하고 새로운 값을 저장할 수 있다.  

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data;    // 정수 값을 저장하기 위한 int형 변수 data 선언 (메모리 공간 할당)

	cout << "data 변수를 위해 할당된 메모리 주소: " <<  &data << endl;

	cout << &data <<"에 저장된 데이터: " << *(&data) << endl;

	*(&data) = 200;                 // 변수 data의 저장공간에 정수 값 200 저장

	cout << &data <<"에 저장된 데이터: " << *(&data) << endl;

	data = 400;			// 변수 data에 정수 값 400 저장  

	cout << &data <<"에 저장된 데이터: " << *(&data) << endl;

	return 0;
}
```

프로그램 실행 결과는 다음과 같다. 

```bash
data 변수를 위해 할당된 메모리 주소: 0x7ffeed0259dc
0x7ffeed0259dc에 저장된 데이터: 0
0x7ffeed0259dc에 저장된 데이터: 200
0x7ffeed0259dc에 저장된 데이터: 400
```

변수 ```data```에 할당된 메모리의 저장공간의 주소는 ```0x7ffeed0259dc``` 이다. 새로운 데이터 값을 저장하기 전에 메모리에는 ```0```이 저장되어 있다.

```*(&data) = 200```은 ```data```변수가 할당된 메모리 공간의 주소를 이용하여 메모리 공간에 200을 저장하는 코드로 
변수 이름이 아닌 메모리 주소를 이용하여 값을 저장할 수 있음을 확인할 수 있다. 

```data = 400;``` 은 일반적으로 변수 이름을 통해 저장장소의 데이터 값을 400으로 변경한 것이다. 

그 후 ```*(&data)``` 와 같이 ```&``` 연산자를 이용하여 data 변수가 저장된 메모리의 주소 값을 얻고 특정 메모리 주소에 저장된 값을 얻는 ```*``` 연산자를 이용하여 
메모리에 저장된 값을 참조한다. 

C++ 언어에서는 메모리의 주소를 저장할 있는 포인터 변수가 규정되어 있다.  



