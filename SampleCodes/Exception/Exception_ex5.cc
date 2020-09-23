#include <iostream>
#include <exception>
using namespace std;

double division(int a, int b) {


}

int main () {
   int x, y;
   cin >> x >> y;
   double z = 0;
   
   try {
      z = division(x, y);
      cout << z << endl;
   }catch (const char* e) {
      cout << e << endl;
   }catch(...)
   {
    cout << "exception" <<endl;
   }
   return 0;
}


