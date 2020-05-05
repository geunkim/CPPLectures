/* 
	File name: strcpyFunction.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char buf[255];
	char *ptr;

	ptr = strcpy(buf, "Hello World!"); // "Hello World1" 을 buf로 복사 
	if(ptr == &buf[0]) 
		cout << "ptr의 주소와 buf 배열의 시작주소는 같음" << endl;
	else
		cout << "ptr의 주소와 buf 배열의 시작 주소는 다름" << endl;
	cout << "1. " << buf << endl;
	strncpy(buf, "Good Morning", 10);
	cout << "2. " << buf << endl;
	strncpy(buf, "Good", 10);
	cout << "3. " << buf << endl;

	return 0;
}

