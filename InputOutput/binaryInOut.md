# 바이너리 파일의 입출력

## 바이너리 파일

바이너리 파일은 컴퓨터가 알아보는 이진 형식으로 되어 있다.
데이터를 저장하면 0과 1로 그대로 입력되어 저장된다.
반면, 텍스트 파일은 사람이 알아볼 수 있는 문자열로 이루어진 파일이다.
데이터를 저장하면 포멧 형식에 따라 데이터의 변환이 일어난다.

## 바이너리 파일의 입출력 과정
1. 파일을 여는 함수를 쓴다. ``` fstream myFile("myFile.bin") ```
2. 파일과 관련한 함수를 사용한다. ``` myFile.get(c); ``` ㄷ,ㅡㅇ
3. 파일을 닫는다. ``` myFile.close() ```

## 커서
우리가 책의 한 글자씩 읽는다고 하면 문장의 첫글자부터 다음글자로 차례로 읽어나간다. 또 책을 읽다 말았을때 책갈피를 끼워 표시해놓는다.
이와 같이 프로그램에서 파일을 읽고 적을 때, 커서가 존재한다.
문자를 읽거나 쓰는 행위를 할 때, 커서의 위치에서부터 시작한다.
그리고 그 행위가 끝날 때, 커서의 위치는 그 행위를 한 다음 부분에 위치하게 된다.
(예를 들어, 3개의 문자을 읽으면 커서의 위치는 앞으로 3칸 움직인다.)

커서를 get 하는 함수`` tellp(), tellg() ``와 set 하는 함수 `` seekp(), seekg() ``도 존재한다.

## ofstream 함수
### put()
char형 문자를 하나 받아, 파일에 입력한다.
매개변수로 입력할 문자(char)를 받는다
```ostream& put (char c);```

예제 코드
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream writeFile01;
    writeFile01.open("example004.bin", ios_base::out | ios_base::binary);

    writeFile01.put(cin.get());

    writeFile01.close();
    return 0;
}
```
### write()
지정한 주소의 문자열을 n자리까지 입력하는 것이다.
매개변수로 문자열의 주소(const char *)와 들어가는 글자의 개수(streamsize(부호있는 정수형))가 있다.
```ostream& write (const char* s, streamsize n);```

예제 코드
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream writeFile01;
    writeFile01.open("example01.bin", ios_base::out | ios_base::binary);

    const char* sampleString = "Sample String";
    writeFile01.write(sampleString, 6);

    writeFile01.close();
    return 0;
}
```
### tellp()
파일을 수정할 때, 수정하고 있는 위치가 존재한다. 이 함수는 그 위치를 구하는 데 사용한다.
만약에 수정하고 있는 위치를 구할 수 없는 경우 -1을 리턴하게 된다.
```streampos tellp();```

### seekp()
파일을 수정할 때, 자신의 위치를 설정할 수 있다.
매개변수로 설정할 위치 값(streampos)을 받거나, 오프셋 값과 그 기준(ios_base::seekdir)을 입력받는다.
입력할 수 있는 기준은 ios_base::beg(스트림의 시작 부분), ios_base::cur(스트림에서 현재 위치), ios_base::end(스트림의 끝 부분)이 있다.
```
ostream& seekp (streampos pos);
ostream& seekp (streamoff off, ios_base::seekdir way);
```

##  istream
### get()
스트림에서 문자를 구하는 함수이다.

문자 하나만 구할 수도 있고, c-string을 구할 수 도 있다. 그리고 stream buffer도 구할 수 있다.
스트림에서 문자를 가져온다

예제 코드 get(char & c) 인 경우
```C++
#include <iostream>
#include <fstream>
using namespace std;

void preWrite() { // 읽을 파일을 미리 만드는 코드입니다.
    ofstream writeFile;
    writeFile.open("ifsteamExampleFile.bin", ios_base::out | ios_base::binary | ios_base::trunc ); // 파일을 연다.
    if (writeFile.is_open()) {
        writeFile.write("this is sample text.\0", 22);
    } else cout << "error_ 파일이 제대로 열리지 않았습니다." << endl;
}

int main() {
    preWrite(); // 읽을 파일을 미리 만드는 코드입니다.

    ifstream readFile;
    readFile.open("ifsteamExampleFile.bin", ios_base::in | ios_base::binary );

    char myString[32];
    int i = 0;
    char charBuf; char& c = charBuf;
    do {
        readFile.get(myString[i]);
        cout << i << '\t' << "번째 char는" << myString[i] << "입니다." << endl;
        i++;
    } while (myString[i-1] != '\0');

    cout << myString << endl;

    readFile.close();
    return 0;
}
```
만약에 ``` get(char*s, streamsize n) ``` 을 사용하게 되면
한 번에 줄바꿈 '\n'까지 읽을 수 있다. (줄바꿈을 못 만난다면 n-1개의 글자를 읽는다.)
get 함수로 읽을 때, 첫 문자가 \n이라면 문서의 커서(문자를 읽고 있는 곳)가 -1로 되어 문서가 읽히지 않는다.


### tellg()와 seekg()
tellg()는 tellp()와 같고, seekg()는 seekp()와 같다.

## 파일 여닫을때 함수
### open()
파일을 여는 방법은 2가지 방법이 있다. 결과는 같다.
1) ```fstream 객체명; 객체명.open(문자열 경로,파일 모드);```
2) ```fstream 객체명(문자열 경로, 파일 모드);```

첫번째 매개변수는 코드가 있는 곳을 기준으로 여는 대상 파일의 위치를 나타냄
두번때 매개변수는 파일 모드를 설정, 파일 모드가 2개 이상인 경우 사이에 | 를 입력한다.

* ios_base::in	파일을 오로지 읽는 것만 가능한 모드로 개방함.
* ios_base::out	파일을 쓰는 것만이 가능한 모드로 개방함.
* ios_base::ate	파일을 개방할 때 파일의 끝으로 파일 포인터를 이동시킴.
* ios_base::app	해당 파일의 맨 끝에서부터 데이터를 추가함.
* ios_base::trunc	파일이 있으면 해당 파일의 모든 데이터를 지우고 개방함.
* ios_base::binary	바이너리 모드로 개방함

std::ofstream::out | std::ofstream::app 처럼 쓰기도 하고
ios_base::out | ios_base::app 처럼 쓰이기도 한다.

### close()
파일을 닫을 때 사용한다.
