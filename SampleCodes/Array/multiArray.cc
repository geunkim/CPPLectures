/*

*/
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int data[][4] = {{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}
				   };

	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) 
			cout << data[i][j] <<" ";
		cout << endl;
	}

	return 0;
}