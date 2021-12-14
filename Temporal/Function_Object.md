# 함수 객체

## 함수 객체란 

[함수 객체](https://github.com/geunkim/DataStructure_Algorithm/blob/main/Basic_CPP.md#%ED%95%A8%EC%88%98-%EA%B0%9D%EC%B2%B4-function-object)

### 함수 객체 및 컨테이너

C++ 표준 라이브러리는 ```<functional>``` 헤더 파일에 여러 함수 객체를 포함한다. 함수 객체의 사용은 컨테이너의 정렬 기준이다.
에로 다음과 같은 ```set``` 컨테이너 선언이 있다.

```c++
template <class Key, class Traits=less<Key>, class Allocator=allocator<Key>> class set
```
두 번쨰 템플릿 매개변수인 ```less``` 가 함수 객체이다. 이 함수 객체는 첫 번째 파라미터가 두 번째 파라미터보다 적으면 **true**를 반환한다.
```set```, ```map```과 같은 컨테이너는 요소를 정렬하기 때문에 컨테이너는 두 요소를 비교하는 방법이 필요하다. 
비교는 함수 객체를 이용하여 행해지며 함수 객체를 생성하여 컨테이너에 대한 프로그래머가 규정한 정렬 기준을 정의할 수 있고 컨테이너 내의 템플릿 리스트에 적용할 수 있다.

### 함수 객체 및 알고리즘 

함수 객체의 또 다른 용도는 알고리즘이다. 
