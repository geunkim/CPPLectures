클래스를 설명하기 위해
weapon 클래스와 creature 클래스를 선언합니다.

그리고 객체를 설명하기 위해
무기 객체 2가지와
각각의 무기를 사용하는 크리쳐 객체 2마리를 생성했습니다.

메인 함수에서 첫 번째로 등장하는 fight 함수는 아까 전 생성시킨 크리쳐 객체 2마리를 서로 싸우도록 만든 함수이고,
두번째와 세번째는 상대방의 객체의 멤버 변수에 함부로 접근하는 예시를 만들었습니다.
일부로 클래스의 멤버 변수를 public으로 해 놓았는데,
작성 의도는 public으로 접근 제한이 없는 변수는 타인에 의해 악의적으로 수정당할 수 있음을 알리기 위해서입니다.

```
#include <iostream>
using namespace std;

//클래스 선언
class weapon {
public: // << 이 접근 지정자는 외부에 의해 수정당할 수 있습니다.
    // 정보 부분
    string name = "빈 이름";
    string lore = "빈 설명";
    // 스펙 부분
    int damage = 0;
};
class creature {
public:
    // 정보 부분
    string name = "이름";
    // 스펙 부분
    int health = 100;
    int atk = 5;
    weapon equipment;
    int cash = 10;
    void attack(creature& target) {
    //목표물의 체력을 자신의 기본 공격력과 무기의 데미지만큼 깎습니다.
    target.health -= atk + equipment.damage;
    cout << name << " 는 " << target.name << " 에게 " << atk + equipment.damage << " 만큼의 데미지를 주었습니다. ( 남은 체력 " << target.health << ")" << endl;
    }
    void changeEquipment(weapon &changeTo) {
        equipment = changeTo;
        cout << name << "은 무기를" << changeTo.name << "으로 바꿨다!" << endl;
    }
};

// 무기 선언
weapon knife = { knife.name = "칼", knife.lore = "날카롭게 갈은 칼.", knife.damage = 30 };
weapon hammer = { hammer.name = "해머", hammer.lore = "상당히 무겁다.", hammer.damage = 20 };

// 캐릭터 선언
creature zebasi = { "제바시", 100 , 10 , knife };
creature bardur = { "발두르", 100 , 10 , hammer };

void fight(creature& target1, creature& target2) {
    cout << target1.name << "는" << target2.name << "에게 싸움을 걸어 왔다!" << endl;
    string winner;
    while ((target1.health > 0) && (target2.health > 0))
    {
        target1.attack(target2);
        if (target2.health <= 0) winner = target1.name;
        target2.attack(target1);
        if (target1.health <= 0) winner = target2.name;
    }
    cout << winner << "의 승리!" << endl;
}

int main()
{
    fight(zebasi, bardur);
    // zebasi가 bardur를 잡습니다.
    bardur.cash += zebasi.cash;
    zebasi.cash = 0;
    // bardur가 복수로 zebasi의 cash를 가져가는 코드를 작성했습니다.
    // 접근 제한자가 public으로 되어 있어 아무나 맴버 변수의 값을 수정할 수 있습니다.
    // 접근 제한자가 private인 경우 해당 클래스 외부에서 수정할 수 없습니다.
}
```
