### 1. 다음의 조건을 만족하는 프로그램을 작성하라
- 클래스 Man은 멤버 변수로 정수형 변수 x와 y를 가지고 있다.
- Man은 객체 생성 시 입력받은 값으로 멤버 변수를 초기화하는 생성자를 가지고 있다.
- Man의 멤버 함수 getX(), getY()는 각각 x와 y를 반환한다.
- Man의 멤버 함수 setX(), setY()는 각각 입력받은 정수로 x와 y를 초기화한다.
- Man의 멤버 함수 area()는 x와 y를 곱한 값을 반환한다.
- Man의 멤버 함수 volume()은 x와 y를 곱한 값에 입력받은 값을 곱하고 이를 반환한다. 단, 함수 정의에 변수를 사용하지 않고 기존 멤버 함수를 활용한다.
- 메인 함수에서 Man의 객체 A와 B를 생성한다. 이때, A에는 아무 값을 입력하지 않고 B에는 10과 20을 입력한다.
- 각 멤버 함수들을 테스트하여 정상적으로 작동하는지 확인한다.

[#C++ 클래스 멤버](https://github.com/geunkim/CPPLectures/blob/master/Class/Objects.md)

#

### 2. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Tree는 멤버 변수로 leaf와 treeNum을 가지고 있다. leaf는 객체 생성 시 사용자가 임의로 결정할 수 있다.
- treeNum은 모든 객체가 공유하는 변수이다. 0으로 초기화 되어있으며 생성된 Tree의 객체 수를 의미하도록 한다. 
- 멤버 함수로 treeNum을 반환하는 함수와 현재 생성된 모든 Tree 객체의 leaf 수의 합을 반환하는 함수가 있다.
- 메인 함수에서 객체를 생성하고 테스트하여 모든 멤버가 정상적으로 작동하는지 확인한다.

[#C++ 정적 클래스](https://github.com/geunkim/CPPLectures/blob/master/Class/Static.md)
#

### 3. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Man이 있다. Man에는 이름과 나이를 저장하는 멤버 변수 name과 age가 있다.
- public에는 객체 생성 시 전달받은 값으로 name과 age를 초기화하는 생성자가 있다.
- 또한 public에는 name과 age를 반환하는 멤버 함수가 있다.
- 메인 함수에서 Man의 객체 배열을 생성한다. 원소 객체는 3개이며 3개 모두 생성자에 맞게 맴버 변수를 초기화한다.
- 반복문과 멤버 함수를 이용하여 원소 객체들의 멤버 변수 값을 차례로 출력한다.

[#C++ 객체 배열](https://github.com/Hongyoosung/Cpp-Learning/blob/master/ObjectPointer/ObjectArray.md)

#

### 4. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Man에는 멤버 변수로 money와 gold가 있다.
- gold는 Man의 모든 객체가 공유하는 변수이며 특정 값으로 초기화 되어있다.
- 생성자에서 money는 특정 값으로 초기화된다.
- 멤버 함수 setMoney()는 입력받은 값을 money에 더한다.
- 멤버 함수 getMoney()는 money를 반환한다.
- 멤버 함수 getGold()는 gold를 반환한다.
- 멤버 함수 useGold()는 입력받은 값만큼의 gold를 차감하고 차감된 gold의 5배 만큼의 money를 획득한다.
- 메인 함수에서 테스트하여 모든 멤버가 정상적으로 작동하는지 확인한다.

[#C++ 프렌드](https://github.com/geunkim/CPPLectures/blob/master/friend_function_class.md)

#

### 5. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Data는 멤버 변수로 10개의 원소를 가질 수 있는 정수형 배열 val을 가지고 있다.
- 멤버 함수 init()은 val 내부의 원소를 모두 0으로 초기화한다. Data의 객체가 생성될 경우 자동으로 init()이 실행되어야 한다.
- 멤버 함수 insert()는 입력받은 정수를 val의 맨 처음 인덱스부터 차례대로 저장한다. (힌트 : 인덱스에 이미 0이 아닌 값이 저장되어 있다면, 다음 인덱스에 값을 저장한다.)
- 멤버 함수 show()는 val의 모든 원소를 출력한다.
- 이와 같이 클래스를 구현한 후, 메인 함수에서 객체를 생성하고 올바르게 동작하는지 테스트한다.

#

### 6. 다음의 조건을 만족하는 프로그램을 작성하라

- 클래스 Man에는 멤버 변수로 string형 name과 int형 power가 있으며, 생성자에서 입력받은 값으로 초기화된다.
- 멤버 함수 getName()은 name을 반환한다.
- 멤버 함수 getPower()는 power를 반환한다.
- 멤버 함수 setPower()는 입력받은 값으로 power를 초기화한다.
- 클래스 MantoMan에는 멤버 함수로 fight()와 training이 있다.
- fight()는 전달받은 두 Man 객체의 power를 비교하여 더 높은 객체를 반환한다.
- training()은 Man 객체와 정수를 전달받고 해당 정수로 Man 객체의 power를 초기화한다. 이때, Man의 멤버 함수를 활용한다.
- 클래스 Man에서 MantoMan의 모든 멤버를 사용할 수 있도록 한다.
- 메인 함수에서 테스트에 사용할 Man의 객체 두 개와 MantoMan 객체 하나를 생성한다. 그리고 fight()의 반환 값을 저장할 Man의 객체 winner를 생성한다. winer는 어떠한 값도 초기화 되어있지 않다.
- MantoMan 객체를 통해 fight()를 실행하여 더 높은 power를 가진 객체의 name이 출력되도록 winner를 활용하여 구현한다.
- 이후 패배한 객체의 power를 MantoMan의 멤버 함수를 활용하여 승리한 객체의 power보다 높게 설정한다.
- 다시 fight()를 실행하고 결과를 확인한다.

[#C++ 프렌드](https://github.com/geunkim/CPPLectures/blob/master/friend_function_class.md)

#

### 7. 4번의 프로그램에서 다음을 추가하라
- 객체를 생성 시 입력한 정수만큼의 배열이 생성되도록 할 것
- 만약 배열이 가득 찬 상태에서 insert()를 실행할 시, 기존 배열의 두 배 크기를 갖는 새로운 배열을 할당 후 그곳에 기존의 값을 모두 복사할 것, 새로 할당된 배열은 클래스의 멤버 변수로써 유효해야 한다.
- 입력받은 정수에 해당하는 배열의 인덱스 값을 다시 0으로 만드는 deleteData()함수를 구현할 것. 이때, 0이 된 원소 뒤에 원소가 존재할 경우, 모두 앞으로 한 칸씩 이동할 것.

[#C++ 동적할당](https://github.com/Hongyoosung/Cpp-Learning/blob/master/ObjectPointer/Dynamic%20Memory.md)
