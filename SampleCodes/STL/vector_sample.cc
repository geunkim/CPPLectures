#include <iostream>
#include <vector>
using namespace std;


//

void assignTest() {
    vector <int> v1, v2, v3, v4;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    cout << "the value of elements of v1 " << endl;
    for(auto& e : v1) cout << e << ",";
    cout << endl;
    cout << "the capacity of v1: " << v1.capacity() << endl;
    cout << "the value of elements of v2 after assign" << endl;
    v2.assign(v1.begin(), v1.end());

    cout << "the size of v2: "<< v2.size() << endl;
    cout << "the capacity of v2: " << v2.capacity() << endl;

    for(auto& e : v1) cout << e << ",";
    cout << endl;

    v3.assign(10 , 3);
    cout << "the result of v3.assign(7 , 3): " << endl;
    cout << "the size of v3: " << v3.size() << endl; 
    cout << "the capacity of v3: " << v3.capacity() << endl; 

    for(auto& e : v3) cout << e << ", ";
    cout << endl;

    v4.assign({5, 6, 7, 8});
    cout << "the result of v4.assign({5, 6, 7}): " << endl;
    cout << "the size of v4: " << v4.size() << endl; 
    cout << "the capacity of v4: " << v4.capacity() << endl;   

    for(auto& e : v4) cout << e << ", ";
    cout << endl;   

}

void itrTest() {
    vector <int> v1;
    vector <int>::iterator v1_itr;
    vector <int>::const_iterator v1_citer;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    v1_itr = v1.begin();
    cout << "Access the data through the iterator" << endl;
    for( ; v1_itr != v1.end(); v1_itr++) cout << *v1_itr << ", ";
    cout << endl;
    
    v1_itr = v1.begin();
    cout << "Add 100 to every element in the vector through the iterator" << endl;
    for( ; v1_itr != v1.end(); v1_itr++) *v1_itr += 100;

    cout << "Accee the element with range-for loop in the vector" << endl;
    for(auto& e : v1) cout << e << ", ";
    cout << endl; 

     cout << "Accee the element with for loop in the vector" << endl;
    for(int i = 0; i < v1.size() ; i++) cout << v1[i] << ", ";
    cout << endl;
}

void sizeTest() {
    vector <int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout << "size of vector: " << v1.size() << endl;
}

void capacityTest() {
    vector <int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout << "capacity of vector: " << v1.capacity() << endl;
}

void atTest() {
    vector <int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30); 

    int& e = v1.at(1);

    cout << e << endl;
    e = 60;
    cout << v1[1] << endl;

}

void backTest() 
{

}

void beginTest()
{

}

void endTest() 
{

}

void clearTest() 
{
    
}

int main(int argc, char const *argv[])
{
    itrTest();
    return 0;
}

