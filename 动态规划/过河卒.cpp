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


int dp[22][22];

void preHandle(int xb, int yb, int hx, int hy) {
    int x[9] = {0,1,1,2,2,-1,-1,-2,-2};
    int y[9] = {0,2,-2,1,-1,2,-2,1,-1};
    for (int k = 0; k < 9; ++k) {
        int nx = hx + x[k];
        int ny = hy + y[k];
        if (nx >= 0 && nx <= xb && ny >= 0 && ny <= yb) {
            dp[nx][ny] = -1;
        }
    }
}

int main() {
    memset(dp, 0, sizeof(dp));
    int xb = read(), yb = read(), hx = read(), hy = read() ;
    preHandle(xb, yb, hx, hy);
    if (dp[0][0] == -1) {
        printf("0\n");
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= yb; ++i) {
        if (dp[0][i] == -1) dp[0][i] = 0;
        else dp[0][i] += dp[0][i-1];
    }
    for (int i = 1; i <= xb; ++i) {
        if (dp[i][0] == -1) dp[i][0] = 0;
        else dp[i][0] += dp[i - 1][0];
    }

    for (int i = 1; i <= xb; ++i) {
        for (int j = 1; j <= yb; ++j) {
            if (dp[i][j] == -1) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    printf("%d\n", dp[xb][yb]);

    return 0;
}