#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string line;

	ifstream myfile("file1.txt");
	if(myfile.is_open()) {

		while(getline(myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();

	}
	else cout << "Unable to open file" << endl;

	return 0;
}