# 정적 클래스, 정적 멤버변수, 정적 멤버함수, 정적 상수 (static class, static member varialbe, static member function, const static member)

## 정적 멤버

클래스로부터 객체가 생성되면 클래스에서 선언된 일반적인 멤버는 "객체 단위의 멤버"로 객체들 마다 각기 다른 값을 가질 수 있는 독립된 변수이다. 
```C++
class Rect {
  int width, height;
public:
  int getArea() { return width * height; }
 };
```
앞의 Rect 클래스로 부터 객체를 r1, r2, r3를 생성하면 각 객체마다 별도의 width, height 변수를 가진다. 

정적 멤버는 "클래스의 멤버"로 객체마다 독립적으로 변수가 선언되는 것이 아니라 클래스에 하나의 변수만 할당되고 생성된 객체들의 정적 멤버는 할당된 저장공간을 공유한다. 
정적 멤버(static member)는 다음과 같은 경우에 사용될 수 있다.
* 프로그램에서 Rect 클래스로 부터 생성된 객체의 수를 알고 싶은 경우
* Rect 클래스의 버전 또는 개발 정보를 클래스에 남기고 싶은 경우 

멤버변수 중 정적 멤버는 static 키워드를 붙여서 선언한다.

#### static 키워드의 특성
변수와 함수는 메모리에 저장 공간을 할당받은 후 삭제되는 (생겨나고 없어지는) 시간적인 개념을 뜻하는 생명 주기(life cycle)와 사용이 가능한 영역(프로그램 코드의 공간) 을 뜻하는 사용 범위(Scope)가 암묵적으로 또는 명시적으로 규정된다. static 키워드로 명시된 변수나 함수는 프로그램이 시작할 때 생성되고 프로그램이 종료할 때 소멸되며 사용 범위는 변수나 함수가 선언된 범위 내에서 사용되며 전역(global) 또는 지역(local)으로 구분된다. 
non-static 멤버 변수는 객체가 생성될 때 저장공간이 할당되며 각 객체마다 별도의 저장공간이 생성되고 객체가 사라질 때 저장공간도 삭제된다. 즉 non-static 멤버 변수의 생명 주기는 객체의 생명 주기와 같다. 반면에 static 멤버 변수는 객체의 멤버 변수이나 객체가 생성되기 전에 저장 공간이 할당되고 객체가 사라져도 할당된 저장 공간은 해지되지 않는다. static 멤버 변수는 클래스에 한번 저장 공간을 할당받는 것으로 저장 공간은 생성된 객체들 사이에서 공유된다.      

### 정적 멤버변수 (static member variable)
다음 코드는 static 멤버 변수를 가지는 Rect 클래스의 예이다. 
 ```C++
class Rect
{
	int width, height;
	static int count;
public:
	Rect() {count++;}
	~Rect() {count--;}
	int getNum() {return count;}
};

int Rect::count = 0;
```
width와 height는 객체 단위의 변수로 Rect 클래스로 부터 생성된 **각 객체**들의 특징인 width와 height 값은 각각 가지게 되나
count는 static 멤버로 Rect 클래스로 부터 생성된 **모든 객체**들이 공유하는 값(의미: 객체 개수)을 표현한다. count는 Rect 객체의 개수에 관게없이 하나만 생성되고 모든 Rect 객체가 공유한다. count는 Rect 객체가 생성될 때 호출되는 생성자에서 1 증가시키고 소멸자에서는 1일 감소하여 생성된 객체의 수가 count에 저장될 수 있도록 한다. 

**static 멤버 변수는 변수의 저장 공간을 할당받기 위해서 클래스 외부에서 전역변수로 선언되어야 한다.** 이 선언문이 없으면 데이터를 저장할 저장 공간이 할당되지 않았기 때문에 링크 에러가 발생한다. 아래의 코드는 count 변수를 선언한 것으로 static 변수이기에 암묵적으로 0으로 초기화된다. 
```C++
int Rect::count;
```
앞에서 선언한 Rect 클래스에 대해 다음과 같이 객체를 생성하는 코드 예가 있다.
```C++
int main(int argc, char const *argv[])
{			  // 영역 1
	Rect r1, r2;
	cout << "(1)# of Rect: " << r1.getNum() << endl;
	{         // 영역 2
		Rect r3;  // 영역 2에서 유효한 객체 (r1, r2, r3)
		cout << "(2)# of Rect: " << r3.getNum() << endl;
	}
	// 영역 1에서 유효한 객체 (r1, r2)
	cout << "(3)# of Rect: " << r2.getNum() << endl;
	
	return 0;
}
```
앞의 프로그램은 main함수(영역 1)내 영역 2가 존재하는 경우를 보인다. 영역 1에서는 Rect 클래스의 객체 r1, r2가 생성되고(r1, r2의 생성자 호출) 영역 2에서 
r3가 생성하였다(r3의 생성자 호출). r3의 사용범위는 영역 2이기 때문에 영역 2를 벗어 나면서(r3의 소멸자 호출) r3 객체는 사리지게 된다. 그러므로 실행 결과는 다음과 같다. 
```C++
(1)# of Rect: 2
(2)# of Rect: 3
(3)# of Rect: 2
```
**정적 멤버변수는 객체 간의 통신(데이터를 주고 받음)에 활용될 수 있다.**

