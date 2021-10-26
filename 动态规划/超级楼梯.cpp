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


long long dp[50];

int main() {
    memset(dp, 0, sizeof(dp));
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= 40; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n, ans = 0;
    n = read();
    while (n--) {
        int m = read();
        if (m == 1) printf("0\n");
        else printf("%lld\n", dp[m]);
    }

    return 0;
}