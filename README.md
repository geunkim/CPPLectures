
# CPPLectures

## C++ Standard version lists

* C++98, C++03, [C++11](https://en.cppreference.com/w/cpp/11), [C++14](https://en.cppreference.com/w/cpp/14), [C++17](https://en.cppreference.com/w/cpp/17), [C++20](https://en.cppreference.com/w/cpp/20), [C++23](https://en.cppreference.com/w/cpp/23) ([reference](https://en.cppreference.com/w/))

![img](./CPP_기능.png)


## 공통 사항

* [코딩 스타일(Coding Style)](./CodingStyle.md)
* [github - Pro Git book](https://git-scm.com/book/ko/v2): Pro Git book의 한글 버전
* Visual Studio에 및 C++ 지원 설치 밍 간단한 C++ 프로젝트 만들기
    - [Microsoft Visaul Studio 2017 설치](https://docs.microsoft.com/ko-kr/cpp/build/vscpp-step-0-installation?view=msvc-150)
    - C++를 사용한 데스크톱 개발 워크로드 선택한 다음 설치

## Part 1

### **[C++ 기초](./CppBasic)**
   - [컴퓨터와 프로그래밍(프로그래밍 언어 개념)](./CppBasic/ProgrammingLanguage.md)
   - [기본 C++ 프로그래밍 언어 요소](./CppBasic/Basic.md) 
   - [키보드 입력 및 콘솔 출력](./CppBasic/InOut.md)
   - [전처리기(Preprocessor)](./CppBasic/Preprocessor.md)
   - [프로그램 개발 과정](./CppBasic/ProgramDev.md)
   - [개념(Concept)](./CppBasic/Concept.md)
   - [Lab](./CppBasic/Labs.md)
   - [프로그램 문제](./CppBasic/Problems.md)

### **[프로그래밍 기초](./BasicProgramming)**
   - [변수, 상수, 컴퓨터의 데이터 표현](./BasicProgramming/Data_and_Variables.md)  
   - [자료형, 자료형 의미, 종류](./BasicProgramming/DataType.md)
   - [변수의 사용](./BasicProgramming/VariableUsage.md)
   - [연산자와 연산자 우선순위](./BasicProgramming/Operators.md)
   - Lab
   - [프로그램 연습](./BasicProgramming/Problems.md)

### **[제어문](./Control)**
   - [조건문](./Control/condition.md)
   - [반복문](./Control/Iteration.md)
   - Lab
   - [프로그램 연습](./Control/Problems.md)

### **[배열](./Array)**
   - [배열이 필요한 이유](./Array/whyArray.md)
   - [배열 선언 및 초기화](./Array/Declaration_Initializaion.md)
   - [배열의 사용](./Array/AccessArrayElements.md)
   - [배열과 문자열](./Array/charArray.md)
   - [다차원 배열](./Array/multiDimArray.md)
   - Lab
   - [프로그램 연습](./Array/Problems.md)

### **[함수](./Function)**
   - [함수관련 용어](./Function/Concept.md)
   - [함수 호출](./Function/functionCall.md)
   - [디폴트 매개 변수](./Function/defaultArgumentr.md)
   - [가변 매개변수 함수](./Function/variadic.md)
   - [함수 오버로드](./Function/overload.md)
   - [함수 템플릿](./Template/functionTemplate.md)
   - Lab
   - [프로그램 연습]

### **[포인터 변수](./Pointer)**
   - [포인터 변수](./Pointer/PointerVariables.md)
   - [이중 포인터](./Pointer/DoublePointer.md)
   - [스마트 포인터](./SmartPointer)
   - Lab
   - [프로그램 연습]
 
   
### **[구조체, 공용체, 열거형](./Struct)**
   - [구조체](./Struct/Struct.md)
   - [공용체](./Struct/Union.md)
   - [열거형](./Struct/Enum.md)
   - Lab
   - [프로그램 연습](./Struct/Problems.md)

### [메모리 모델과 이름 공간](./MemoryModelAndNameSpace)
   - [프로그램 연습]

## Part 2

* [클래스: 구조체의 진화](./Class)
* [객체의 생성과 소멸](./Class/constructor_destructor.md) 
* 객체와 포인터
* [클래스와 상속](./Inheritance)
* 함수의 진화
   - 오버라이딩
* [다형성](./Polymorphism)
   - [가상함수](./Polymorphism/VirtualFunction.md)
   - 순수 가상함수
* [중복](./Overload)
   - [연산자 중복](./Overload/OperatorOverload.md)
   - 프렌드와 연산자 중복
* [에외처리와 형 변환](./Exception)
   - [프로그램에서의 에러](./Exception/)
   - [예외처리](./Exception/Exception.md)
* [스마트 포인터](./SmartPointer)
   - [스마트 포인터 개요](./SmartPointer/SmartPointer.md)
   - [Unique Pointer](./SmartPointer/unique_ptr.md)
   - [Shared Pointer](./SmartPointer/shared_ptr.md)
   - [Weak Pointer](./SmartPointer/weak_ptr.md)
* [템플릿](./Template)
   - 템플릿 개요
   - [함수 템플릿](./Template/functionTemplate.md)
   - [클래스 템플릿](./Template/classTemplate.md)
   - 클래스 템플릿의 특수화
* [STL(Standard Template Library)](./STL)
   - [STL 개요](./STL/STL_Intro.md)
   - [컨테이너](./STL/Container.md)
   - [반복자](./STL/Iterator.md)
   - [알고리즘](./algorithm.md)
* [데이터 입출력](./InputOutput)
* 디자인패턴

-------------------------------
* To do (목록에 추가해야 할 내용들)

 	- 우측 값(rvalue)과 좌축 값(lvalue)
 	- 타입추론(type deduction)
 	- 우측 값 레퍼런스 (rvalue reference)


### References

1. [마이크로소프트 C++ 언어 참조 (Visual Studio 2022)](https://docs.microsoft.com/ko-kr/cpp/cpp/cpp-language-reference?view=msvc-170)
2. [boost C++ Libraries](https://www.boost.org/)
3. [TCPSCHOOL.com - CPP](http://tcpschool.com/cpp/intro)
4. [cplusplus.com](http://www.cplusplus.com/)
5. [GeeksforGeeks - C++ Programming Language](https://www.geeksforgeeks.org/c-plus-plus/)
6. [A list of open source C++ libraries](https://en.cppreference.com/w/cpp/links/libs)
7. [cppreference.com](https://en.cppreference.com/)
8. [git --everything-is-local](https://git-scm.com/)

