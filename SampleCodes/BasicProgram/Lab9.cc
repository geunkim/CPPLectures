/*

	File: Lab9.cc
	Author: Geun-Hyung Kim

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	unsigned short value = 0xffff;
	unsigned short mask1 = 0x00ff;
	unsigned char mask2 = 0x77;
	unsigned char mask3 = (unsigned char)01010101;
	unsigned char mask4 = (unsigned char)10101010;


	cout << "[출력 1]: " << value << endl;
	cout << "[출력 2]: " << mask1 << endl;
	cout << "[출력 3]: " << (int)mask2 << endl;
	cout << "[출력 4]: " << (int)mask3 << endl;
	cout << "[출력 5]: " << (int)mask4 << endl;		

	cout << "[출력 - 1]: " << (value & mask1) << endl;
	cout << "[출력 - 2]: " << (value & mask2) << endl;
	cout << "[출력 - 3]: " << (mask3 & mask4) << endl;
	cout << "[출력 - 4]: " << (mask3 | mask4) << endl; 
	cout << "[출력 - 5]: " << (mask3 ^ mask4) << endl; 
	cout << "[출력 - 6]: " << (mask3 | !mask4) << endl; 

	return 0;
}
