#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception {
public:
	const char* what() const throw() {
		return "C++ Exception";
	}
};


int main(int argc, char const *argv[])
{
	int i;
	cout << "Enter integer number: ";
	cin >> i;
	try{
		if(i == 0)
			throw MyException();
		else 
			throw invalid_argument("MyFunc argument too large.");

	}catch(MyException& e) {
		cout << "MyException caught" << endl;
		cout << e.what() << endl;
	}catch(exception& e){
		cout << "exception caught" << endl;
		cout << e.what() << endl;
	}
	return 0;
}