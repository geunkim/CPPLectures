/*
	File name: fileOut.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ofstream fout("text.txt");	

	if(!fout) {
		cout << "[Error] file open" << endl;
	}
	
	fout << "Hello World!" << endl;
	fout << "This a sample file." << endl;
	fout.close();
	return 0;
}