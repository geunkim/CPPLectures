/*
	File name: strstrFunction.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[] = "Use your brain and heart";
    char target[] = "brain";
    char *p = strstr(str, target);
    
    if (p)
        cout << "\"" << target << "\" is present in \"" << str << "\" at position " << p-str << endl;
    else
        cout << "\"" << target << "\" is not present in \"" << str << "\"" << endl;

    cout << "\"" << target << "\" 다음의 문장: " << p << endl;

    return 0;
}

