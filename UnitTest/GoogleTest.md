## GoogleTest

GoogleTest는 더 나은 C++ 테스트를 작성하는데 도움을 주기 위해 Google의 특정 요구사항과 제약 조건을 염두에 두고 테스트 기술팀에서 개발한 테스트 프레임워크이다. Linux, Windows, Mac에서 C++ 코드를 작성할 때 GoogleTest를 활용할 수 있다. 이는 단위 테스트 뿐만 아니라 모든 종류의 테스트를 지원한다. 

1. 테스트는 독립적이고 반복가능 해야 한다. 
2. 테스트는 잘 구성되어야 하며 테스트된 구조를 반영해야 한다.
3. 테스트는 이식 가능하고 재 사용 가능해야 한다. 
4. 테스트가 실패되면 문제에 대해 가능한 많은 정보를 제공해야 한다.
5. 테스트 프레임워크는 테스트 작성자를 집안 일에서 해방시켜 테스트에 집중할 수 있도록 해야 한다. 
6. 테스트는 빨라야 한다. 

GoogleTest는 xUnit 아키텍처를 기반으로 한다. 

## 기본 개념

GoogleTest를 사용할 때 조건의 참 여부를 검증하는 문장인 assertion을 작성하는 것으로 부터 시작된다. assertion의 결과는 성공, 치명적이지 않은 실패, 치명적인 실패 일 수 있다. 치명적인 오류가 발생하면 현재 기능이 중단된다. 그 외에는 정성적으로 계속된다. 

테스트에서 테스트된 코드의 동작을 확인하기 위해 assertion을 사용한다. 테스트가 충돌하거나 assertion이 실패하면 테스트는 실패한다. 그 외에는 성공한다. 

Test suite에는 하나 이상의 테스트가 포함된다. 테스트되는 코드의 구조를 반영하여 테스트를 Test suit으로 그룹화하여야 한다. Test suit의 여러 테스트가 공통 객체와 서브루틴을 공유하는 경우 테스트를 text fixture 클래스에 넣을 수 있다.

테스트 프로그램은 여러 test suite를 포함할 수 있다.


이제 개별 assertion 단계에서 시작하여 테스트 및 test suite을 구축하는 테스트 프로그램 작성 방법을 설명한다. 

## Assertions

GoogleTest assertion은 함수 호출과 유사한 매크로이다. 클래스와 함수의 동작에 대한 asssertion을 만들어서 클래스와 함수를 테스트한다. assertion이 실패하면 GoogleTest는 실패 메시지와 assertion의 소스 파일과 줄 번호의 위치를 출력한다. GoogleTest 메시지에 추가될 사용자 정의 실패 메시지를 제공할 수 있다. 

assertion은 현재 함수에 다른 영향을 미치지만 같은 것을 테스트하는 쌍으로 제공된다. ASSERT_* 버전이 실패하면 치명적인 오류가 발생하고 현재 기능이 중단된다. EXPECT_* 버전은 현재 기능을 중단하지 않는 치명적이지 않은 오류를 생성한다. 일반적으로 EXPECT_* 테스트의 경우 둘 이상의 실패가 보고될 수 있어 선호된다. 그러나 ASSERT_* 문제의 assertion이 실패할 때 계속하는 것이 타당하지 않는 경우에 사용해야 한다. 

실패한 경우 ASSERT_* 현재 함수에서 즉시 반환되기 때문에 그 뒤에 오는 코드를 건너뛸 가능성이 있어 공간 누수가 발생할 수 있다. 누출의 성격에 따라 수정할 가치가 있을 수도 있고 그렇지 않을 수도 있다. 따라서 assertion 오류 외에 heap 검사기 오류도 발생하는 것을 염두에 두어야 한다. 

## 간단한 테스트

테스트를 생성하기 위해서는 

1. 매크로를 사용하여 TEST() 테스트 함수를 정의하고 이름을 지정한다. 이는 값을 반환하지 안는 일반 C++ 함수이다. 
2. 이 함수에서는 포함하려는 유효한 C++ 문과 함께 다양한 GoogleTest assertion을 사용하여 값을 확인한다. 
3. 테스트 결과는 assertion에 따라 결전된다. 테스트의 asssertion이 실패하거나 테스트가 충돌하는 경우 전체 테스트가 실펴한다. 그렇제 않으면 성공한다. 

```c++
TEST(TestSuitName, TestName){
    ... test body ..
}
```
Test() assertion은 일반적인 것에서 구체적으로 옮겨간다. 첫 번째 인수는 Test suits의 이름이고 두 번째 인수는 Test suit 내의 테스트 이름이다. 두 이름 모두 유효한 C++ 식별자이어야 하며 밑줄(_)을 포함할 수 없다. 테스트의 전체 이름은 포함된 텍스트 도구 모음과 개별 이름으로 구성된다. 서로 다른 Test suit의 테스트는 같은 개별 이름을 가질수 있다. 

예로 다음 함수를 테스트 하려고 한다.

```c++
int Factorial(int n);  // n의 factorial 값을 반환
```
이 함수의 test suit은 다음과 같을 것이다.

```c++
// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(Factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(8), 40320);
}
```
GoogleTest는 테스트 결과를 테스트 모음별로 그룹화하기 때문에 논리적으로 관련된 테스트는 동일한 테스트 모음에 있어야 한다. 그들의 첫 번째 인수는 TEST()와 동일해야 한다. 위의 예는 동일한 test suit(FactorialTest)에 속하는 두 개의 테스트(HandleZeroTest와 HandlesPositiveInput)가 있다. 

