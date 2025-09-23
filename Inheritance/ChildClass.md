# 자식 클래스 정의 
자식클래스란 큰 틀이 되는 부모클래스의 멤버 변수와 함수를 사용하는 것이다. 자식클래스에서도 멤버 변수나 함수를 추가하여 사용할 수 있으며, 부모클래스에서는 사용할 수 없다.

자식클래스는 다음과 같이 선언한다.
```cpp
class <자식클래스 이름> : <접근 지정자> <부모 클래스 이름> 
{
	// 자식 클래스에서 추가할 멤버 변수와 함수
};
```

자식클래스에서 부모클래스의 멤버 변수나 함수에 접근하는 방법은 ```<부모 클래스 이름>::<접근할 멤버 이름>;``` 이다.

다음은 ’탈 것‘이 부모클래스가 되는 예제이다.

```cpp
class Vehicle
{
private:
	int person = 0;    // 탑승인원
	int baggage;       // 화물 무게
public:
	void ride()  // 탑승
	{
		person++;
	}
	void load(int weight);   // 짐 싣기
	void getOff();   // 하차
	int getPerson()  // 탑승인원 확인
	{
		return person;
	}
};

class Cruise :public Vehicle
{
private:
	int room;    
public:
	void setRoom(int room);    // 크루즈의 방 수 설정
	void countPerson()
	{
		cout << Vehicle::getPerson() << endl;     // 부모클래스 호출
	}
};

class AirPlane :public Vehicle
{
private:
	int seat;    
public:
	void setSeat(int seat);    // 자리 수 설정
	void countPerson()    // 탑승인원 확인
	{
		cout << Vehicle::getPerson() << endl;     // 부모클래스 호출
	}
};

int main(int argc, char const* argv[])
{
	Cruise dolphin;
	dolphin.ride();    // 부모클래스 멤버함수  접근
	dolphin.load(10);  // 부모클래스 멤버함수  접근
	dolphin.countPerson();     // 자식클래스 멤버함수 호출
  
	AirPlane cppAir;
	cppAir.ride();    // 부모클래스의 멤버함수 접근
	cppAir.load(20);  // 부모클래스 멤버함수  접근 
	cppAir.countPerson();     // 자식클래스 멤버함수 호출
}
```

크루즈와 비행기를 만든다 하면 기본적으로 탑승 인원, 화물 무게를 가져야 할 것이고, 손님이 타고 내리고 짐을 싣는 행위가 있을 것이다. 두 대상의 공통된 점을 가진 ```class Vehicle``` 가 부모클래스이다. 크루즈에만 설정되는 최대 수용 인원에 맞추어 방 수를 설정하고 탑승 인원 확인을 추가하여 ```class Vehicle``` 의 자식클래스인 ```class Cruise :public Vehicle``` 를 선언한다. 비행기에서는 가능한 무게에 대해 자리 수를 설정하고 탑승 인원 확인을 추가하여 ```class AirPlane :public Vehicle``` 를 선언한다. 


## 단일 상속

```c++
#include <iostream>
#include <string>
using namespace std;

// 부모 클래스 (기반 클래스)
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

// 자식 클래스 (파생 클래스)
class Student : public Person {
private:
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

int main() {
    Student s("홍길동", 21, "컴퓨터공학");
    s.introduce();   // 부모 클래스 함수 사용
    s.study();       // 자식 클래스 함수 사용
    return 0;
}
```

## 다중 상속

```c++
#include <iostream>
using namespace std;

class Teacher {
public:
    void teach() {
        cout << "강의를 하고 있습니다." << endl;
    }
};

class Researcher {
public:
    void research() {
        cout << "연구를 하고 있습니다." << endl;
    }
};

// 다중 상속
class Professor : public Teacher, public Researcher {
public:
    void introduce() {
        cout << "저는 교수입니다." << endl;
    }
};

int main() {
    Professor p;
    p.introduce();
    p.teach();
    p.research();
    return 0;
}
```

# 오버라이딩
```c++
#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {  
        cout << "동물이 소리를 냅니다." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "야옹!" << endl;
    }
};

int main() {

    Animal a1;
    Dog a2; 
    Cat a3;

    a1.speak();  
    a2.speak();
	a3.speak();
	
    return 0;
}
```

