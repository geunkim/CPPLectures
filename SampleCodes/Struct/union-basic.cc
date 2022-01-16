#include <iostream>

using namespace std;


union Student {
	char grade;
	int id;
	short score;
};

int main(int argc, char const *argv[])
{
	Student peter;

	cout << "할당된 메모리 크기: " << sizeof(peter) << endl;

	peter.grade = 'A';

	cout << "grade: " << peter.grade << endl;
	cout << "grade(code 값): " << (int) peter.grade << endl;

	peter.score = 512 + 66;
	cout << "score: " << peter.score << endl;

	cout << "grade: "  << peter.grade << endl;

	return 0;
}