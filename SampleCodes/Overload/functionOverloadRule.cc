#include <iostream>
using namespace std;


// default parameters 
int sum(int a, int b) {
	return a + b;
}

int sum(int a, int b, int c = 100){
	return a + b + c;
}

// 
class Test { 
   static void func(int i) {} 
   void func(int i) {}    
}; 

int main(int argc, char const *argv[])
{
	int result = sum(10, 20, 30);  // 세개의 파러미터
	//result = sum(10, 20);          // 컴파일 에러를 발생시키는 코드 
	cout << "result: " << result << endl;
	return 0;
}