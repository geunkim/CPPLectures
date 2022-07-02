#include <iostream>

using namespace std;

int threeMax(int a, int b, int c){
	int max = a;
	if(b > max) max = b;
	if(c > max) max = c;

	return max;  

}

int main(int argc, char const *argv[])
{
	cout << threeMax(10 ,20, 30) << endl;
	cout << threeMax(100, 50, 10) << endl;
	cout << threeMax(10, 50, 40) << endl;
	return 0;
}