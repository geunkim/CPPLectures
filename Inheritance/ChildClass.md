# 자식 클래스 정의 
자식클래스란 큰 틀이 되는 부모클래스의 멤버 변수와 함수를 사용하는 것이다. 자식클래스에서도 멤버 변수나 함수를 추가하여 사용할 수 있으며, 부모클래스에서는 사용할 수 없다.

자식클래스는 다음과 같이 선언한다.
``` 
class <자식클래스 이름> : <접근 지정자> <부모 클래스 이름> 
{
	// 자식 클래스에서 추가할 멤버 변수와 함수
};
```

다음은 ’탈 것‘이 부모클래스가 되는 예제이다.

```
class Vehicle
{
private:
	int person;    // 탑승인원
	int baggage;   // 화물 무게

public:
	void ride(int person);  // 탑승
	void load(int weight);  // 짐 싣기
	void getOff();  // 하차
};

class Cruise :public Vehicle
{
private:
	int crew;   // 승무원 탑승인원
	int room;   // 크루즈의 방 수

public:
	void takeCrew(int crew);   // 승무원 탑승
	void setRoom(int room);  // 크루즈의 방 수 설정
};

class AirPlane :public Vehicle
{
private:
	int crew;   // 승무원 탑승인원
	int seat;   // 비행기 자리 수

public:
	void takeCrew(int crew);   // 승무원 탑승
	void setSeat(int seat);   // 자리 수 정하기
};

int main(int argc, char const* argv[])
{
	Cruise dolphin;
	dolphin.ride(10);
	dolphin.getOff();

	AirPlane CppAir;
	CppAir.ride(10);
	CppAir.getOff();
}
```

```class Vehicle``` 은 부모클래스가 되고 ```class Cruise```, ```class AirPlane```이 부모클래스를 상속받은 자식클래스가 된다. ```main``` 함수에서 자식클래스로 변수를 선언한 후 부모클래스의 멤버함수를 자유롭게 사용할 수 있는 것을 확인할 수 있다.
