#include <exception>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())
        throw invalid_argument("MyFunc argument too large.");
}

int main()
{
    try
    {
        MyFunc(256); //cause an exception to throw
    }

    catch (exception& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}


