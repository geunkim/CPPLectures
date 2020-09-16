# 클래스 실습


### 복사 생성자

1. 다음의 프로그램을 실행하고 차이점을 분석하고 shallowCopy.cc 를 실행하였을 때 에러가 발생하는 이유를 검토하시오.

* [deepCopy.cc](../SampleCodes/Class/deepCopy.cc)
* [shallowCopy.cc](../SampleCodes/Class/shallowCopy.cc)

2. 아래의 ``Point`` 클래스를 사용하여 ```main()``` 함수에서 다양한 형태의 ```Point``` 클래스의 객체를 생성하고 디폴트 복사 생성자와 디폴트 대입연산자를 사용하고 각 연산의 결과가 제대로 동작하는지 확인하는 코드를 작성하시오.
([참고](../SampleCodes/Class/pointTest.cc))

```c++
class Point{
	int x, y;
public:
	Point(int x = 10, int y = 10);
	void show();
};

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::show(){
	cout << "x: " << x << ", " << "y: " << y << endl;
}

int main(int argc, char const *argv[])
{
	return 0;
}
```

### 복사 대입연산자 

3. 앞의 ``Point`` 클래스에 대해 대입연산자 함수를 재 정의하시오.
([참고](../SampleCodes/Class/pointTest.cc))

```c++
class Point{
	int x, y;
public:
	Point(int x = 10, int y = 10);
	Point& operator = (const Point& v);  // 대입 연산자
	void show();
};
```

### 멤버 초기화 리스트

4. 동영상에서 사용된 ``Point``, ``Line`` 클래스에 대해서 정의하고 멤버 초기화 리스트를 활용하여 멤버 변수를 초기화하는 프로그램을 작성하시오.

### 멤버 인라인 함수

5. 다음의 ``Date`` 클래스의 멤버함수를 인라인 함수로 정의하시오 

```C++
class Date{
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d);
	~Date();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear();
	int getMonth();
	int getDay();
	void printDate();
};

6. 클래스의 객체를 함수의 매개변수로 전달하고 객체를 함수의 반환 값으로 사용하는 함수를 작성하시오.

7. 그외 배운 내용을 검증하는 프로그램을 작성하시오.


