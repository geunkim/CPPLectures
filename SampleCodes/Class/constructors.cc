#include <iostream>
using namespace std;


class Book{
	string name;
public:
	Book(string n) : name(n) { cout << "생성자" << endl;}
	~Book() { cout << "소멸자" << endl;}
	string getName() { return name;}
	void setName(string n) { name = n;}
};

void printBookName(Book b){
	cout << b.getName() << endl;
}

int main(int argc, char const *argv[])
{
	Book b("C++ Programming");
	Book c = b;
	c.setName("Data Structure");

	printBookName(b);

	return 0;
}