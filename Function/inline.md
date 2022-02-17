# 인라인 함수 (inline function)

C++ 에서 인라인 함수는 함수 앞에 ```inline``` 지시자를 붙은 경우로 컴파일러가 인라인 함수를 호출하는 곳에 함수 몸제(function body)를 포함시켜 컴파일을 한다. 
이렇게 하면 함수 호출에 따르는 오버해드를 피할 수 있으며 매크로 함수의 단점을 해결한다. 

* 장점
  - 실제 함수 호출보다 프로그램 실행속도가 빠르다.
  - 함수 호출 인수와 함수 매개변수의 자료형 검사를 수행한다.
   
* 단점: 
  - 크기가 크거나 복잡한 태스크를 수행하는 함수의 경우 함수 호출의 오버헤드가 함수의 실행 시간에 비교하여 크지 않다.
  - 프로그램에서 모든 함수 호출문이 함수 정의 코드로 대체하기 떄문에 메모리 사용 측면에서 알반 함수보다 블리하다.    

- 함수 호출의 오버헤드: 일반함수를 호출하면 프로그램 실행 위치가 해당 함수의 시작 위치로 옮겨진 후 함수 몸체의 프로그램 코드를 실행한 후 다시 함수를 호출한 위치 다음의 프로그램 코드를 실행시킨다. 
이 처럼 프로그램 실행 위치가 호출된 함수로 옮겨졌다고 다시 돌아오기 위해서는 함수로 옮기기 전의 상태를 저장하였다가 다식 복원해야 하는 일을 수행하여야 한다. 이러한 일련의 과정이 오버해드에 해당한다.

다음 프로그램 코드는 간단히 매개변수에 값을 3씩 더해주는 ```inc(int& x)```함수를 인라인 함수로 구현하고 ```main 함수```에서 20번 호출하는 프로그램이다. 

```c++
inline void inc(int& x) {
	x += 3;
}

int main(int argc, char const *argv[])
{
	int i = 10;
	int count = 1;

	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;
	cout << "(" << count++ << ") "; inc(i); cout << i << endl;

	return 0;
}
```
인라인 함수로 작성된 코드를 다음과 같이 일반 함수로 작성하고 ```main 함수```는 앞의 코드와 동일하게 작성한다.
```c++
void inc(int& x) {
	x += 3;
}
```
인라인 함수로 작성된 프로그램 소스파일(inline_func.cc)과 일반 함수로 작성된 프로그램 소스파일(inline_comp_func.cc)을 작성하고 
파일의 크기와 맥북에서 g++ 컴파일러와 링커를 사용하여 생성한 실행 파일의 크기를 비교하면 다음과 같다.

<img src=./inline_func.png>

소스파일의 크기를 비교하면 인라인 함수로 구현된 ```inline_func.cc``` 소스 파일의 크기가 일반 함수로 구현된 ```inline_comp_func.cc``` 소스 파일보다 7 바이트 더 크다는 것을 확인할 수 있다.
실행파일의 크기를 살펴보면 앞에서 언급한데로 인라인 함수를 사용한 실행파일(56000 바이트)이 일반 함수를 사용한 실항파일(55968)보다 크가가 더 크다. 일반 함수로 작성된 프로그램의 경우 일반 함수에 대한 기계어 코드가 한번 생성되고 호출되는 형태인 반면 인라인 함수의 코드로 작성된 프로그램의 경우 인라인 함수의 코드가 함수 호출 부분에 복사하여 실행 코드를 생성하기 때문이다. 




