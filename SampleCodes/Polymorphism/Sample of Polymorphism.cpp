#include <iostream>
#include <string>

using namespace std;

// 20193496 ���뼺
// ������, �߻� Ŭ������ �̿��� ���� �ڵ� 

/* ������ ���� �ڵ带 ���� �ڽİ�ü�� �̿��Ͽ� �߻� �θ� Ŭ������  ������� �� ����Լ��� 
    �������� ����� �� ������ Ȯ�������� �θ�Ŭ������ ���������Լ��� ����Ϸ��ϴ� 
    ������ ���� Ȯ�� �� �� �־���.*/

class ghost {
public:
    int x = 5, y = 3;

    virtual void hide() {
        cout << "����" << endl;
    }
    virtual void move() = 0;
};

class monster : public ghost {
public:
    int x = 7, y = 8;

    void hide() {
        cout << "ū ��ü�� ����" << endl;
    }
    void move() {
        cout << "������" << endl;
    }
};

class zombie : public ghost {
public:
    int x = 2, y = 2;

    void hide() {
        cout << "�̻��� ��ü�� ����" << endl;
    }
    void move() {
        cout << "������ ������" << endl;
    }
};

int main()
{
    // ghost Ghost;  -> ��ü ���� �Ұ�

    monster Monster;

    Monster.ghost::hide();
    // Monster.ghost::move(); -> ���������δ� ������ �������� ������ ���� "������ �� ����" ��� ������ ��
    Monster.hide();
    Monster.move();
    cout << Monster.ghost::x << Monster.y << endl;

    zombie Zombie;

    Zombie.ghost::hide();
    // Zombie.ghost::move(); -> ���������δ� ������ �������� ������ ���� "������ �� ����" ��� ������ ��
    Zombie.hide();
    Zombie.move();
    cout << Zombie.x << Zombie.ghost::y << endl;

    return 0;
}