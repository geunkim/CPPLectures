/*
	File name: fileIn.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char const *argv[])
{
	ifstream fin("text.txt");
	char buf[255];
	if(!fin) {
		cout << "[Error] text.txt file open" << endl;
		return 0;
	}

	fin >> buf;
	cout <<"1: " << (buf) << endl;
	fin >> buf;
	cout <<"2: " << (buf) << endl;

	fin.close();
	return 0;
}