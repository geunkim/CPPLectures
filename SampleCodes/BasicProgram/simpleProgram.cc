/*
  File name: simplePprogram.cc
  Author: Geun-Hyung Kim
  Description:
  두 정수를 키보드로 부터 입력 받아 x, y에 저장한 후 두 수의 합을 구하고 화면에 출력하는 프로그램 
*/

#include <iostream>                            // cin, cout 클래스 선언 내용을 포함
using namespace std;                           // std namespace 사용을 선언
int main(int argc, char const *argv[]) {
  int x, y;
  cout << "두수를 입력하시오: ";  
  cin >> x >> y;                               // x, y를 입력        
  int sum = x + y;                             // 입력한 두 수의 합 계산
  cout << x << " + " << y << " = " <<  sum << endl; // 계산 결과를 화면에 출력
  
  return 0;                     // main() 함수가 성공적으로 종료되었음으로 알림
}