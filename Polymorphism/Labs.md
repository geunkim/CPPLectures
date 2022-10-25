# 프로그램 실습 

1. 다음 프로그램을 사용하여 프로그램 전체와 가상 함수의 사용 방법을 분석하라.
(a) friend ostream& operator <<(ostream& os, Position const& pos) 에서 ``const``키워드가 없는 경우와
있는 경우 어떤 차이가 있나?

```c++
#include <iostream>
using namespace std;

struct Position {
	int x, y;
	Position(int px, int py) : x(px), y(py) {}
	friend ostream& operator <<(ostream& os, Position const& pos) {
		os << "Position info: " << pos.x << ", " << pos.y << endl;
		return os;
	}
};

class BaseUnit {
protected:
	Position p;
public:
	BaseUnit(int px, int py) : p(px, py) { }
	virtual ~BaseUnit() {}
	virtual void moveTo(int dx, int dy) {
		cout << "Base Unit moveTo (" << dx << ", " << dy << ")" << endl;
		p.x += dx, p.y+= dy;
	}
	Position getPosition() {return p;}
};

class Player : public BaseUnit {
public:
	Player(int px, int py) : BaseUnit(px, py) {}
	void moveTo(int dx, int dy) {
		cout << "Player moveTo (" << dx << ", " << dy << ")" << endl;
		p.x += dx, p.y+= dy;
	}
};

class Monster : public BaseUnit {
public:
	Monster(int px, int py) : BaseUnit(px, py) {}
	void moveTo(int dx, int dy) {
		cout << "Monster moveTo (" << dx << ", " << dy << ")" << endl;
		p.x += dx, p.y+= dy;
	}
};

int main(int argc, char const *argv[])
{
	BaseUnit *basePtr;
	Player p1(20, 30);
	Monster m1(40, 20);
	
	basePtr = &p1;
	basePtr->moveTo(20, 30);
	cout << "p1's position: " << basePtr->getPosition() << endl;

	basePtr = &m1;
	basePtr->moveTo(30, 20);
	cout << "m1's position: " << basePtr->getPosition() << endl;

	return 0;
}
```

