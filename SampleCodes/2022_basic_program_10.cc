#include <iostream>
using namespace std;

template <typename T>
T func(T *p, int n) {
  T sum = 0;
  for(int i = 0; i < n; i += 2) sum += *(p+i);
  return sum;
}


int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	cout <<    func(a, 10)    << endl;
	return 0;
}



