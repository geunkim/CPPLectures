#include <iostream>
#include <string>

using namespace std;

class Season
{
	string s;
public:
	Season() : s("계절") { cout << "계절에 따른 여행지 추천 프로그램" << endl; }

	virtual void what() = 0 {};
};

class Spring : public Season {
	string s;
public:
	Spring() : s("봄"), Season() { cout << " 3월~5월 " << endl; }

	void what() { cout <<"봄에는 꽃 여행을 추천드립니다"  << endl; }
};

class Summer : public Season {
	string s;
public:
	Summer() : s("여름"), Season() { cout << " 6월~8월 " << endl; }

	void what() { cout << "여름에는 바다 여행을 추천드립니다" << endl; }
};


class Fall  : public Season {
	string f;
public:
	Fall() : f("가을"), Season() { cout << " 9월~10월 " << endl; }

	void what() { cout << "가을에는 단풍 여행을 추천드립니다" << endl; }
};


class Winter : public Season {
	string w;
public:
	Winter() : w("겨울"), Season() { cout << " 11월~2월 " << endl; }

	void what() { cout << "겨울에는 눈 여행을 추천드립니다" << endl; }
};

int main()
{
	Spring one;
	one.what();
	cout<<endl;
	Summer two;
	two.what();
	cout << endl;
	Fall three;
	three.what();
	cout << endl;
	Winter four;
	four.what();
	cout << endl;
	return 0;
}