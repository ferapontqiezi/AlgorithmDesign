//AC
#include <cstring>
#include <iostream>

using namespace std;

class Matrix {
public:
    int a[6][6];
    Matrix() {
       memset(a, 0, sizeof(a));
    }
};

//矩阵乘法
Matrix operator*(Matrix A, Matrix B) {
    Matrix C = Matrix();
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                C.a[i][j] += A.a[i][k] * B.a[k][j];
            }
            C.a[i][j] = C.a[i][j] % 997;
        }
    }
    return C;
}

int main() {
    int N;
    cin >> N;
    int ans_3 = 1, ans_2 = 5, ans_1 = 11;
    int e_2 = 0, e_1 = 1;
    int f_1 = 1;
    Matrix I;
    for (int i = 0; i < 6; i++)
        I.a[i][i] = 1;
    Matrix base;
    base.a[0][1] = 1;
    base.a[1][2] = 1;
    base.a[2][0] = 2;
    base.a[2][1] = 4;
    base.a[2][2] = 1;
    base.a[2][4] = 1;
    base.a[2][5] = 2;
    base.a[3][4] = 1;
    base.a[4][0] = 1;
    base.a[4][3] = 1;
    base.a[5][0] = 1;
    base.a[5][5] = 1;
    N = N - 3;
    while (N) {
        if (N & 1)
        I = I * base;
        base = base * base;
        N >>= 1;
    }
    ans_1 = (I.a[2][0] * ans_3 + I.a[2][1] * ans_2 + I.a[2][2] * ans_1 +
            I.a[2][3] * e_2 + I.a[2][4] * e_1 + I.a[2][5] * f_1) %
            997;

    cout << ans_1;
    return 0;
}