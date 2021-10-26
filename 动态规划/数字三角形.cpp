#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

inline int read() {
    int res = 0, flag = 1;
    char c = getchar();
    if(c == '-') {
        flag = -1;
        c = getchar();
    }
    while(c != ' ' && c != '\n') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * flag;
}


int a[1002][1002];

int main() {
    //freopen("1.in", "r", stdin);
    memset(a, 0, sizeof(a));
    int n, ans = 0;
    n = read();
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= i; ++ j) {
            a[i][j] = read();
            a[i][j] += max(a[i-1][j-1], a[i-1][j]);
        }
    }
    for(int i = n; i > 0; -- i) {
        ans = max(ans, a[n][i]);
    }
    printf("%d", ans);
    return 0;
}