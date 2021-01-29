#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ofstream myfile;
	myfile.open("example.txt", ios::app);
	if(myfile.is_open()) {
		myfile << "Third line" << endl;
		myfile << "Fourth line" << endl;
		myfile.close();	
	}
	else cout << "Unable to open file" << endl;

	return 0;
}
