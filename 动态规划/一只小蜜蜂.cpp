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


long long dp[100][100];

int main() {
    //freopen("E:/AlgorithmDesign/2.in", "r", stdin);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 98; ++i) {
        dp[i][i + 1] = 1;
    }
    for (int i = 1; i <= 97; ++i) {
        dp[i][i + 2] = 2;
    }
    for (int i = 1; i <= 96; ++i) {
        for (int j = i + 3; j <= 99; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i][j - 2];
        }
    }
    int n, ans = 0;
    n = read();
    while (n--) {
        int a = read();
        int b = read();

        printf("%lld\n", dp[a][b]);
    }

    return 0;
}