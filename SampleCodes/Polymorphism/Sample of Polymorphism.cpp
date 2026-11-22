#include <iostream>
#include <string>

using namespace std;

// 20193496 나용성
// 다형성, 추상 클래스를 이용한 샘플 코드 

/* 간단한 예제 코드를 통해 자식객체를 이용하여 추상 부모 클래스의  멤버변수 및 멤버함수를 
    문제없이 출력할 수 있음을 확인했으며 부모클래스의 순수가상함수를 출력하려하니 
    에러가 남을 확인 할 수 있었다.*/

class ghost {
public:
    int x = 5, y = 3;

    virtual void hide() {
        cout << "숨음" << endl;
    }
    virtual void move() = 0;
};

class monster : public ghost {
public:
    int x = 7, y = 8;

    void hide() {
        cout << "큰 물체가 숨음" << endl;
    }
    void move() {
        cout << "움직임" << endl;
    }
};

class zombie : public ghost {
public:
    int x = 2, y = 2;

    void hide() {
        cout << "이상한 물체가 숨음" << endl;
    }
    void move() {
        cout << "느리게 움직임" << endl;
    }
};

int main()
{
    // ghost Ghost;  -> 객체 생성 불가

    monster Monster;

    Monster.ghost::hide();
    // Monster.ghost::move(); -> 문법적으로는 오류가 없었으나 컴파일 도중 "참조할 수 없다" 라는 오류가 뜸
    Monster.hide();
    Monster.move();
    cout << Monster.ghost::x << Monster.y << endl;

    zombie Zombie;

    Zombie.ghost::hide();
    // Zombie.ghost::move(); -> 문법적으로는 오류가 없었으나 컴파일 도중 "참조할 수 없다" 라는 오류가 뜸
    Zombie.hide();
    Zombie.move();
    cout << Zombie.x << Zombie.ghost::y << endl;

    return 0;
}