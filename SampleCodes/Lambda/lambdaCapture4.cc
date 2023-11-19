#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int total = 10;
    int factor = 20;

    auto lambdatest = [] mutable{ total += 30; factor += 10; cout << factor << endl; };

    lambdatest();

    cout << "total: " << total << endl;
    cout << "factor: " << factor << endl;

    return 0;
}
