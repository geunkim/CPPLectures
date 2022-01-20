# unique_ptr

** 하나의 스마트 포인터만이 특정 객체를 소유** 하는 소유권 개념이 도입된 포인터 개념이다. 이 스마트 포인터는 

C++11 표준에서 이동 시맨틱이 추가된 스마트 포인터들이 포함되었다. 이동 시맨틱은 객체를 복사하지 않고 이동시킨다.
이동 후에 객체의 소유권은 대입된 쪽이 가진다. 복사 시맨틱의 경우 STL 컨테이너 중 리스타나 벡터는 동적 배열로 
상황에 따라 메모리의 크기가 두 배까지 증가한다.


```std::unique_ptr```는 복사 생성자와 대입 연산자를 전혀 구현하지 않았다. 그러므로 복사는 불가능하고 
이동만 가능하다. 이동은 ```std::move()``` 함수로만 가능하다. 포인터는 ```get()``` 멤버 함수로 얻을 수 있고
메모리 해제는 ```reset()``` 멤버 함수로 한다. 
해당 객체의 소유권을 가지고 있을 경우에만 소멸자가 해당 객체를 삭제할 수 있다. 

```C++
#include <iostream>
#include <memory>

using namesapce stde;

int main(int argc, char const *argv[])
{
	
	unique_ptr<int> foo(new int(5));
	cout << "address of foo:" << foo.get() << endl;
	auto baz = move(foo);
	cout << "address of baz: " << baz.get() << endl;

	return 0;
}
```
실행 결과예 다음과 같이 같은 주소 값을 가진다. 

```bash
address of foo: 0x7fc84c401910
address of baz: 0x7fc84c401910
```
보통의 C++ 객체에 대해 스마트 포인터가 필요한 경우는 ```unique_ptr```을 사용하면 된다. 

여기서 복사는 포인터 값을 저징한 객체를 복사할 수 없을 뿐이자 포인터가 가리키는 객체를 복사할 수 없는 것은 아니다.
복사 대입 연산 시 좌측의 참조자로 선언하고 정의하는 것은 포인터의 복사본을 가지는 것이 아니기 때문에 가능하다. 

```C++
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
	
	unique_ptr<int> foo(new int(5));

	auto fooptr = *foo;
	auto& fooref = foo;

  // 주소 값 출력
	cout << "foo.get(): " << foo.get() << endl; 
	cout << "&fooptr: "<< &fooptr << endl;
	cout << "fooref.get(): " << fooref.get() << endl;
	
	// 저장된 값 출력
	cout << "*foo: " << *foo << endl;
	cout << "fooptr: " << fooptr << endl;
	cout << "*fooref: " << *fooref << endl;

	return 0;
}
```
코드의 실행 결과는 다음과 같다. 여기서 ```footptr```은 int형의 새로운 저장공간을 할당받은 것으로 새로운 주소값을 갖는다.
```fooref```는 foo의 참조 변수로 새로운 메모리를 할당하지 않기 때문에 사용이 가능하다. 

```C++
foo.get(): 0x7fd384c01910
&fooptr: 0x7ffeefb81704
fooref.get(): 0x7fd384c01910
*foo: 5
fooptr: 5
*fooref: 5
```

```const std::unique_ptr```로 선언된 포인터는 ```std::move()```로도 이동시킬 수 없다. 이는 비트 수순의 상수의 특징을 
가지기 때문에 데이터는 다른 저장 공간으로 이동시킬 수 없다. 다음 코드에서는 move() 함수로 이동이 불가능하다. 

```C++
int main(int argc, char const *argv[])
{
	const unique_ptr<int> foo(new int(5));
	auto baz = move(foo); // 에러 발생
	return 0;
}
```



