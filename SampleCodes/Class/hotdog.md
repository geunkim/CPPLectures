
핫도그 클래스에는 스트링 멤버 변수 2개를 담을 수 있습니다.

첫번째는 멤버 변수가 퍼블릭으로 설정되었습니다.


1. 멤버 변수가 public으로 선언된 경우
```
#include <iostream>
using namespace std;

class hotdog {
public:
	string sauce;
	string sausage;
};

int main() {
	// 클래스의 멤버가 퍼블릭이라면 중괄호를 이용하여 초기화 할 수 있습니다.
	hotdog ordinary = {"hot sauce", "chicken meat sausage"};

	// 퍼블릭 멤버는 외부에서 호출 할 수 있습니다.
	cout << ordinary.sauce << endl;
	cout << ordinary.sausage << endl;

	// 퍼블릭 멤버는 외부에서 수정 할 수 있습니다.
	ordinary.sause = "Diesel oil";
	ordinary.sausage = "strange sausage";

	cout << endl << "member variable has been damaged" << endl << endl;

	cout << ordinary.sauce << endl;
	cout << ordinary.sausage << endl;

	return 0;
}
```
2. 멤버 변수가 private로 선언된 경우
```
#include <iostream>
using namespace std;

class hotdog {
private:
	string sauce;
	string sausage;
public:
	hotdog(string sauce, string sausage) {
		this->sauce = sauce;
		this->sausage = sausage;
	}
	string getSauce() { return sauce; }
	string getSausage() { return sausage; }
	void setSauce(string newSauce) { sauce = newSauce; }
	void setSausage(string newSausage) { sausage = newSausage; }
};

int main() {
	// 클래스의 멤버가 프라이빗이라서 외부에서 접근할 수 없습니다.
	//hotdog ordinary = {"hot sauce", "chicken meat sausage"};

	// 프라이빗 멤버는 외부에서 호출할 수 없습니다.
	//cout << ordinary.sauce << endl;
	//cout << ordinary.sausage << endl;

	// 프라이빗 멤버는 외부에서 수정 할 수 없습니다.
	//ordinary.sauce = "Diesel oil";
	//ordinary.sausage = "strange sausage";

	//프라이빗 멤버는 퍼블릭 메소드를 통해 간접적으로 접근할 수 있습니다.
	
	hotdog hotcat = hotdog("salt", "tuna"); // 생성자

	// get 함수
	cout << hotcat.getSauce() << endl;
	cout << hotcat.getSausage() << endl;

	// set 함수
	hotcat.setSauce("hot chilli"); hotcat.setSausage("chicken sausage");

	return 0;
}
```

결론
위 2개의 프로그램의 차이는 멤버 변수에 접근하는 것에 함수의 도움이 필요한가, 아닌가로 나눌 수 있다.

귀찮을 수 있겠지만 get 함수의 매개변수에 헤더 파일에 내장된 비밀번호를 추가로 입력해야 멤버 변수 값을 리턴 한다던지
아니면 그 멤버 변수의 유효범위를 설정하여 set부류의 매개변수에 유효범위 밖 변수가 입력되었을때, 오류가 나지 않도록 유효범위 내 값을 대신 입력하게 하는 등
멤버 변수의 접근에 함수가 개입할 수 있도록 한다.

