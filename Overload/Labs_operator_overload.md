# 연산잔 오버로드 실습

1. 다음 코드를 컴파일하였을 때 발생하는 문제의 원인을 분석하고 컴파일이 발생하지 않도록 수정 후 실행한 결과를 분석하라.

```c++
#include <iostream>

using namespace std;

class citizen {
	string name;
	int age;
public:
	citizen(string name, int age) : name(name), age(age) {}
//friend ostream & operator << (ostream &os, const citizen& c);
};

//ostream & operator << (ostream &os, const citizen& c){
//	os << "[" << c.name << ", " << c.age << "]";
//	return os;
//}

int main(int argc, char const *argv[])
{
	citizen c1("Gil-Dong Hong", 20);
	
	cout << c1 << endl;
	return 0;
}
```


2. 다음 코드를 실행하고 두 개의 Distance를 더하고 빼는 연산자를 추가하라. 또한 displayDistance()를 연산자 "<<" 로 대체할 수 있도록 코드를 수정하라.


```c++
/*
	File Name: unaryOperators.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

class Distance{
	int feet;    
	int inches; //0 to 12. (1 feet = 12 inches ..)
public:
	Distance(int f = 0, int i = 0): feet(f), inches(i) {}
	void displayDistance() {
		cout << "F: " << feet << ", I: " << inches << endl;
	}
	Distance operator - () {
		return Distance(-feet, -inches);
	}
  // +, - 연산자 중복 추가 
};

int main(int argc, char const *argv[])
{
	Distance D1(11, 10), D2(-5, 11);
	Distance T;
	T = -D1;
	D1.displayDistance();
	T.displayDistance();

	T = -D2;
	D2.displayDistance();
	T.displayDistance();
	return 0;
}
```

3. 다음 두 프로그램을 실행하고 분석하라. 

```c++
#include <iostream>

using namespace std;
class Rect;
bool operator == (const Rect& a, const Rect& b);

class Rect
{
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	friend bool operator == (const Rect& a, const Rect& b);
};

bool operator == (const Rect& a, const Rect& b) {
 	return ((a.width == b.width) && (a.height == b.height));
}

int main(int argc, char const *argv[])
{
	Rect a(5, 5), b(5, 5);
	if(a == b) cout << "Equal" << endl;
	else cout << "Not equal" << endl;
	return 0;
}
```

```c++
#include <iostream>
using namespace std;

class Rect
{
	int width, height;
public:
	Rect(int w, int h) : width(w), height(h) {}
	bool operator == (const Rect& b);
};

bool Rect::operator == (const Rect& b) {
 	return ((this->width == b.width) && (this->height == b.height));
}

int main(int argc, char const *argv[])
{
	Rect a(5, 5), b(5, 5);
	if(a == b) cout << "Equal" << endl;
	else cout << "Not equal" << endl;
	return 0;
}
```
4.  다음 연산자의 오버로딩을 구현하고 검증하라.

```c++
class Time
{
	int hour, min, sec;
public:
	Time(int h, int m, int s) : hour(h), min(m), sec(s){}
	~Time(){};
  
  Time& operator = (Time& T);   // 대입 연산자 
	bool operator == (Time& T);
	bool operator != (Time& T);
	bool operator > (Time& T);
	bool operator < (Time& T);
  friend ostream& operator << (ostream& os, const Time& t);
};
```

5. 다음 myString 클래스를 구헌하고 검증하라.

```c++
class myString
{
	char* buf;		// 문자열 데이터가 저장된 메모리 식작 조사 		
	int length;		// 문자열의 길이 
	int capacity;  	// 할당된 메모리 용량
public:
	myString();
	myString(const char* str);		// 
	myString(const myString& str);  // 복사 생성자
	~myString();

	int length() const;
	int capacity() const;
	char at(int i) const;

	bool operator==(myString& str);
	bool operator > (myString& str);
};


6. 다음 myVector의 연산자 오버로드를 구현하고 검증하라.

```c++
class myVector
{
	double x, y;
public:
	myVector(double x = 0.0, double y = 0.0):  x(x), y(y){};

	myVector operator+(myVector& V);
	myVector operator-(myVector& V);	
  myVector operator-();
  myVector operator++();
  myVector operator++(int);
  myVector operator--();
  myVector operator--(int);
	bool operator==(myVector& V);
  friend ostream& operator << (ostream& os, const myVector& v);
};
```


