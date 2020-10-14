

1번 문제
```C++
// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Base {
	int v1;
protected:
	int v2;
public:
	int v3;

	void setV1(int i) { v1 = i; }
	void printVal() { cout << v1 << ", " << v2 << ", " << v3 << endl; }
};

class Derived1 : private Base
{
public:
	void setV1_new(int i) { setV1(i); }
	void setV2(int i) { v2 = i; }
	void setV3(int i) { v3 = i; }
	void printVal_new() { printVal(); }
};

class Derived2 : protected Base
{
public:
	void setV1_new(int i) { setV1(i); }
	void setV2(int i) { v2 = i; }
	void setV3(int i) { v3 = i; }
	void printVal_new() { printVal(); }
};

class Derived3 : public Base
{
public:
	void setV2(int i) { v2 = i; }
};


int main(int argc, char const *argv[]) {
	
	// private
	Derived1 a;
	a.setV1_new(1); a.setV2(2); a.setV3(3);
	a.printVal_new();
	cout << endl;

	Derived2 b;
	b.setV1_new(10); b.setV2(20); b.setV3(30);
	b.printVal_new();
	cout << endl;
	
	Derived3 c;
	c.setV1(100); c.setV2(200); c.v3 = 300;
	c.printVal();

	/* code */
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


```

2번 문제
```C++
#include "pch.h"
#include <iostream>
using namespace std;
class Person
{
	string names;
	string address;
	string tel;
public:
	Person();
	Person(string, string, string);
	~Person();

};

Person::Person() :
	names { "Doe" }, 
	address { "010-3305-3383" }, 
	tel { "no-telephone" } 
{ cout << "new Person Born!!!" << endl; }
Person::Person(string a, string b, string c) :
	names { a }, 
	address { b }, 
	tel { c } 
{ cout << "new Person Born!!!" << endl; }
Person::~Person() { cout << "somebody Dead!!!" << endl; }

class Professor : public Person
{
public:
	Professor();
	~Professor();
	void teach();
};
Professor::Professor() { cout << "hi professer" << endl; }
Professor::~Professor() { cout << "bye professer" << endl; }
void Professor::teach() { cout << "professer teach()" << endl; }

class TennisPlayer : public Person
{
public:
	TennisPlayer();
	~TennisPlayer();
	void playTennis();

};
TennisPlayer::TennisPlayer() { cout << "hi player" << endl; }
TennisPlayer::~TennisPlayer() { cout << "bye player" << endl; }
void TennisPlayer::playTennis() { cout << "player plays tennis" << endl; }

class Businessman : public Person
{
public:
	Businessman();
	~Businessman();
	void runBusiness();
};

Businessman::Businessman() { cout << "hi businessman" << endl; }
Businessman::~Businessman() { cout << "bye businessman" << endl; }
void Businessman::runBusiness() { cout << "businessman work" << endl; }

int main(int argc, char const *argv[])
{
	Person a;
	Professor b; b.teach();
	TennisPlayer c; c.playTennis();
	Businessman d; d.runBusiness();
	return 0;
}
```
