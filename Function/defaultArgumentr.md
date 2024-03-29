# 기본 매개변수 (default argument)

함수 원형(function prototype)을 선언할 때 인수의 기본 값을 성절하는 것이 가능하다. 이처럼 인수의 값을 함수 원형을 선언할 때 지정하는 인수를 
기본 매개변수(default argument) 라고 한다. 함수 언형 선언 시 인수의 기본 값을 설정하면 함수 호출를 호출할 때 실 인수를 생략할 수 있다는 장점을 가진다.
죽 매개변수에 값이 전달되지 않는 경우 디폴트 값이 전달되도록 함수를 선언할 수 있다. 
함수 호출 시 실 인수 값을 생략하면 호출 시 지정한 기본 값이 함수에 전달된다. 기본 매개변수에 기본 값을 전달하는 것은 컴파일러에 의해 처리한다. 

기본 인수를 지정한 함수 원형의 선언의 형태는 다음과 같다. 

```C++
반환 자료형 함수이름 (자료형 매개변수명, 자료형 매개변수명 = 기본 값, 자료형 매개변수명 = 기본 값);
```
기본 매개변수는 함수 선언 혹은 함수 원형 선언 시 한 반만 지정한다. 즉 함수 원형 선언 시 기본 매개변수를 지정했다면 함수를 정의할 때 기본 인수를 지정할 수 없다. 

앞에서 보았던 ```sum``` 함수릐 선언에서 기본 매개변수를 선언해보자.

```C++
int sum(int a = 5, int b = 10);    // 기본 매개변수 지정 선언 
```
int a와 b는 기본 매개변수로서 기본 값은 5와 10을 각각 가지도록 선언되었다. 기본 매개변수를 가진 함수를 호출할 떄 인수 값을 생략하느 경우 자동으로 
기본 값이 매개변수로 전달된다. 생략하는 경우 자동으로 기본 갓이 매캐변수로 전달된다. ```sum()``` 한수는 다음과 같이 3개의 형태로 호출할 수 있다.

```C++
sum();            // sum(5, 10); 의미
sum(20);          // sum(20, 10); 의미
sum(200, 100);    // sum(200, 100); 의미
```
## 기본 매개변수 사용할 때 주의할 점

기본 매기변수를 지정한 함수를 선언할 때 주의해야 할 규칙이 있다. 기본 매개변수를 사용하려면 기본 매개변수를 지정하기 위해서는 모두 끝 쪽에 몰려 선언되어야 한다. 
즉 기본 매개변수 선언 후 다음에 일반 매개변수를 선언할 수 없다.  다음과 같이 ```sum()``` 함수를 선언할 때 하나의 매개변수만 기본 매개변수로 
선언하는 경우 컴파일 에러가 발생하는 예와 정상적인 예를 보인다.  

```C++ 
int sum(int a = 5, int b);    // 컴파일 에러 방생 
int sum(int a, int b = 10);    // 컴파일 성공 
```

## 기본 매개변수를 가진 함수에 인수 전달하는 규칙

기본 매개변수를 선언한 함수를 호출할 때 함수의 매캐변수의 수보다 적은 수의 인수를 전달하는 경우 컴파일러가 전달한 인수와 매개변수와의 매핑되는 규칙을 이해하는 것
이 필요하다. 이 규칙을 이해하지 못하면 프로그래머가 원하는 결과를 얻을 수 없기 떄문이다. 앞의  ```sum()``` 함수 호출 예에서 보인 것 처럼 함수 호출 시 
전달된 인수들의 가장 왼쪽의 인수부터 함수의 가장 왼쪽의 매개변수에 전달된다. 

```C++
void f(int a = 0, int b = 0, int c = 0, int d = 0);
```
앞과 같이 함수 ```f()``` 가 선언되어 있을 때 가능한 함수 ```f()``` 호출의 예는 다음의 다섯 가지 이다.

```C++
f();                    // f (0, 0, 0, 0); 의미 
f(10);                  // 실 인수 값 10은 매개변수 a에 전달, f(10, 0, 0, 0) 의미 
f(10, 20);              // 추가된 인수 값 20은 매개변수 b에 전달,  f(10, 20, 0, 0) 의미 
f(10, 20, 30);          // 추가된 인수 값 30은 매개변수 c에 전달, f(10, 20, 30, 0) 의미 
f(10, 20, 30, 40);      // 추가된 인수 값 40은 매개변수 d에 전달 , f(10, 20, 30, 40) 의미 
```

## 기본 매개변수와 함수 오버로딩 

기본 매개변수를 사용하면 함수 오버로딩을 간소화할 수 있는 장점을 가진다. 반대로 이러한 간소화 특성 때문에 애매모호한 경우가 발생할 수 있다. 





