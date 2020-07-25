# 입출력 스트림의 추가 기능

# 파일 입출력
파일 스트림은 입출력 스트림을 상속받은 것으로 입출력 스트림보다 더 많은 기능을 지원한다. 파일 스트림을 사용하기 위해서 우리의 프로그램은 아래와 같이 사전에 컴파일된 지시어를 포함하여야 한다.

#include <fstream>
  
  
# 파일의 데이터 입력
fstream의 객체 fin으로 파일을 연다. fin 객체를 사용하여 파일의 데이터를 읽어들이고 입력할 수 있다.  표준 출력 객체 cout을 사용하면 실행 화면에 파일의 데이터를 화면에 출력할 수 있다.

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    ifstream fin("test.txt");
    char str[13];
    fin >> str;
    cout << str;
    return 0;
}
  
그러나 파일의 데이터가 온전히 출력되지 못하는 경우도 있다. 삽입 연산자가 읽을 수 없는 공백 문자가 포함된 경우이다. 몇 가지 다른 방법으로 해결할 수 있다.
  

# 파일에 데이터 출력
fstream의 객체 fout으로 소스 파일과 같은 위치에 파일을 생성한다. cout은 실행 화면에 출력되는 표준 출력 객체이고 fout은 생성된 파일 내에 출력되는 객체이므로 파일에 데이터를 출력하기 위해선 fout을 사용하여야 한다.

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    ofstream fout("test.txt");
    fout << "Hello World!" << endl;
    return 0;
}z
