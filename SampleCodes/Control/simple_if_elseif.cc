
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int score = 74;

	if(score >= 90)
	{
		cout << "A" << endl;
	}
	else if (score >= 80)  // if (score >= 80 && score < 90)
	{
		cout << "B" << endl;
	}
	else if (score >= 70) // if (score >= 70 && score < 80)
	{
		cout << "C" << endl;
	}
	else if (score >= 60) //if (score >= 60 && score < 70) 
	{
		cout << "D" << endl;
	}
	else 				   // if (score < 60)
	{
		cout << "F" << endl;
	}

	cout << "After if-else if-statement" << endl;

	return 0;
}