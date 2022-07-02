#include <iostream>
using namespace std;

class Obj {
	int num;
public:
	Obj(int num) {    // 생성자
		this-> num = num;
		cout << num << ":  Obj Constructor" << endl;
	}
	~Obj(){   // 소멸자
		cout << num << ":  Obj Destructor" << endl;
	}

};

int main(int argc, char const *argv[])
{
	cout << "main start" << endl;
	Obj a(1);
	{
		Obj b(2);
	}
	Obj c(3);
	cout << "main end" << endl;
	
	return 0;
}

