/*
	File name: dateClass.cc
	Author: Geun-Hyung Kim
*/

class Date{
	int year;
	int month;
	int day;
	Date()
	Date(int y, int m, int d);
	~Date();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear();
	int getMonth();
	int getDay();
	void printDate();
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}