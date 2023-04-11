# 배열의 사용 

다음과 같이 배열이 선언되고 초기화하였다.

```C++
int score[] = {10, 20, 30, 40, 50};
```
* 배열 score의 두 번째 요소에 50을 복사 대입하는 연산
```C++
score[1] = 50; // 배열의 인덱스는 0에서 부터 시작하기 때문에 첫 번째 요소는 인덱스 0, 두 번째 요소는 인덱스 1...
```

* 배열 score의 마지막 요소의 값을 int형 변수 myScore에 대입하는 연산 
```C++
myScore = score[4];
```

* 배열 score의 네 번째 요소의 값을 배열 score의 첫 번째 요소에 복사 대입하는 연산
```C++
score[0] = score[3]
```

## 배열과 반복문과의 만남

배열의 저장되어 있는 데이터들을 모두 화면에 출력한다.
```C++
int store[3] = {50, 40, 30};
cout << store[0] << endl;
cout << store[1] << endl
cout << store[2] << endl;
```
배열의 크기가 10 개일 때도 앞의 코드처럼 ```cout``` 문을 10번 쓰지는 않을 것이다.
이는 "Hello World!" 를 10번 출력하는 것과 달리 대괄호의 인덱스 값이 계쇡 변경되어야 하므로 복사 붙이기도 쉽지 않다.
```cout << store[i] << endl;``` 패턴이 반복되고 i를 0에서 2까지 변경하면 된다.

```C++
int score[3] = {50, 40, 30};
for(int i = 0; i < 3; i++) 
  cout << score[i] << endl; 
```

### 범위 기반 for 문 (Range-based for statement)

범위 기반 ```for 문```은 배열과 같이 다루어야 할 데이터의 개수(범위: range)를 알 수 있는 메모리의 데이터를 반복적으로 접근할 때 유용하개 
사용할 수 있는 반복문이다. 이는 다루어야 하는 데이터의 개수을 알 수 있는 배열에 ```for 문```을 사용하는 경우 복잡하고 오류가 발생하기 쉽다. 
범위 기반 ```for 문```은 새로운 유형의 반복 구조로 배열의 각 데이터으 ㅣ접근의 반복할 수 있는 방법을 제공한다. 

범위 기반 ```for 문```의 구조는 다음과 같다. 

```c++
for(range-declaration : expression) {
  statement;
}
```

* ```expression```: 배열과 같이 여러 개의 데이터가 저장되어 있는 데이터 리스트 
* ```range-declaration```: ```expression```의 하나의 데이터를 저장할 수 있는 변수의 선언 
* ```statement```: ```expression```의 데이터 리스트의 각 값을 처리하는 명령문 

1) 범위 기반 ```for``` 문 사용 예

```c++
for(auto data : {1, 2, 3} {
   cout <<  2 * data << endl;
}
```

```c++
auto v = { 6, 7, 8}
for(auto data : {v} {
   cout <<  data << endl;
}
```

```c++
int list[] = {10, 20, 30};
for(auto i: list) {
  i *= 2;
}
for(auto i: list) {
  cout << i << endl;
}
```
앞의 코드에서 첫 번째 범위 기반 for 문에는 ```auto i```로 배열 list의 원소의 값을 접근하고 있어 배열 list의 각 요소의 값이 변수 ``ì```에 복사가 된다.
복사된 값에 2배를 한 후 저장을 하여도 배열 list에 저장된 값에는 영향을 주지 않는다. 그러므로 앞의 코드는 



```c++
int list[] = {10, 20, 30};
for(auto& i: list) {
  i *= 2;
}
for(auto i: list) {
  cout << i << endl;
}
```


```c++
int score[] = {50, 40, 30};
for(auto data: score)
	cout << data << endl;
```

* [범위 기반 for 문]

## 배열의 복사

배열에 저장된 요소들은 다른 배열로 복사를 하는 경우 기반 대입연산자로는 불가능하다. 
이를 위해서는 하나의 배열에 저장된 데이터를 하나씩 새로운 배열에 복사하여야 한다.
```C++
int source[5] = {70, 80, 90, 100, 50};   // 기존 데이터
int dest[10];                            // 새로운 배열 
for(int i = 0; i < 5; i++) 
  dest[i] = source[i];      // dest[0] = source[0],.. dest[4] = source[4]
```
## 배열의 비교 

두 배열의 관계를 비교할 때 기본 관계연산자(==, !=, <, >, <=, >=)로는 불가능하다.
두 배열이 각 요소에 같은 값이 저장되어 있는지 아닌지를 확인하는 확인해보자.
두 배열을 비교하기 위해서 먼저 두 배열의 크기가 같아야 한다. 

```c++
int source[5] = {70, 80, 90, 100, 50};   // 기존 데이터
int comp1[5] = {70, 80, 90, 100, 50};    // 비교할 배열 1
int comp2[5] = {70, 80, 90, 10, 40};     // 비교할 배열 2
bool same = false;                       // 비교 결과를 저장할 변수

// source 와 comp1 비교 
for(int i = 0; i < 5; i++) {
  if(source[i] == comp1[i]) same = true;
  else same = false;
}
// 여기서 same에 저장된 데이터가 true이면 두 배열을 같은 것, false이면 다른 것 

// source 와 comp2 비교
for(int i = 0; i < 5; i++) {
  if(source[i] == comp2[i]) same = true;
  else same = false;
}
```

배열을 비교에서 source와 comp1의 비교, source와 comp2의 비교를 반복문을 사용하여 표현하였는데
비교하는 데이터만 다를 뿐 프로그램 코드(알고리즘)는 같다.
이렇게 처리 데이터만 다르고 프로그램 코드가 같은 경우를 다루기 위해서 **함수** 라는 개념이 있다.



