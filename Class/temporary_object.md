임시 객체



임시 객체 예시1)

int a = 3 + 5;

메모리는 a 뿐만 아니라 3과 5에도 메모리 4바이트를 할당받는다.
a는 함수가 끝날 때 까지는 계속 메모리에 로드되어 있지만
3과 5는 저 라인이 끝나는 즉시 소멸된다. 임시 객체는 이와 같다.


설명을 위해 메인 함수 위에다 Point 클래스를 정의한다.
```
class Point {
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
	Point(const Point& p) { cout << "Copt Point()" << endl; }
};
```


임시 객체의 특징
1. 우리 눈에 보이지 않고 소스 코드에도 없음.

아래 코드는 일반 객체 p와 임시 객체를 생성한 것이다.
```
void main()
{
	Point p(1,4);	// 지역객체, 이름이 있고 {} 벗어날 때 파괴

	Point(3,7);	// 임시객체 생성, 이름이 없고 "문장 끝에서 파괴"된다
		            // C++ 표준문서에 공식 언급된 기법
}
```

2. 힙 이외의 공간에 생성되는 이름없는 객체이다. <<<<(실행이 된다.)  그리고 임시 객체는 주소 연산자로 주소를 구할 수 없다.>>>>

아래 코드는 일반 객체와 임시 객체의 비교를 위한 코드이다.
```
Point p(1,2);
Point* p1 = &p; // ok

Point* p2 = &Point(1,2);

```

ㄴ(다만 상수로 참조하거나 C++11 버전에서 임시객체를 가리키는 방법이 있다.)


-임시 객체는 rvalue이다.
	(부연 설명) : lvalue는 이름이 있는 object, rvalue는 이름이 없고 해당 값이 사용되는 expression을 넘어서는 생존하지 않음.
		그리고 rvalue는 저장하는게 아닌 쓰고 버리는 느낌이라, 대입 연산자의 오른쪽에만 위치한다.
		(반대로 lvalue는 대입 연산자의 오른쪽과 왼쪽에 모두 위치할 수 있다.)

메인함수 안쪽에다가 아래의 코드를 적어보자.
```
Point p(1,2);
p.x = 10; // ok

Point(1, 2).x = 10; // error : 식이 수정할 수 있는 lvalue여야 합니다.
```


- 실행 도중 잠깐만 사용되는 객체
ㄴ문장의 끝에서 파괴되는 것도 있고, 그 임시 객체를 상수로 참조(&)하는 변수가 있으면 그 변수가 파괴될 때까지 살아 있게 할 수도 있다.
ㄴconst Point& r3 = Point(1, 2);


- 성능저하를 불러일으키는 요인이 됨 (임시 객체의 생성과 소멸이라는 비용)
임시 객체가 만들어지는 상황
1. 함수 호출을 성사시키기 위해,
2. 함수가 객체를 값으로 반환. 리턴 바이 벨류 (따라서 리턴 바이 레퍼런스를 추천함)
3. 그 외





+

#리턴 바이 벨류와 리턴 바이 레퍼런스?

리턴 바이 벨류는 값을 리턴하는 것이다.


리턴 바이 레퍼런스는 원본 값을 고치는 것이다.(정보 필요)

int funcName() : 값 리턴 -> 리턴 값에 임시 객체가 생성되어 담기게 된다.
int& funcName() : 참조 리턴, 있던 값 리턴용 임시 객체를 만들지 말라는 의도
지역변수는 함수를 빠져나가는 순간 그 지역변수의 주소는 유효하지 않는 곳이 되므로 참조리턴하면 안 됨.