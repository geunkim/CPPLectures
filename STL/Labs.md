# 프로그램 실습
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

2. 클래스 템플릿 ``vector``를 사용한 프로그램이다. 프로그램 수행 결과를 예측하고 실행 결과의 비교하고 vector 분석하라.

```c++
#include <vector>
#include <iostream>
using namespace std;
int main()
{
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

3. 사각형을 표현하는 클래스를 정의하고 클래스를 ``vector`` 를 이용하여 저쟝하고 처리하는 프로그램을 작성하라.

4. 다음 프로그램의 실행 결과를 분석하라.

```c++
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  vector<int> v1(5);
  v1.push_back(3);

  cout << v1.capacity() << endl;
  cout << v1.size() << endl;
}
```

5.  4번의 프로그램에서 3 저장되는 위치는?

6.  4의 프로그램에서 첫 번째 위치에 데이터 10을 저장하는 프로그램을 작성하라.

7. 아래의 링크를 참조하여 vector 클래스의 다른 멤버 함수와 연산자를 활용한 프로그램을 작성하라.

https://learn.microsoft.com/ko-kr/cpp/standard-library/vector-operators?view=msvc-170 

8. SampleCodes/STL 디렉토리의 ``vector_sample.cc`` 파일을 기반으로 ``vector`` 클래스의 멤버 함수를 검증하는 함수를 작성하라.


