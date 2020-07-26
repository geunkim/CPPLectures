/*
	File name: fileRepeateIn.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream fin("text.txt");
	char buf[255];
	int i = 1;
	if(!fin) {
		cout << "[Error] text.txt file open" << endl;
		return 0;
	}

	while(true){
		fin.getline(buf, 255);
		if(fin.eof()) break;
		cout << i << ": " << (buf) << endl;	
		i++;
	}
	fin.close();

	return 0;
}


