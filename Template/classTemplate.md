# 클래스 템플릿(Class Template)

```template```을 사용하여 제너릭 클래스를 만든다. 템플릿 클래스의 예로는 int, double, char, Box 등의 다양한 자료형의 데이터를 저장하는 스택이 있다. 
스택 클래스는 데이터의 자료형만 다를 뿐 알고리즘은 동일하다. 함수 템플릿과 같이 클래스 템플릿**틀**을 정의하여 다양한 자료형의 데이터를 처리하는 
클래스를 생성하는 기능이다. 이 틀을 클래스 템플릿 클래스의 멤버 함수는 자동 템플릿 함수이다.

템플릿 클래스의 선언은 다음과 같이 작성한다. 
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
템플릿 클래스의 선언은 일반 클래스의 선언과 비슷하다. 단 템플릿 클래스가 처리하는 데이터의 자료형 대신 템플릿 자료형 T를 사용한다. 
앞에서 선언한 myArray 템플릿 클래스를 이용하여 int, double, char의 자료형을 가진 객체를 생성하는 방법은 다음과 같다.
```C++
myArray <int> arr;
myArray <double> arr;
myArr <char> arr;
```
템플릿 클래스에서 멤버함수의 정의는 템프릿 함수와 같은 형태를 가진다. 
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
