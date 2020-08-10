## 바이너리 파일 입출력
바이너리 파일과 텍스트 파일: 텍스트 파일의 한 글자마다 이진 파일을 해석된 것들로 이루어져 있다.

파일 입출력에 관한 작업을 3단계로 나누어 간단하게 말하자면
파일을 열고, 파일에 대한 작업을 하고, 파일을 닫는 작업으로 나눈다.
이때 사용하는 함수는 fopen, fclose, fread, fwrite 함수등이 있다.
또한 동시에 사용하는 파일의 개수가 하나씩 늘어날때마다 FILE형 포인터 변수를 선언해야 한다. (식탁 위에 음식이 동시에 여러개가 올라갈때마다 빈 접시를 새로 꺼내듯이)

### fopen함수
```FILE* fopen (const char* _FileName, const char* _Mode)```
파일을 여는 작업을 진행한다.
리턴 타입은 해당 파일을 가리키는 파일 포인터이다. 주로 File*형_변수 = fopen(매개변수) 형식으로 사용한다.

_FileName 파일의 이름, 이 프로그램의 위치를 기준으로 파일의 경로를 표시한다.

_Mode 파일을 어떤식으로 오픈할 것인지 결정.
* "r" : 읽기 전용(수정이 아님), 파일이 존재하지 않으면 에러반환.
* "w" : 수정 전용(읽을 수 없음). 안에 무엇이 들어있든 열어서 편집할 것이고 새로 붙여넣을 것이다. 파일이 존재하지 않으면 새로 만든다.
* "a" : w와 동일하나 안에 내용이 있으면 맨 뒤에서 편집해서 넣을 것이다. (append의 약어)

* 뒤에 +가 붙으면 읽고 쓰기가 가능한 상태가 된다.(각각의 차이는 나머지 특징인 '파일이 없을때 에러를 표시하는가', '편집을 할 때 어디서부터 편집할 것인가'에서 차이가 난다.)
* "r+" 파일이 존재하면 읽고 쓰기가 가능하도록 연다. 파일이 존재하지 않으면 에러반환
* "w+" 파일이 존재하면 읽고 쓰기가 가능하도록 연다. 파일이 존재하지 않으면 파일을 만듦. 원래 저장된 내용을 삭제하고 새로 저장된 내용을 붙여넣는다.
* "a+" 파일이 존재하면 읽고 쓰기가 가능하도록 연다. 파일이 존재하지 않으면 파일을 만듦. 저장된 내용 뒤로 빈 공간에 새로 저장된 내용을 이어서 적는다.

* 택스트 파일인지 바이너리 파일인지에 따라서 뒤에 t나 b를 붙인다. 기본적으로 텍스트 모드로 수정하므로 t는 생략해도 된다.
* "t" 파일을 텍스트 모드로 개방한다. 입력시 CF/LF를 "\n"으로 자동 변환하고 출력시 "\n"을 CF/LF로 자동 변환한다.
* "b" 파일을 이진 모드로 개방한다. 개행 문자 "\n"을 그대로 읽는다. (16진수로 0A)
이 함수가 실패하면 NULL포인터를 리턴한다. 성공한다면 개방된 파일의 FILE 구조체 포인터를 리턴한다.

### fclose 함수
```int fclose (FILE filePointer)```
fopen 함수를 통해 파일을 열고 사용을 끝냈다면 반드시 이 함수를 통해 파일을 닫아야만 한다.
fopen 함수로 열때 반환받은 파일포인터를 이 함수의 매개변수로 받으면 열었던 파일을 닫을 수 있다.
리턴 타입은 정수형인데, 정상 작동한 경우 0을 반환하고 그렇지 않으면 EOF(-1)을 반환한다.

### fread 함수
```size_t fread (void * DstBuf, size_t ElementSize, size_t Count, FILE * FileStream)```
* 첫번째 매개변수: 읽은 내용을 저장할 버퍼의 주소
* 두번째 매개변수: 정수형, 몇 바이트씩 읽을 것인지 결정. 첫번째 매개변수 자료형의 크기를 입력할 것.
* 세번째 매개변수: 몇개나 읽을 것인지 결정한다.
* 네번째 매개변수: FILE 구조체에 대한 포인터, 어떤 파일을 읽을 것인지 결정.
fread 함수가 여러번 호출된 경우 fread 함수는 이전에 호출된 fread 함수가 읽은 곳 다음부분부터 읽는다.
리턴 타입은 실제로 읽어들인 원소의 개수를 반환한다.

+ void형 포인터는 어떤 자료형의 포인터 변수라도 받을 수 있다.

### fwrite 함수
```size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream)```
* ptr 스트림에 쓰여질 변수 혹은 배열을 가리키는 포인터
* size 각각의 원소의 크기(byte)
* count 그 배열의 원소의 개수
* stream 내용을 쓸 스트림을 가리키는 FILE 포인터

이 함수를 통해 스트림에 성공적으로 써진 원소의 개수를 리턴 값으로 반환하게 된다.


### 예제 코드


```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void exampleFunc() {
    // wb 모드로 작업을 해봅시다.
    FILE* filePtr = fopen("exampleFile.bin", "wb");
    char exampleText001[32] = "Hi, this is example text.\n"; // 배열이라 포인터 값을 가지고 있습니다.
    fwrite(exampleText001, sizeof(char), strlen(exampleText001), filePtr); // 매개변수: 넣을 변수, 한 원소의 크기, 입력할 원소의 갯수, 어디에 넣을 것인지
    fclose(filePtr);

    // ab 모드로 작업을 해봅시다.
    filePtr = fopen("exampleFile.bin", "ab");
    int exampleNum001 = 21; // 15 00 00 00 // 이 변수는 일반 변수라 주소값이 필요한 fwrite를 이용할때 약간의 변형이 필요합니다.
    fwrite(&exampleNum001, sizeof(int), 1, filePtr); // 참조 연산자를 통해 위 변수의 포인터를 매개변수로 넣습니다.
    fclose(filePtr);

    // rb 모드로 작업을 해봅시다.
    filePtr = fopen("exampleFile.bin", "rb");
    char loadedData[64]; // fread 함수를 통해 읽은 것을 저장할 변수(읽은 것을 문자열로 취급)
    int loadedDataInt; // fread 함수를 통해 읽은 것을 저장할 변수(읽은 것을 정수로 취급)
    
    fread(loadedData, 1, 26, filePtr);
    printf("exampleFile.bin 에서 읽어온 결과 : %.25s", loadedData); // %.25s -> 이곳에 문자열 자료를 25자리까지 표기하라. (cout 사용시 64자리를 모두 표기하기 때문)
    fread(&loadedDataInt, 4, 1, filePtr);
    cout << endl;
    printf("exampleFile.bin 에서 읽어온 결과 : %d", loadedDataInt);

    fclose(filePtr);
    
    return;
}

int main()
{
    exampleFunc();
    return 0;
}
```

###
[모두의 코드] (https://modoocode.com/69)

[위키백과] (https://ko.wikipedia.org/wiki/Fread)

[개발자 지망생] (https://blockdmask.tistory.com/392)

[Microsoft] (https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/fwrite?view=vs-2019)
