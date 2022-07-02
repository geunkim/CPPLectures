//#include <ctime>
//#include <stdio.h>
//#include <iostream>

//using namespace std;

int main(int argc, char const *argv[])
{
	time_t result = time(NULL);
 	printf("%s",std::ctime(&result));

	return 0;
}