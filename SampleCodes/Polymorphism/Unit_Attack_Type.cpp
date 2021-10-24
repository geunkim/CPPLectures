#include <iostream>
#include <string>

using namespace std;

class Unit_Attack {
public:
	Unit_Attack() { cout << "Unit_Attack_Type" << endl; }
	virtual ~Unit_Attack() { cout << "Type_Delete" << endl; }

	virtual void attackType() = 0; // ĳ������ ����Ÿ���� �����Ͻʽÿ�
};

class Barbarian : public Unit_Attack {
public:
	Barbarian() { cout << "[Barbarian]" << endl; }
	~Barbarian() { cout << "class_delete" << endl; }
	void attackType() { cout << "�ٰŸ�\n" << endl; }
};

class Archer : public Unit_Attack {
public:
	Archer() { cout << "[Archer]" << endl; }
	~Archer() { cout << "class_delete" << endl; }

	void attackType() { cout << "���Ÿ�\n" << endl; }
};

class Wizard : public Unit_Attack {
public:
	Wizard() { cout << "[Wizard]" << endl; }
	~Wizard() { cout << "class_delete" << endl; }

	void attackType() { cout << "����\n" << endl; }
};

int main() {
	Barbarian b;
	b.attackType();

	Archer a;
	a.attackType();

	Wizard w;
	w.attackType();

	return 0;
}