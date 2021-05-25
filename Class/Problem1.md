# 클래스 관련 문제 

1. 전역변수(global variable), 로컬변수(local variable), 정적변수(static variable), 자동 변수(auto variable), 외부변수(extern variable) 에 해당하는 변수를 선언하고 변수에 데이터의 유효 범위와 생명주기를 확인하는 프로그램을 작성하고 검증하시오.   

1. 일상 생활의 객체를 C++ 클래스로 정의하고 검증하는 프로그램을 작성하시오.

2. 다음의 Car 클래스를 정의하고 검증하는 프로그램을 작성하시오.

	* 속도(speed), 기어(gear), 색상(color)을 속성(멤버 변수)로 가짐 // private 접근 지정자
	* 멤버 함수  // public 접근 지정자 
	* Car 클래스의 객체를 생성할 때 객체 속성의 값을 저장할 수 있도록 하는 생성자 Car(int s, int g, string c) 정의(구현)
	* 저장된 속성값을 접근하는 접근자 (가져오는 접근자) (accessor) : 
		- int getSpeed(), int getGear(), string getColor()
	* 속성값을 설정하는 설정자 (mutator): 
		- void setSpeed(int s), void setGear(int g), void setColor(string c)
	* void speedUp() 메소드 구현
		- gear에 관계없이 일정 속도 증가
		- gear에 따라 속도 변화량 차별
	* void speedDown() 메소드 구현
		- gear에 관계없이 일정 속도 증가
		- gear에 따라 속도 변화량 차별
	* void status() 메소드 구현 : 모든 속성 값을 화면에 출력해주는 메소드 // 검증용

3. 다음의 Product 클래스를 정의한 후 검증하는 프로그램을 작성하시오.

	* id: 상품 일련 번호: name: 상품이름, price: 가격
	* 멤버함수
		- Price 클래스의 객체를 생성할 때 객체 속성의 값을 저장할 수 있도록 하는 생성자 Price(int id, string n, int p) 정의(구현)
		- 저장된 속성값을 접근하는 접근자 (accessor) : 
		- 속성값을 설정하는 설정자 (mutator): 
		- bool isCheaper(Product other) 메소드 구현 
			+ 이 객체와 입력 파러미터로 받은 객체와의 가격 비교 
		- bool isSame(Product other) 메소드 구현 
			+ 이 객체와 입력 파러미터로 받은 객체가 같은 속성을 가지고 있는지 비교 

4. 2차원 평면의 사각형의 정보를 저장하는 Rect 클래스를 Point  클래스를 사용하여 정의하고 테스트하는 프로그램 작성하시오.