# main 함수 입력 파러미터 

C++의 ```main```함수는 입력 파라미터로 ```argc```와 ```argv``` 두 개가 있다. 이는 콘솔 창에서 실행 파일을 실행하기 위해서 실행파일과 함께 입력되는 데이터(인수)를
처리할 때 사용된다. 
```Unix``` 셀 명령어 중에 디렉토리와 파일 목록을 얻는 ```ls```가 있는데 ```ls```명령어를 사용할 때 다음과 같은 형식을 갖는다. 

```bash
$ls [option] [파일/디렉토리]
```

즉 ```$ls``` 명령어 다음에 필요에 따라 두 개의 인자를 함께 적을 수 있으며 이는 main 함수의 입력 인수로 전달된다. 

```argc```는 콘솔에서 프로그램을 실행할 때 실행파일 이름을 포함하여 입력되는 인자의 개수를 나타내며 
```argv[]```는 실행 파일 이름을 포함하여 입력되는 인자의 문자열을 저장한 배열이다.  

```c++
int main(int argc, char const *argv[])

	return 0;
}
````
```$ls``` 의 경우 ```argc```의 값은 1 이고 ```argv[0]```에는 문자열 ```ls```가 저장된다. 
```$ls -al```의 경우  ```argc```의 값은 2 이고 ```argv[0]```에는 문자열 ```ls```, ```argv[1]```에는 문자열 ```-al``` 이 저장된다. 


다음 프로그램(main_args.cc) 코드는 샐행파일을 실행할 때 함께 실행파일 이름과 함께 입력되는 인자들의 개수와 인자를 출력한다. 

```c++
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int idx = 0;
	cout << "argc: " << argc << endl;
	while (idx < argc) {
		cout << argv[idx] << endl;
		idx++;
	}	
	return 0;
}
````
실행 결과는 다음과 같다. 

```bash
$./main_args
argc: 1
./main_args
```
```bash
$./main_args first
argc: 2
./main_args
first
```

