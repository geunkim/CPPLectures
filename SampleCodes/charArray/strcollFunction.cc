/*
	File name: strcollFunction.cc
	Author: Geun-Hyung Kim
*/
#include <iostream>
#include <cstring>
#include <clocale> // setlocale 함수 때문에 존재

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(LC_COLLATE, "ko_KR.UTF-8");

	char str1[] = "감자", str2[] = "고구마";

	cout << "In korean locale: ";

	if(strcoll(str1, str2) < 0)
		cout << "\""<< str1 << "\" before  \"" << str2 << "\"" << endl;
	else
		cout << "\""<< str2 << "\" before  \"" << str1 << "\"" << endl;

	cout << "In lexicographical comparison: "; 

	if(strcmp(str1, str2) < 0)
		cout << "\""<< str1 << "\" before  \"" << str2 << "\"" << endl;
	else
		cout << "\""<< str2 << "\" before  \"" << str1 << "\"" << endl;
	
	return 0;
}
