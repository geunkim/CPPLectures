#include <iostream>

using namespace std;
const int SIZE = 10;

class MyArray
{
private:
	int buf[SIZE];
public:
	MyArray() {
		for (int i = 0; i < SIZE; i++)
			buf[i] = 0;
	}
int& operator[] (int i);
const int& operator[] (int i) const;
};

int& MyArray::operator[](int i) {
	if(i >= SIZE) {
		cout << "bad index";
		return buf[0];
	}
	return buf[i];
}

const int& MyArray::operator[] (int i) const{
	if(i >= SIZE) {
		cout << "bad index";
		return buf[0];
	}
	return buf[i];

}

int main(int argc, char const *argv[])
{
	MyArray A;

	A[3] = 9;
	cout << "A[3]: " << A[3] << endl;
	cout << "A[4]: " << A[4] << endl;	
	return 0;
}