#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2, v3;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 = ";
    for (auto& v : v1){
        cout << v << " ";
    }
    cout << endl;

    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (auto& v : v2){
        cout << v << " ";
    }
    cout << endl;

    v3.assign(7, 4);
    cout << "v3 = ";
    for (auto& v : v3){
        cout << v << " ";
    }
    cout << endl;

    v3.assign({ 5, 6, 7 });
    for (auto& v : v3){
        cout << v << " ";
    }
    cout << endl;


    int &i = v1.at(0);
  
    cout << "v1 첫 번째 원소의 값:  " << i << endl; 

    if(v1 == v2) cout << "v1과 v2는 같다." << endl;
    else cout << "v1과 v2는 다르다" << endl;
  
    i = 80;
    const int &j = v1.at(0);
  
    cout << "값을 변경 후 v1 첫 번째 원소의 값:  " << j << endl; 

    if(v1 == v2) cout << "v1과 v2는 같다." << endl;
    else cout << "v1과 v2는 다르다" << endl;
}