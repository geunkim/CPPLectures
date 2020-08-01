/*
	File name: multiConstruct.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
using namespace std;

class Person{
private:
	string name;
	int age;
public:
	Person(){}				 // 기본 생성자
	Person(string n) : name(n){}		 // 생성자 1
	Person(string n, int a) : name(n), age(a) {} // 생성자 2
	void setName(string n) { name = n;}
	void setAge(int a) { age = a;}
	void show() {
		cout << name << ", " << age << endl;
	}
};

int main(int argc, char const *argv[])
{
	Person dad;	// 기본 생성자 호출
	Person mom("Young-Hee Park");  // 생성자 1 호출
	Person son("Gil-Dong Lee", 20); // 생성자 2 호출
	dad.setName("Chul-soo Lee"), dad.setAge(52);
	mom.setAge(50);
	dad.show(), mom.show(), son.show();
	return 0;
}