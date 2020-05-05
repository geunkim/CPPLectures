/* 
	File name: strcatFunction.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char str1[255] = "first string";
	char str2[255] = " second string";
	char str3[] = " third string";
	char *ptr;


	ptr = strcat(str1, str2);
	if(ptr == &str1[0])
		cout << "ptr에 저장된 주소와 str1 시작주소는 같음" << endl;
	else
		cout << "ptr에 저장된 주소와 str1 시작주소는 다름" << endl;

	cout << "1. " << str1 << endl;
	strncat(str1, str3, 6);
	cout << "2. " << str1 << endl;
	strncat(str2, str3, 20);
	cout << "3. " << str2 << endl;

	return 0;
}


