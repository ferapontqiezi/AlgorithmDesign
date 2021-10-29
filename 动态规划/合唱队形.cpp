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
    while (c != ' ' && c != '\n' && c != EOF) {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * flag;
}


int a[105], f[105], g[105];

int main() {
    int n = 0;
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        f[i] = 1;
        g[i] = 1;
    }
    for (int i = n - 1; i >= 1; -- i) {
        for (int j = i + 1; j <= n; ++ j) {
            if (a[i] > a[j] && f[i] <= f[j] + 1) {
                f[i] = f[j] + 1;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (a[i] > a[j] && g[i] <= g[j] + 1) {
                g[i] = g[j] + 1;
            }
        }
    }
    int maxx = 0;
    for (int i = 1; i <= n; ++ i) {
        int x = f[i] + g[i] - 1;
        maxx = max(x, maxx);
    }
    printf("%d\n", n - maxx);

    return 0;
}