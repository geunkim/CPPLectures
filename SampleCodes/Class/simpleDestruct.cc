/*
	FileName: simpleDestruct.cc
	Author: Geun-Hyung Kim
*/

# include <iostream>
using namespace std;

class Date {
	int month;
	int day;
	int year;
public:
	Date(int y, int m, int d);
	~Date();
	void printDate(){
		cout << year << "-" << month << "-" << day << endl;
	}
};

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Date::~Date(){
	cout << "Destructor " << endl;
}

int main(int argc, char const *argv[])
{
	Date today(2020, 8, 31);
	today.printDate();
	return 0;
}

