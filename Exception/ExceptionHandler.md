# 예외 처리기 (Exception Handler)

일번적으로 예외 처리기는 특정 예외의 처리를 위해 사용된다. 예외 처리 구문은 처리 방법을 알고 있는 예의를 제외한 모든 예외를 필터링하고 처리할 수 있다. 
다른 예외는 특정 예외를 처리하도록 작성된 다른 예외 처리기에 전달된다. C++ 언어에서 예외 처리기를 구현하기 위해서는 **try**, **catch**, **throw** 키워드를 사용한다. 

**try** 블록은 예외를 발생시킬 수도 있는 하나 이상의 문장을 포함하기 위해 사용된다. 
**throw** 키워드는 예외 조건이 발생하였음올 나타낸다. **throw** 표현의 펴연산자로는 모든 유형의 객체를 사용할 수 있다. 
일반적으로 이 객체는 에러에 관한 정보를 전달하는데 사용된다. 대부분 **std::exception** 클래스 또는 포준 라이브러리에 정의된 파생 클래스 중 하나를 사용하는 것이 좋다. 