## 정적 멤버함수 (static member function)
멤버함수도 정적 멤버함수로 선언할 수 있다. 정적 멤버함수도 정적 멤버변수와 같이 특정 객체에 종속되지 않는 것으로 객체를 생성하지 않고도 호출이 가능하다. 객체가 생성되지 않았기 때문에 클래스 이름을 직접 사용한다. 
정적 멤버함수의 특성은 정적 멤버변수의 특성과 같다.
* 정적 멤버함수가 선언된 클래스의 모든 객체가 공유한다.
* public 접근지정자를 통해 선언되면 외부에서 class의 이름을 통해 접근이 가능하다.
* 정적함수는 객체의 맴버로 존재하는 것이 아니다.

```C++
class Rect
{
	int width, height;
	static int num;                        // 정적 멤버변수
public:
	Rect() {num++;}
	~Rect() {num--;}
	static int getNum() {return num;}      // 정적 멤버함수
	static int getWidth() {return width;}  // 정적 멤버함수 (접근 오류) 
};
```
앞의 프로그램은 Rect 클래스의 선언으로 getNum()와 getWidth() 의 두개의 정적 멤버함수가 정의되어 있다. 이 중 getNum() 멤버함수는 정적 멤버변수인 num의 값을 참조하는데 getWidth() 멤버함수는 일반 멤버변수인 width 값을 참조하고 있다. getWidth() 는 정적 멤버함수로 객체가 생성되지 않아도 호출될 수 있기 때문에 객체가 생성되어야 저장 장소를 할당받는 일반 멤버변수를 접근하는 것을 가능하지 않다. 그러므로 getWidth() 정적 멤버함수의 정의에서 컴파일 에러가 발생한다.
즉, 정적 멤버함수 내에서는 정적 멤버변수와 정적 멤버함수만 호출할 수 있다.
```C++
class Rect
{
	int width, height;
	static int num;
public:
	Rect() {num++;}
	~Rect() {num--;}
	static int getNum() {return num;}
};

int Rect::num;
``` 
앞의 프로그램은 Rect 클래스의 getNum() 멤버함수가 정적으로 선언하고 정의하였다. 
이 클래스의 객체를 생성하고 사용하는 프로그램 예는 다음과 같다.
```C++
nt main(int argc, char const *argv[])
{			  // 영역 1
	Rect r1, r2;
	cout << "(1)# of Rect: " << r1.getNum() << endl;
	{         // 영역 2
		Rect r3;  // 영역 2에서 유효한 객체 (r1, r2, r3)
		cout << "(2)# of Rect: " << Rect::getNum() << endl;
	}
	// 영역 1에서 유효한 객체 (r1, r2)
	cout << "(3)# of Rect: " << r2.getNum() << endl;
	
	return 0;
}
```
앞의 main() 함수에서는 정적 멤버함수인 getNum()의 호출을 r1.getNum(), Rect::getNum(), r2.getNum() 의 형태로 할 수 있다. (호출 형태가 다양하지만 실제로 호출 되는 함수는 전부 같은 '메모리에 할당된' 함수이다.)
프로그램의 결과는 앞의 정적 멤버함수의 결과와 같다. 
```C++
(1)# of Rect: 2
(2)# of Rect: 3
(3)# of Rect: 2
```
정적 멤버는 생성된 객체를 가키리는 this를 사용하여  정적 멤버를 가리킬 수 없다.

## 정적 상수 (const static member)
클래스 선언 시 정적 멤버변수로 주로 선언되는 것은 상수이다. 정적 멤버변수로 선언하면 클래스의 모든 객체에서 공유하여 각 객체별 저장 공간을 별도로 선언하지 않기 때문에 메모리를 절약할 수 있다.
정적 상수는 'const static 자료형 변수이름'으로 선언하며, 선언과 동시에 초기화가 가능하다. 이렇게 한번 초기화가 이뤄지면 값을 절대 변경할 수 없다.




