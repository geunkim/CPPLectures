/*
	File name: strlenFunction.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char str1[] = "This a string";
    char str2[] = "This is another string";
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    cout << "Length of str1 = " << len1 << endl;
    cout << "Length of str2 = " << len2 << endl;
    if (len1 > len2)
        cout << "str1 is longer than str2" << endl;
    else if (len1 < len2)
        cout << "str2 is longer than str1" << endl;
    else
        cout << "str1 and str2 are of equal length" << endl;

	return 0;
}

