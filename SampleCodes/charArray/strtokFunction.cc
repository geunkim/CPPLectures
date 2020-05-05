/* 
	File name: strtokFunction.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char buf[255] = "This, a sample; string. \\string-with delimeter.";
	char del[] = "\\,;-. ";
	char *ptr;
	int i = 1;

	ptr = strtok(buf, del);
	
	while(ptr != NULL) {
		cout << i++ <<". " << ptr << endl;
		ptr = strtok(NULL, del);
	}

	return 0;
}


