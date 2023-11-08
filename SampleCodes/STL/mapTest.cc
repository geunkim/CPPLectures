#include <iostream>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
    map<string, string> strmap;
   
    strmap.insert(make_pair("1", "C++"));
    strmap.insert(make_pair("4", "Data Strucgture"));
    strmap.insert(make_pair("5", "C#"));
    strmap.insert(make_pair("2","Java"));

    for(auto itr = strmap.begin(); itr != strmap.end(); itr++)
        cout << "key: " << itr->first << ", " << "value: " << itr->second << endl;
    
    return 0;
}


