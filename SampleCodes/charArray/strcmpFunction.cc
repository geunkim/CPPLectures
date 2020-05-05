/* 
	File name: strcmpFunction.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char str1[] = "abcdef";
	char str2[] = "abcdefg";
	char str3[] = "abcdefgh";

	int result = strcmp(str1, str2); // str1 은 str2 보다 사전식으로 앞에 있음 
	cout << "result of strcmp(str1, str2): " << result << endl; 
	result = strcmp(str2, str3);     // str2 는 str3 보다 사전식으로 앞에 있음
	cout << "result of strcmp(str2, str3): " << result << endl;
	result = strcmp(str3, str1);     // str3는 str1 보다 사전식으로 뒤어 있음
	cout << "result of strcmp(str3, str1): " << result << endl;
	result = strncmp(str1, str3, 6); // str1과 str3이 6문자를 비교하면 같음 
	cout << "result of strcmp(str1, str6, 6): " << result << endl;	

	return 0;
}

