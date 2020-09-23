#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	try{
  		throw 1.1;
  	}
  	catch(int e) {
  		cout <<  e << endl;
  	}
	return 0;
}



