/*
	File name: explicitCopyConstruct.cc
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
   	explicit Person(const Person &ref) {    //복사 생성자  		
    	name = ref.name;
      	age = ref.age;
   	}
   	void show() {
      cout << name << ", " << age << endl;
   }
}; 

int main(int argc, char const* argv[]) {
   Person hong("Gil-Dong Hong", 28);  // 인자가 있는 생성자 호출
   
   //Person lee = hong; // 에러가 발생
   Person lee(hong); // 복사 생성자를 통한 lee 객체 생성
   lee.show();

   return 0;
}