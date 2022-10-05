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
