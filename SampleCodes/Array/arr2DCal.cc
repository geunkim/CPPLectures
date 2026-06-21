```cpp
#include <iostream>

using namespace std;

double A[3][3] = { {0, 1, 2},
                    {1, 2, 3},
                    {9, 8, 7} };
double B[3][3] = { {1, 2, 3},
                {3, 2, 1},
                {5, 5, 5} };
double C[3][3] = { 0 };

void 덧셈()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void 뺄셈()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void 곱셈()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] += A[i][j] * B[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void 나눗셈()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] / B[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    덧셈();
    뺄셈();
    곱셈();
    나눗셈();

    return 0;
}

```
