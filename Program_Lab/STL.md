# STL(Standard Template Library) Lab

1. 다음의 코드를 실행 한 후 검토하시오.

```cpp
#include <iostream>

using namespace std;
const int SIZE = 10;

class MyArray
{
private:
	int buf[SIZE];
public:
	MyArray() {
		for (int i = 0; i < SIZE; i++)
			buf[i] = 0;
	}
	int& operator[] (int i);

};

int& MyArray::operator[](int i) {
	if(i >= SIZE) {
		cout << "bad index";
		return buf[0];
	}
	return buf[i];
}

int main(int argc, char const *argv[])
{
	MyArray A;

	A[3] = 9;
	cout << "A[3]: " << A[3] << endl;
	cout << "A[4]: " << A[4] << endl;	
	return 0;
}
```

2. ``int``, ``float``형의 템플릿 클래스 array를 선언하고 템플릿 클래스 array의 멤버 함수와 연산자를 조사하고 각 멤버 함수와 연산자를 활용하여 검증하는 프로그램을 작성하라. (멤버함수 연산자 6개 이상)
(``range-based for loop``와 ``iterator`` 를 활용) 

템플릿 클래스 선언: <array> 헤더 파일에 존재 

```cpp
template <typename T, size_t N> class array;
```

3. ``int``, ``float``형의 템플릿 클래스 vector를 선언하고 템플릿 클래스 vector 의 멤버 함수(insert, push_back 는 필수)와 연산자를 조사하고 각 멤버 함수와 연산자를 활용하여 검증하는 프로그램을 작성하라. (멤버함수 연산자 6개 이상)
(``range-based for loop``와 ``iterator`` 를 활용) 

템플릿 클래스 선언: <vector> 헤더 파일에 존재 

```cpp
template <typename T> class vector;
```

4. 템플릿 클래스 list, set 을 활용하는 프로그램 작성하시오.
