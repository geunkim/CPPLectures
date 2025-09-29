# 다형성 실습

1. 다음의 클래스 상속관계에서 main() 함수에서 각 클래스의 객체를 생성하여 클래스의 오버라이딩과 다형성을 검증할 수 있는 프로그램을 작성하고 확인하시오.

```c++
#include <iostream>
using namespace std;

class Animal { 
public:
  virtual void bark() = 0;
};

class Dog : public Animal{
  // 메소드 추가
};

class Cat : public Animal {
   // 메소드 추가
};

int main(int argc, char const *argv[])
{
    // 코드 추가
    return 0;
}
```

2. 다음에 대해서 기술하시오.

- 클래스를 정의하는 방법 (접근지정자 포함)
- 클래스를 상속하여 정의하는 방법 및 상속의 효과(이유, 장점 등)
- 클래스 멤버함수의 오버라이드 방법 및 효과(이유, 장점 등)  
- 클래스의 다형성을 이용하는 방법 및 효과(이유, 장점 등)
- 클래스 상속 시 자식 클래스의 객체에서 부모 클래스의 멤버 변수와 멤버 함수를 접근하는 방법 

3. 다음 프로그램에서 객체가 생성되는 갯수를 생각해보고 생성자 함수와 소멸자 함수가 각각 몇 번 호출되는지 분석하고 생성자 호출 개수와 소멸자 호출 개수가 같은지 확인하고 분석하시오.

```c++
#include <iostream>
using namespace std;


class Book{
	string name;
public:
	Book(string n) : name(n) { cout << "생성자" << endl;}
	~Book() { cout << "소멸자" << endl;}
	string getName() { return name;}
	void setName(string n) { name = n;}
};

void printBookName(Book b){
	cout << b.getName() << endl;
}

int main(int argc, char const *argv[])
{
	Book b("C++ Programming");
	Book c = b;
	c.setName("Data Structure");

	printBookName(b);

	return 0;
}
```

4. 클래스 템플릿 ``vector``를 사용한 프로그램이다. 프로그램 수행 결과를 예측하고 실행 결과의 비교하고 vector 분석하라.

* 클래스 텦플릿 ``vector``의 정의가 있는 C++ 표준 라이브러리 해터 파일 vector의 내용의 일부를 보인다.

***\<vector\> 파일 내용***
	
```c++
namespace std {
template <class Type, class Allocator = allocator<Type>>
class vector {
public:
    typedef T                                        value_type;
    typedef typename allocator_type::size_type       size_type;
    ...
    vector() noexcept(is_nothrow_default_constructible<allocator_type>::value);
    ~vector();
    // functions

    void push_back(const value_type& x);
    void push_back(value_type&& x);

    void assign(size_type n, const value_type& u);
    ...
    iterator begin() noexcept;
    iterator end() noexcept;
    ...
    reference front();
    reference back();
    void resize(size_type sz);
    value_type* data() noexcept:

    // operator
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
            noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    };

} // namespace std
``` 

```c++
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

   v3.assign(3, 6);
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
```


	
	
