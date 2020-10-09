# const, static, 상속 실습

다음의 문제를 해결하기 위한 프로그램을 작성하시오.

## const, static 실습

1. 다음 코드는 Vehicle 클래스를 상속 받아 Car 클래스를 정의하였다. main 함수에서 ```Car::getNumObj()``` 함수를 두번 호출한 결과가 각각 5, 3으로 출력되도록 한다. 
이러한 결과를 얻을 수 있도록 ```Car``` 클래스에 멤버 변수와 멤버 함수를 추가 및 관련해아 코드를 추가하시오.


```cpp
#include "iostream"
using namespace std;


class Vehicle
{
	int numTire;
public:	
	Vehicle() { cout << "Vehicle create"<< endl; }
	~Vehicle() {cout << "Vehicle delete" << endl;}
	Vehicle(int nT): numTire(nT) {}
	void setNumTire(int t) {numTire = t;}
	int getNumTire() {return numTire; }
};

class Car : public Vehicle
{
	int numSeat;
public:
	Car() { cout << "Car create" << endl; }
	Car(int nT, int nS): numSeat(nS), Vehicle(nT) { }
	void setNumSeat(int a) { numSeat = a;}
	void setAttr(int t, int s) { setNumTire(t); numSeat = s;}
	~Car() {cout << "Car delete" << endl; }
	void printAll() {
		cout << "numTire: " << getNumTire()  << " numSeat:  " << numSeat << endl;
	}	
};

int Car::numObj = 0;

int main(int argc, char const *argv[])
{
	Car c1(4, 5), c2, c3;
	{
		Car c4, c5;
		cout << Car::getNumObj() << endl;  // 5 출력
	}

	cout << Car::getNumObj() << endl;      // 3 출력

	return 0;
}
```

2. count에 Circle 클래스의 객체가 생성된 수를 저장하고 객체가  없어지면 count의 값이 줄어들도록 클래스의 멤버함수를 정의하고 main 함수 내에서 동작됨을 확인하시오.
  - getCount()는 count 값의 접근자로 이를 구현하고 radius 값의 접근자 getRadius() 메소드를 구현하고 이것이 정적 멤버함수로 가능한지 확인하시오.

```cpp
class Circle{
	double x, y;
	double radius;
	static int count;
public:
	Cicle () : x{0.0}, y{0.0}, radius{2.0} {}
	Circle (double a, double b, double c) : x{a}, y{b}, radius(c) {}
	static int getCount();
	~Circle() {}
};
````

3. ``const 멤버 변수``, ``const 멤버 함수``, ``const 객체`` 의 특징을 이해할 수 있는 프로그램을 작성하시오.


## 상속 실습

4. 상속에서 부모 클래스와 자식 클래스의 생성자와 소멸자가 호출되는 순서를 확인할 수 있는 프로그램을 작성하고 프로그램 결과를 기반으로 호출 순서에 대해서 셜명하시오. 





## 그 외

5. 다음 클래스의 멤버함수를 정의하고 ```main``` 함수에서 ```Singleton``` 클래스의 인스턴스를 생성하고. 생성된 인스턴스에 대해 ```getInstance(),cummulate(), getTotal()``` 함수를 호출하고 각 동작이 어떻게 이루어지는지 설명하시오.
 
(제약사항: 
   - getInstance() 함수 내에서는 객체가 생성되지 않았으면 생성하고 주소값을 반환하고 이미 생성된 객체의 주소 값을 반환 
)

```c++
class Singleton{
	Singleton(){};   // 생성자가 private member 함수
	static bool instanceFlag; // Singleton 객체가 생성되면 true, 삭제되면 false
	static Singleton* instance;  // 생성된 객체의 주소 값을 저장 
	int total;                // 객체가 생성될 때 값은 0으로 초기화 
public:
	static Singleton* getInstance(); // Singleton 객체를 반환하는 함수 (한번 생성하고 공유할 수 있도록 함)
	~Singleton() {}
	void cummulate(int value); // 입력 파러미터 value를 total에 더하기 
	int getTotal();            // 

};
```

6. GitHub의 ``\SampleCodes\MemoryStructure`` 와 ``\SampleCodes\Inheritance``에 들어갈 static, const, 상속과 관련한 프로그램을 각각 1개 이상 (총 3개 이상) 작성하시오.

