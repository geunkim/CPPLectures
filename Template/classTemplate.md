# 클래스 템플릿(Class Template)

```template```을 사용하여 제너릭 클래스를 만든다. 클래스 템플릿의 예로는 int, double, char, Box 등의 다양한 자료형의 데이터를 저장하는 스택이 있다. 
스택 클래스는 데이터의 자료형만 다를 뿐 알고리즘은 동일하다. 
함수 템플릿과 같이 클래스 템플릿 **틀**을 정의하여 다양한 자료형의 데이터를 처리하는 클래스를 생성하는 기능이다. 
이 틀을 클래스 템플릿 클래스의 멤버 함수는 자동 템플릿 함수이다.

클래스 템플릿의 선언은 다음과 같이 작성한다. 
```C++
template <typename T>   // T: 클래스에서 다루는 데이터의 자료형 
class myArray {
private:
  T data[100];
public:
  void setData(int idx, T d);
  T getData(int idx);
};
```
클래스 템플릿의 선언은 일반 클래스의 선언과 비슷하다. 단 클래스 템플릿이 처리하는 데이터의 자료형 대신 템플릿 자료형 T를 사용한다. 
앞에서 선언한 myArray 클래스 탬플릿을 이용하여 ```int```, ```double```, ```char```의 자료형을 가진 객체를 생성하는 방법은 다음과 같다.

```C++
myArray <int> arr;
myArray <double> arr;
myArr <char> arr;
```
클래스 템플릿에서 멤버함수의 정의는 함수 템플릿과 같은 형태를 가진다. 

```C++
template <typename T>
<반환 자료형> 클래스 이름<자료형 이름 목록>::멤버 함수 명(인수 목록)
```

앞의 setData, getData 멤버 함수의 정의는 다음과 같다.
```C++
template <typename T>
void setData(int idx, T d) {
  data[idx] = d;
}

template <typename T>
T getData(int idx) {
  return data[idx];
}
```
클래스 템플릿을 사용하면 다양한 자료형을 처리하는 클래스와 객체를 쉽게 만들 수 있다. 

다음은 클래스 템플렛을 활용하여 데이터를 저장하는 예제이다.

```cpp
#include <iostream>
using namespace std;

template <typename T>  // 클래스 템플릿 선언
class myArray
{
private:
    T data[10];
public:
    void setData(int idx, T d)
    {
        data[idx] = d;
    }
    T getData(int idx)
    {
        return data[idx];
    }
};

int main(int argc, char const* argv[])
{
    myArray<int> d1;  // int 자료형 메모리 할당
    d1.setData(0, 10);

    myArray<double> d2;   // double 자료형 메모리 할당
    d2.setData(0, 10.5);

    cout << d1.getData(0) << endl;
    cout << d2.getData(0) << endl;

    return 0;
}
```

이 프로그램의 실행 결과는 다음과 같다. 

```
10
10.5
``` 


