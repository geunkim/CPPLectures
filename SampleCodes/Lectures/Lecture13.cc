#include <iostream>
using namespace std;

class Date{
	int year;
	int month;
	int day;
public:
	// Date(); // 디폴트 생성자(기본 생성자) constructor
	Date(int y = 2021, int m = 1, int d =1) : year(y), month(m), day(d) { cout << "생성자 2" << endl;} 
	~Date(); // 소멸자 destructor 
	void printAll() {cout << year << ", " << month << ", "<< day << endl;}
};



int main(int argc, char const *argv[])
{
	Date myDate;
	Date yourDate(2021, 5, 25), yesterDay(2021, 5, 24);
	myDate.printAll();
	yourDate.printAll();
	yesterDay.printAll();
	

	return 0;
}

// Date::Date() {
// 	cout << "생성자 호출" << endl;
// }

Date::~Date() {
	cout << "소멸자 호출" << endl;
}

