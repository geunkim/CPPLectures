# 복사 대입 연산자 오버로드 

북사 대입 연산자를 통해 이미 생성된 객체 간 대입 연산자를 수행하게 된다. 
객체에 대해서 대입 연산자를 수행하는 경우 구조체의 대입 연산자와 같이 대입 연산자의 오른쪽 객체의 멤버 변수의 값을 왼쪽 객체의 멤버 변수에 복사한다.  
C++ 언어는 기본적으로 멤버 변수의 값을 복사하는 대입 연산자를 제공한다. 

다음 코드는 정수형 멤버 변수 x, y, z를 갖는 클래스 Obj를 정의하고 해당 객체를 생성하고 대입 연산을 통해 
객체의 멤버 변수 각각이 해당 멤버 변수의 저장 장소에 복사됨을 보인다.

```c++
#include <iostream>
using namespace std;

class Obj {
	int x, y, z;
public:
	Obj(){}
	Obj(int a, int b, int c) : x(a), y(b), z(c) {}
	friend ostream& operator << (ostream& os, const Obj& o) {
		os << "(" << o.x << ", " << o.y << ", " << o.z << ")";
		return os;
	}
	void printAddr(){
		cout << "x_addr(" << &x << "), ";
		cout << "y addr(" << &y << "), ";
		cout << "z addr(" << &z << ")" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Obj x(1, 2, 3), z(10, 20, 30);

	cout << "x: " << x << endl;
	cout << "객체 x의 각 멤버 변수의 주소: ";
	x.printAddr();
	cout << "z: " << z << endl;
	cout << "객체 z의 각 멤버 변수의 주소: ";
	z.printAddr();

	z = x;   // 대입 연산 수행 
	cout << endl;
    cout <<"대입 연산 후 z의 값: ";
	cout << "z: " << z << endl;
	cout << "대입 연산 후 객체 z의 각 멤버 변수의 주소: ";
	z.printAddr();

	return 0;
}
```
실행 결과는 다음과 같다. 

```bash
x: (1, 2, 3)
객체 x의 각 멤버 변수의 주소: x_addr(0x7ffee3b3fa30), y addr(0x7ffee3b3fa34), z addr(0x7ffee3b3fa38)
z: (10, 20, 30)
객체 z의 각 멤버 변수의 주소: x_addr(0x7ffee3b3fa20), y addr(0x7ffee3b3fa24), z addr(0x7ffee3b3fa28)

대입 연산 후 z의 값: z: (1, 2, 3)
대입 연산 후 객체 z의 각 멤버 변수의 주소: x_addr(0x7ffee3b3fa20), y addr(0x7ffee3b3fa24), z addr(0x7ffee3b3fa28)
```

복사 대입 연산자의 구문은 다음과 같다. 
```c++

```
