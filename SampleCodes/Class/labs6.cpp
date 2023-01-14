#include <iostream>

using namespace std;

class Man;

class MantoMan {
public:
	Man fight(Man a, Man b);
	void training(Man& a, Man& b);
};

class Man {
	string name;
	int power;
public:
	Man(){};
	Man(string name, int power) 
	{ 
		this->name = name;
		this->power = power; 
	}
	int getPower() { return power; }
	string getName() { return name; }
	void setPower(int power) { this->power = power; }
	friend MantoMan; // MantoMan 클래스의 모든 멤버 함수를 프렌드 선언
};

Man MantoMan::fight(Man a, Man b) {
	if (a.power > b.power) return a;
	else return b;
}

void MantoMan::training(Man& a, Man& b) {
	a.setPower(1000);
	b.setPower(1010);
}


int main(int argc, const char* argv[]) {

	Man Jinho("jinho", 1000);
	Man Donghun("donghun", 100);
	Man winer;
	MantoMan vs;

	winer = vs.fight(Jinho, Donghun);
	cout << winer.getName() << " has win" << endl;

	vs.training(Jinho, Donghun);
	cout << endl << "Re Match" << endl << endl;

	winer = vs.fight(Jinho, Donghun);
	cout << winer.getName() << " has win" << endl;


	return 0;
}