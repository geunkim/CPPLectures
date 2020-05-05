/*
	File name: strchrFunction.cc
	Authors: Geun-Hyung Kim
*/

#include <iostream>
#include <cstring> 

using namespace std;

int main(int argc, char const *argv[])
{
	
	char str[] = "Programming is easy.";
    char ch = 'r';
    char *ptr = strchr(str, ch);
    
    if (ptr)
        cout << ch << " is present \"" << str << "\"" << endl;
    else
        cout << ch << " is not present \"" << str << "\"" << endl;

    cout << "\'" <<  ch <<"\' 다음의 내용: " << ptr << endl;

	return 0;
}

