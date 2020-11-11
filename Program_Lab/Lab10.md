# Template Lab

1. 함수 오버로딩 정의하기
배열의 시작 주소(arr)와 배열의 원소 개수(num)를 입력받아 배열의 모든 원소의 값을 
더하는 함수를 정의.

```cpp
int sum(int *arr, int num);
double sum(double *arr, int num);
long sum(long *arr, int num);
float sum(float *arr, int num);
```

2. 1번의 오버로딩 함수를 템플릿 함수로 정의하고 다양한 자료형에 대해서 호출하여 검증하시오.

```cpp
template <typename T> 
T sum(T *arr, int num);
```

3. 2번의 템플릿 함수 선언과 정의를 다른 소스 파일에 구현하여 분할 컴파일을 하고 검증하시오.


4. 수를 입력받아 절대 값을 구하는 함수 ``myAbs`` 를 템플릿 함수로 정의하고 검증하시오.

```cpp
int myAbs(int a);
double myAbs(double a);
long myAbs(long a);
float myAbs(flaot a);
```


5. 다음 템플릿 클래스 ``Storage``에 대한 생성자와 멤버함수를 정의하고 검증하시오.

```cpp
template <typename T>
class Storage {
	T m_data;
public:
	Storage();
	Storage(T data);
	T getData();
	void setData(T data);
};
```

6. 다음 ``Counter`` 템플릿 클래스를 정의를 검증하는 코드를 작성하고 검증하시오. 사용할 수 있는 자료형의 제약이 있는지 검토하시오.

```cpp
template <typename T>
class Counter{
	T value;
public:
	Counter() { value = 0;}
	Counter(T n) { value = n;}
	T getValue() {return value;}
	void operator ++() {++value;}
	void operator --() {--value;}
};
```


7. ``SampleCodes/Template`` 디렉토리의 코드를 실행하고 분석하시오.



