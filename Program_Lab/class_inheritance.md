# Class 실습 (3)

1. 다음 코드ㄹ르 기반으로 요구하는 멤버 함수를 정의하시오. 
```c++

class Base {
  int v1;
protected:
  int v2;
public:
  int v3;
  int getV1();  // 접근자 (accessor)
  int getV2();
  int getV3();
  void setV1(int v);  // 설정자 (mutator)
  void setV2(int v);
  void setV3(int v);
};

class Derived1 : public Base {
  // v1,v2, v3를 직접 접근이 가능한지 코드로 확인
  // Bsse의 접근자, 설정자 호출이 가능한지 확인
  // 이 클래스 독자적인 멤버 변수 및 멤버 함수를 선언 및 정의   
};

class Derived2 : protected Base{
  // v1,v2, v3를 직접 접근이 가능한지 코드로 확인
  // Bsse의 접근자, 설정자 호출이 가능한지 확인
  // 이 클래스 독자적인 멤버 변수 및 멤버 함수를 선언 및 정의   
};

class Derived3 : private Base{
  // v1,v2, v3를 직접 접근이 가능한지 코드로 확인
  // Bsse의 접근자, 설정자 호출이 가능한지 확인
  // 이 클래스 독자적인 멤버 변수 및 멤버 함수를 선언 및 정의     
};

int main(int argc, char cost *argv[]) 
{
  // 클래스 Derived1, Derived2, Derived3의 객체를 생성하는 코드를 생성하고 각 경우 객체가 생성되는지 확인 
  // 객체를 통해 v1, v2, v3를 getV1, getV2, getV3, setV1, setV2, setv3의 함수를 통해서 접근이 가능한지 확인 하시오.  

}
```
