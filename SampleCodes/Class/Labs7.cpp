#include <iostream>


using namespace std;

struct Person
{
	string name;
	Person* child;
};

class World
{
	Person* person;
public:
	World(string name)
	{
		person = new Person{ name, NULL };
	}

	Person* find(Person* person, string name)
	{
		if (person == NULL) return NULL;
		if (person->name == name) return person;
		else
		{
			return NULL;
		}
	}

	void add_Person(string parent, string child)
	{
		
		if (find(person, parent) == NULL)
		{
			cout << parent << " 을(를) 찾지 못했습니다" << endl;
			return;
		}
		else
		{
			person->child = new Person{ child, NULL };
			person = person->child;
			cout << parent << " 의 자식은 " << child << " 입니다" << endl;
		}
	}
};

int main() {

	World w("홍길동");
	w.add_Person("홍길동", "a");
	w.add_Person("a", "b");
	w.add_Person("c", "d");

	return 0;
}




