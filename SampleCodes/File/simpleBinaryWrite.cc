#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int data[] = {1, 2, 3, 4, 5, 6};

	ofstream myfile("exbinary.bin", ios::binary);
	if(myfile.is_open()) {
		myfile.write((char*)data, 6*sizeof(int));
		myfile.close();
	}

	else cout << "Unable to open file" << endl;
	return 0;
}