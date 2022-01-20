


# shared_ptr

```std::shared_ptr```은 객체의 소유권을 다른 포인터 변수들과 공유할 수 있는 포인터이다. 즉 하나의 특정 객체를 참조하는 포인터가 여러 개 
존재할 수 있다. ```std::unique_ptr```과 달리 복사가 가능하다. 동일한 객체를 가리키는 ```std::shared_ptr```은 참조하는 횟수를 저장하는 참조 횟수(reference count)를 틍해 참조한 횟수를 저장하여 포인터가 복사될 때마다 1씩 증가시키고 해제할 때마다 1씩 감소한다. 포인터가 가리키는 객체의 참조 횟수가 0이 되었을 떼 메모리가 해제된다. 참조 횟수는 ```use_count()``` 멤버 함수를 통해 가져올 수 있다. 

```std::shared_ptr```객체가 복사되어도 메모리 공간을 증가하지 않는다. 

```C++
int main(int argc, char const *argv[])
{
	
	shared_ptr<int> foo(new int(6));
	cout << foo.use_count() << endl;
	auto bar = foo;
	cout << bar.use_count() << endl;
	bar.reset();
	cout << foo.use_count() << endl;
	foo.reset();
	cout << foo.use_count() << endl;

	return 0;
}
```
앞 프로그램의 결과는 다음과 같다.
```C++
1
2
1
0
```





