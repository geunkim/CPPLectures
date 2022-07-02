#include <iostream>
using namespace std;

//private, public 
struct Student
{
public:   // 접근(권한) 지정자 
	int id; // 학번.   --> 멤버(변수)
	char name[20]; // 이름 
	char major[30]; // 학과
};

class Person  // 멤버변수 + 멤버함수 
{
	int height; 
	int age;
	float weight;
	void BMI():
public:
	void setAge(int age) {
		if (age > 1) this->age = age;
		else this->age = 0; }
	void setHeight(int height) {this->height = height;}
	void setWeight(float weight) {this->weight = weight;}
	void printAll();
private:
	void BMI();
};

void Person::printAll() {
	cout << height << ", " << age << ", " << weight << endl;
}

int main(int argc, char const *argv[])
{
	Student s1;
	Person p1;   // 객체 (object), 인스턴스 
	s1.id = 20210001;
	strcpy(s1.name, "홍길동");
	strcpy(s1.major,"게임공학");

	p1.setAge(-25);
	p1.setWeight(70.5);
	p1.setHeight(175);

	cout << s1.id << ", " << s1.name << ", " << s1.major << endl;

	p1.printAll();

	return 0;
}