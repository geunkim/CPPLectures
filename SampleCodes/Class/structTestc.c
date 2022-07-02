#include <stdio.h>
#include <string.h>

struct Student{
	char name[20];
	char id[10];
	int age;
	int department;
};

typedef struct Student Student;

int main(int argc, char const *argv[])
{

	Student s1;

	strcpy(s1.name, "이순신");
	strcpy(s1.id, "20221234");
	s1.age = 20;
	s1.department = 21;

	printf("%s\n", s1.name);
	printf("%s\n", s1.id);
	printf("%d\n", s1.age);
	printf("%d\n", s1.department);

	return 0;
}