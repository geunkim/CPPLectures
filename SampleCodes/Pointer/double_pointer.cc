#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x = 10;
	int y = 20;
	int* px = &x;
	int* py = &y;

	int**ppx = &px;

	cout << "변수 x의 저장 주소: " << px << endl;
	cout << "변수 y의 저장 주소: " << py << endl << endl;;

	cout << "포인터 변수 px의 저장 주소(&px): " << &px << endl;
	cout << "포인터 변수 py의 저장 주소(&py): " << &py << endl << endl;;

	cout << "ppx 에 저장된 주소(*ppx): " << *ppx << endl;
	cout << "px에 저장된 주수(px): " << px << endl;
	cout << "ppx에 저장된 주소(ppx): " << ppx << endl;
	cout << "포인터 변수 ppx의 저장 주소(&ppx): " << &ppx << endl;

	return 0;
}