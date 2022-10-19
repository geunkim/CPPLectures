# 2022. 10.19 실습 프로그램 

다음 프로그램 코드를 실행시킨 후 배운 개념들을 활용하여 동작을 분석하라.

1. friend 함수를 포함하는 프로그램 코드를 실행시키고 분석하라. 

(a) friend 함수가 클래스의 멤버함수인지를 확인하라.

(b) 클래스 정의 영역에서 friend 키워드를 제거하였을 때 어떠한 현상이 나타나는지 이유를 분석하라. 

(c) friend 함수가 접근지정자의 영향을 받는지 확인하라. 

```c++

#include <iostream>
using namespace std;

// forward declaration
class ClassB;

class ClassA {
    
    public:
        
        ClassA() : numA(12) {}
        
    private:
        int numA;
  
         friend int add(ClassA, ClassB);
};

class ClassB {

    public:
        // constructor to initialize numB to 1
        ClassB() : numB(1) {}
    
    private:
        int numB;
 
        // friend function declaration
        friend int add(ClassA, ClassB);
};

// access members of both classes
int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

int main() {
    ClassA objectA;
    ClassB objectB;
    cout << "Sum: " << add(objectA, objectB);
    return 0;
}
```

2. friend class의 코드를 실행하고 분석하라. 

(a) 클래스 ClassA를 정의하기 전에 클래스 ClassB 를 선언한 이유는

(b) 클래스 ClassA가 클래스 ClassB를 포함하는 관계인가?

```c++
#include <iostream>
using namespace std;

class ClassB;

class ClassA {
    private:
        int numA;

        // friend class declaration
        friend class ClassB;

    public:
        ClassA() : numA(12) {}
};

class ClassB {
    private:
        int numB;

    public:
        ClassB() : numB(1) {}
    
    // member function to add numA
    // from ClassA and numB from ClassB
    int add() {
        ClassA objectA;
        return objectA.numA + numB;
    }
};

int main() {
    ClassB objectB;
    cout << "Sum: " << objectB.add();
    return 0;
}
```

3. 클래스 템플릿 프로그램을 실행하고 분석하라. 

(a) 클래스 템플릿을 사용하여 특정 데이터 타입의 객체를 생성하는 방법을 분석

```c++
#include <iostream>
using namespace std;

// Class template
template <typename T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}  

    T getNum() {
        return num;
    }
};

int main() {

    Number<int> numberInt(7);
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}
```

4. 클래스 템플릿 프로그램을 실행하고 분석하라.

```c++
#include <iostream>
using namespace std;

template <typename T>
class Calculator {
   private:
    T num1, num2;

   public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResult() {
        cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
        cout << num1 << " / " << num2 << " = " << divide() << endl;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() { return num1 / num2; }
};

int main() {
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl
         << "Float results:" << endl;
    floatCalc.displayResult();

    return 0;
}
```

5. 여러 타입이 있는 클래스 템플릿 프로그램을 실행시키고 분석하라.

```c++
#include <iostream>
using namespace std;

template <typename T, typename U, typename V = char>
class ClassTemplate {
   private:
    T var1;
    U var2;
    V var3;

   public:
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}  // constructor

    void printVar() {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }
};

int main() {
   
    ClassTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

   
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    return 0;
}
```

6. 앞의 프로그램 3, 4, 5를 비교 분석하라. 

7. 함수 오버라이딩 프로그램을 실행하고 코드를 분석하라.

```c++
#include <iostream>
using namespace std;

class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1, derived2;
    derived1.print();

    // access print() function of the Base class
    derived2.Base::print();

    return 0;
}
```

8. 함수 오버라이딩 프로그램을 실행하고 코드를 분석하라.


```c++
#include <iostream>
using namespace std;

class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;

        // call overridden function
        Base::print();
    }
};

int main() {
    Derived derived1;
    derived1.print();
    return 0;
}
```

9. 함수 오버라이딩 프로그램을 실행하고 코드를 분석하라.

```c++
#include <iostream>
using namespace std;

class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1;
    Base* ptr = &derived1;
    ptr->print();

    return 0;
}
```

10. 앞의 7, 8, 9 프로그램을 비교 분석하라. 
