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
	peter.id = 0;
	cout << "할당된 메모리 크기: " << sizeof(peter) << endl;

	peter.grade = 'A';

	cout << "grade: " << peter.grade << endl;
	cout << "grade(code 값): " << (int) peter.grade << endl;

	cout << "id: " << peter.id << endl;
	cout << "score: " << peter.score << endl;
	cout << "grade: " << peter.grade << endl;


	peter.score = 512 + 66;

	cout << "id: " << peter.id << endl;
	cout << "score: " << peter.score << endl;
	cout << "grade: " << peter.grade << endl;

	peter.id = 65536 + 1024 + 67;

	cout << "id: " << peter.id << endl;
	cout << "score: " << peter.score << endl;
	cout << "grade: " << peter.grade << endl;

	return 0;
}