/*
	File name: deepCopy.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
	int age;
	string* name;
public:
	Student(int a = 0, string n = "Anonymous") : age(a), name(new string(n)) {}
	Student(const Student& s);
	~Student();
	void printContent();
};

Student::Student(const Student& s){
	age = s.age;
	name = new string(s.name->c_str());
}

Student::~Student() {
	delete name;   // 왜 필요한지 고민하기 
}

void Student::printContent() {
	cout << "name: " << *name;
	cout << ", age: " << age << endl;
}

int main(int argc, char const *argv[])
{
	Student any;
	{
		Student me(any);
		me.printContent();
	}
	any.printContent();
	
	return 0;
}