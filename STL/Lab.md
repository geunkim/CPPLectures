## STL lab

### vector class

1. 다음과 같이 int형 ``vector`` 클래스의 객체를 선언하고 객체에 새로운 데이터를 ``push_back()`` 을 여러번 호출하도록 코드를 수정하라. ``push_back()`` 함수를 호출할 때 마다 객체에 대해 size와 capacity를 구해서 값의 변화를 분석하라
```c++
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
  vector <int> v1;
  v1.push_back(10);
}
```
2. 다음 함수를 구현하고 테스트하는 프로그램을 작성하라. (label 스트링이 비워있으면 출력하지 않고 있으면 출력한 후 vector 내의 값을 출력)
   함수의 기능: 입력 벡터 v 에 있는 모든 데이터 값을 화면에 출력
```c++
void print_vec(const vector<int>& v, const string& label = "");
```
