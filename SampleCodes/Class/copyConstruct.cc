/*
	File name: copyConstruct.cc
	Author: Geun-Hyung Kim
*/

#include <iostream>
using namespace std;

class Person {
	string name; 
   	int age;      
public:
   	Person(string name, int age) { //인자가 있는 생성자
    	this->name = name;
      	this->age = age;
   	}
   	Person(const Person &ref) {    //복사 생성자  		
    	name = ref.name;
      	age = ref.age;
   	}
   	void show() {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 인자가 있는 생성자 호출
   Person kim {"Chul-soo Kim", 30};   // 인자가 있는 생성자 호출 
   Person lee = {"Soon-sin Lee", 40}; // 인자가 있는 생성자 호출 
   
   lee.show();
   Person man = hong; // 북사 생성자 호출 (man 객체는 hong 객체의 내용을 복사하여 생성) 
   man.show();

   return 0;
}