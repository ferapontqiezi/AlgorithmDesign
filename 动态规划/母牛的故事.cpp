#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<algorithm>
using namespace std;

inline int read() {
    int res = 0, flag = 1;
    char c = getchar();
    if (c == '-') {
        flag = -1;
        c = getchar();
    }
    while (c != ' ' && c != '\n') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * flag;
}


int a[20], b[20], c[20];

int main() {
    //freopen("E:/AlgorithmDesign/2.in", "r", stdin);
    memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b)), memset(c, 0, sizeof(c));
    a[1] = 1, b[1] = 2, c[1] = 3;
    for (int i = 2; i <= 18; ++i) {
        for (int j = 1; j <= 3; ++j) {
            int rem = j % 3;
            if (rem == 1) a[i] = a[i - 1] + c[i - 1];
            else if (rem == 2) b[i] = b[i - 1] + a[i];
            else c[i] = c[i - 1] + b[i];
        }
    }

    int n, ans = 0;
    n = read();
    while (n) {
        int quo = n / 3, rem = n % 3;
        if (rem == 1) printf("%d\n", a[quo+1]);
        else if (rem == 2) printf("%d\n", b[quo+1]);
        else printf("%d\n", c[quo]);
        n = read();
    }

    return 0;
}