#include <iostream>
#include <string>
using namespace std;

struct Student{
	char name[20];
	char id[10];
	int age;
	int department;
};

int main(int argc, char const *argv[])
{
	Student s1;

	strcpy(s1.name, "이순신");
	strcpy(s1.id, "20221234");
	s1.age = 20;
	s1.department = 21;

	cout << s1.name << endl;
	cout << s1.id << endl;
	cout << s1.age << endl;
	cout << s1.department << endl;

	return 0;
}
