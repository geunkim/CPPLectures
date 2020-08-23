# 특수화(Specialization)
암시적 구체화, 명시적 구체화, 명시적 특수화를 모두 특수화라 부른다. 
## 명시적 특수화(Explicit Specialization)
템플릿의 특수화란 템플릿을 사용할 때, **특정 자료형에 대해서는 다른 처리를 하고 싶을 때** 사용한다. 특정 타입의 변수가 들어오면 따로 정의한 함수로 처리를 한다. 만약 매개변수의 자료형이 int 형일 때, 템플릿의 동작을 수행하는 것이 아닌 다른 동작을 수행하고 싶을 때 사용하는 것이 명시적 특수화이다. 

명시적 특수화를 사용하기 위한 조건이 있다. 
1.	함수의 매개변수의 개수가 같아야 한다.
2.	함수 템플릿 반환형과 동일해야 한다.
3.	반환형 앞에 template<>를 붙인다.
명시적 특수화에는 2가지가 있는데 함수 템플릿일때와 클래스 템플릿일때가 있다

### 함수 템플릿의 명시적 특수화
함수 템플릿의 명시적 특수화의 사용 방법은 다음과 같다. 
```cpp
Template<> ReturnType 템플릿명 <자료형> (매개변수자료형 t1, 매개변수자료형 t2, …);
```
함수 템플릿의 명시적 특수화의 예시이다.
```cpp
template <typename T>
T add (T x, T y)
{
return x + y;
}
```
위와 같은 템플릿이 있다고 가정하였을 때, int형으로 명시적 특수화를 하게 되면 다음과 같다.
```cpp
Template<>
int add<int>(int x, int y)
{
return x + y + 21;
}
```
이처럼 명시적 특수화를 사용하게 되면 특정 자료형일 때, 다른 처리를 하게 할 수 있다. <>을 이용한 자료형을 지정하는 것은 매개변수의 자료형이 알려주기 때문에 빼도 상관없다. 

### 클래스 템플릿의 특수화
클래스 템플릿은 클래스 템플릿 또한 함수 템플릿과 같이 특수화가 있다. 함수 템플릿의 이유와 같이 특정 자료형을 다른 처리를 하기 위해서 존재한다. 다만, 클래스 템플릿의 특수화는 2가지 종류가 있다. 함수 템플릿과 같이 명시적 특수화가 있으며, 클래스 템플릿에서만 가능한 부분 특수화가 있다. 

클래스 템플릿의 명시적 특수화의 예시이다. 함수 템플릿의 명시적 특수화의 방식과 동일하다.
```cpp
template <typename T>
class myArray
{
private:
 T data[100];
public:
void setData(int idx, T d);
T getData(int idx);
};
```
라는 클래스 템플릿이 있다고 가정하였을 때, 이것을 명시적 특수화를 하게 되면
```cpp
template <>
class myArray<double>
{
private:
 double data[100];
public:
void setData(int idx, double d);
double getData(int idx);
};
```
가 된다. 클래스 앞에 <double>과 같은 자료형을 붙여 double형에 대하여 특수화를 할 것임을 알려준다. 
### 부분 특수화(Partial specialization)
클래스 템플릿에서만 가능한 특수화이다. 	템플릿의 포괄성을 일부 제한한다. 
다음은 부분 특수화의 예시이다. 
```cpp
template<typename T1, typename T2>
class myArray
{
private:
 T1 data1[100];
 T2 data2[50];
public:
void setData1(int idx1, T1 d1);
void setData2(int idx2, T2 d2);
T1 getData1(int idx1);
T2 getData2(int idx2);
};
```
위와 같은 클래스 템플릿이 있다고 가정하였을 때, 부분 특수화를 하게 되면
```cpp
template<typename T1 >
class myArray<T1, double>
{
private:
 T1 data1[100];
 double data2[50];
public:
void setData1(int idx1, T1 d1);
void setData2(int idx2, double d2);
T1 getData1(int idx1);
Double getData2(int idx2);
};
```
이렇게 되게 된다. 여기서 주의할 점은 클래스의 이름 뒤에 <>안의 T1은 특수화가 적용되지 않는다.

다음은 함수 템플릿의 구체화이다. 

## 구체화(instantiation)

구체화란 템플릿 함수가 함수 템플릿으로 변하는 것을 말한다. 이 때 ‘템플릿 함수와 함수 템플릿은 같은 것 아닌가? ’라고 생각할 수 있는데 둘은 다른 말이다. 함수 템플릿은 함수를 만들기 위한 템플릿이고, 템플릿 함수는 이를 통해 생성된 함수를 말한다. 
구체화의 종류에는 2가지가 있다. 암시적 구체화(implicit instantiation)와 명시적 구체화(explicit instantiation)가 있다. 

### 암시적 구체화(implicit instantiation)

암시적 구체화는 컴파일러가 함수의 호출을 보고 템플릿 함수를 알아서 만드는 것을 말한다.

### 명시적 구체화(implicit instantiation)

 함수가 요구하는 특정 자료형을 명시적으로 컴파일러에게 알려주어 함수 템플릿을 만드는 것을 말한다. 특정 자료형에 대한 템플릿 함수를 만들고 싶을 때 사용한다.
