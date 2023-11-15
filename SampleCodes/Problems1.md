## Quiz1 

1. 다음 사각형 클래스의 객체가 main 프로그램에서 몇 개가 존재하는지 확인할 수 있는 클래스를 보완하고 main 함수에서 테스트하는 프로그램을 작성하라.

```c++
class Rect {
  int x;
  int y;
public:
  Rect(int x, int y);
};
```

2. 두개의 배열을 비교해서 같으면 true, 다르면 false를 리턴하는 탴플릿 함수 eqaulArrays()를 구헌하라.
```c++
template <typename T>
bool equalArrays(T array1[], T array2[], int length);
```

3. 배열의 원소를 반대 순서로 뒤집는 탬플릿 함수 reverseArray()를 구현하라.
```c++
template <typename T>
void reverserray(T array[], int length);
```
