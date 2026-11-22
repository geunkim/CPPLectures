### 1. 2차원 배열 +90도 회전

```cpp
#include <iostream>

using namespace std;

void rotate() {
    char arr1[3][3];
    char arr2[3][3];
    int i, j;
    char alphabet = 'A';

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arr1[i][j] = alphabet;
            alphabet++;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << arr1[i][j];
        }
        cout << endl;
    }

    cout << "==================" << endl;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arr2[j][2 - i] = arr1[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << arr2[i][j];
        }
        cout << endl;
    }

}

int main() {
    rotate();

    return 0;
}
```


### 2. 2차원 배열 상하 반전
```cpp
    cout << "==================" << endl;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arr2[2 - i][j] = arr1[i][j]; //수정 된 부분
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << arr2[i][j];
        }
        cout << endl;
    }
}

```

### 3. 2차원 배열 좌우 반전
```cpp
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arr2[i][2 - j] = arr1[i][j]; //수정 된 부분
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << arr2[i][j];
        }
        cout << endl;
    }
}

```

### 4. 2차원 배열 대각선 반전
```cpp

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arr2[2 - i][2 - j] = arr1[i][j]; //수정 된 부분
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << arr2[i][j];
        }
        cout << endl;
    }
}

```
