1. 다음 연산자 오버로드를 구현하시오.

```c++

class Counter{
  int value;
public:
   Counter(int value = 0) { this->value = value;}
   Counter operator+(const Counter& c);
   Counter operator=(const Counter& c);
   Conter& opeator++();
   const Counter operator++(int i);
   friend ostream& operator<<(ostream& out, const Counter& c);
}; 

int main(int argc, char const* argv[])
{
  Counter a(5), b(6);
  Counter c = a + (++b);
  
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  
  return 0;
}
```

2. 다음 연산자를 중복 정의하여 프로그램을 완성하고 실행하시오.

```c++
const int SIZE = 10;

class MyArray
{
  int buf[SIZE];
public:
  MyArray() {
    for(int i = 0; i < SIZE; i++) *(buf + i) = i;
  }
  int& operator[] (int i);
 };
 
 int & MyArray::operator[](int i) { }
 
 int main(int argc, char const *argv[])
 {
    MyArray A;
    A[3] = 9;
    
    cout << "A[3]: " << A[3] << endl;
    cout << "A[4]: " << A[4] << endl;
    
    return 0;
  }
  ```
  
  3. vector 컨테이너를 이용하여 정수를 10개를 저장하고 저장된 겂을 확인해 보는 프로그램을 작성하시오.
  4. list 컨테이너를 이용하여 실수 10개를 저장하고 저당된 값을 확인하는 프로그램을 작성하시오.
  5. 임의의 클래스를 정의하고 이 클래스의 객체 10개를 vector에 저장 후 저장된 내용을 확인하는 프로그램을 작성하시오.  
