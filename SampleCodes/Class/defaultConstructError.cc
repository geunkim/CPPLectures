/*
	File name: defaultConstructError.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

class Person{
private:
	string name;
	int age;
public:
	Person(string n, int a) : name(n), age(a) {}
	void setName(string n) { name = n;}
	void setAge(int a) { age = a;}
	void show() {
		cout << name << ", " << age << endl;
	}
};

int main(int argc, char const *argv[])
{
	Person father;  // [컴파일 에러 발생] 컴파일러가 기본 생성자를 생성하지 않음 
	Person son("Gil-Dong Hong", 30); //생성자 호출 
	son.show();
	return 0;
}