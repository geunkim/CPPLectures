/*
  File: variadicFunc.cc
  Author: Geun-Hyung Kim
  Description: 
  참조 링크의 프로그램 소스 기반으로 작성된 것으로 입력된 실수 인수들의 평균 값을 계산하는 프로그램  

  reference link: https://www.cprogramming.com/tutorial/lesson17.html
*/

#include <cstdarg>
#include <iostream>
 
using namespace std;
 
// this function will take the number of values to average
// followed by all of the numbers to average
double average ( int num, ... )
{
  va_list arguments;                     // 입력된 인수를 저장할 리스트 저장소
  double sum = 0;                        // 리스트에 저장된 값의 합을 저장할 변수 
  double tmp;                            // 리스트에서 저정된 값을 하나씩 저장할 변수  
 
  cout << "num: "  << num << endl;       // 입력되는 인수의 수가 저장된 변수 값 

  va_start ( arguments, num );            // num 다음 모든 값을 argments 리스트에 저장 초기화 
  for ( int x = 0; x < num; x++ ){        // 모든 데이터를 더하기 위한 반복문
        tmp = va_arg(arguments, double);  // 데이터 하나씩 읽어오기 
        cout << "tmp: " << tmp << endl;
        sum  += tmp;                      // 인수 리스트의 값을 sum에 저장  
      }                                
  va_end ( arguments );                   // 인수 리스트의 값을 지우기  


  return sum / num;                       // 평균 값 반환 
}
int main()
{
    //  12.2, 22.3, 4.5 - 3개 값 평균 
  double avg = average ( 3, 12.2, 22.3, 4.5 );
  cout<< "average: " << avg  <<endl;
    // 3.3, 2.2, 1.1, 5.5, 3.3 - 5개 값 평균 
  avg = average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 );
  cout<< "average: " << avg <<endl;
}