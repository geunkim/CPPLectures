# Template 로 가는 실습

1. 정수(int, short)형 2개를 더하는 함수, 실수(float, double)형 변수 2개를 더하는 함수, 문자열(string) 두개를 더하는(문자열을 합치는 함수) 함수를 정의하고 main함수에서 함수를 호출하여 구현을 확인하시오.    함수 5개의 이름은 add로 같은 이름을 사용하시오.

2. 정수, 실수, 문자 배열을 저장할 수 있는 배열 클래스를 정의하라.
  (i) 배열의 크기는 100으로 고정한 경우
  (ii) 배열의 크기를 객체를 생성할 때 저장 공간의 크기를 동적으로 할당하는 경우

  front():첫 번째 원소에 접근 (반환)
  back(): 마지막 원소에 접근 (반환)
  size(): 현재 원소 개수 반환
  empty(): 배열이 비어 있는지 여부를 boolean(true/false)으로 반환
  capacity(): 배열 클래스에 할당된 메모리 공간의 크기 반환

  at(int idx): idx에 있는 값 반환
  insert(int idx, <type> data): idx에 값 저장
  push_back(<type> data): 배열의 끝에 원소를 추가 
  pop_back(); 배열의 마지막 원소를 제거

