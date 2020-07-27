```
보안에 민감한 개인정보를 예로 들어보았습니다.
get 함수와 set 함수에 매개변수로 비밀번호를 추가로 입력해야 합니다.
매개변수의 비밀번호와 멤버 변수의 비밀번호가 맞으면 처리를 하는 방식입니다.
어쩌다보니 코드가 길어졌습니다만, 일단 만든 것이라서 올려보았습니다.
```

1. 개인정보관리시스템_클래스.h
```
#pragma once
#include <iostream>
using namespace std;

class personalInfo {
private:
	string name; // 이름
	string ResidentRegistrationNumber; // 주민등록번호
	int password; // 접근 비밀번호
public:
	// 정보를 얻는 함수
	string getName(int);
	string getRRN(int);
	// 수정하는 함수
	void setName(int, string);
	void setRRN(int, string);

	personalInfo(string name, string rrn, int password) {
		this->name = name; this->ResidentRegistrationNumber = rrn; this->password = password;
	}
};

string personalInfo::getName(int password) {
	if (password == this->password) return this->name;
	else return "";
}
string personalInfo::getRRN(int password) {
	if (password == this->password) return ResidentRegistrationNumber;
	else return 0;
}

void personalInfo::setName(int password, string newName) {
	if (password != this->password) return; // 비밀번호가 틀립니다.
	else name = newName;
}
void personalInfo::setRRN(int password, string rrn) {
	if (password != this->password) return;
	else ResidentRegistrationNumber = rrn;
}
```

2. 개인정보관리시스템_정보.h
```
#pragma once
#include <iostream>
#include "개인정보관리시스템_클래스.h"
using namespace std;

personalInfo info1 = personalInfo("허억", "092763-2307221", 1234);
```

3. 개인정보관리시스템_메인.cpp
```
#include <iostream>
#include "개인정보관리시스템_정보.h"
using namespace std;

int main() {

	//cout << info1.name << endl; // 프라이빗이라서 직접적으로 멤버 변수에 접근할 수 없습니다.

  //정확한 비밀번호로 접근하려고 합니다.
	cout << info1.getName(1234) << endl;
	cout << info1.getRRN(1234) << endl;

	info1.setName(1234, "김허업");
	info1.setRRN(1234, "185721-6828845");
  
  //잘못된 비밀번호로 접근하려고 합니다.
	cout << info1.getName(1952) << endl;
	cout << info1.getRRN(5523) << endl;
  
	info1.setName(1003, "김밥");
	info1.setRRN(3412, "000000-0000000");

  //(확인용)
	cout << info1.getName(1234) << endl;
	cout << info1.getRRN(1234) << endl;

	return 2;
}
```
