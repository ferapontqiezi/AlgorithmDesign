#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline void re(int &x) {
    x = 0;
    bool flag = false;
    char c = getchar();
    while(c < '0' || c > '9'){
        flag = c == '-';
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + (c ^ '0');
        c = getchar();
    }
    if(flag) x = -x;
    return ;
}
int n;
int a[100010][3], dp[100010][3][2];
int main() {
    re(n);
    for(int i = 1; i <= n; i++) {
        re(a[i][0]); re(a[i][1]); re(a[i][2]);
    }
    int ans = 0;
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 3; i++)
            for(int k = 0; k < 2; k++)
                dp[1][i][k] = 0;
        dp[1][j][0] = dp[1][j][1] = a[1][j];
        for(int i = 2; i <= n; i++) {
            dp[i][0][0] = max(dp[i-1][1][1], dp[i-1][2][1]) + a[i][0];
            dp[i][1][0] = dp[i-1][2][1] + a[i][1];
            dp[i][1][1] = dp[i-1][0][0] + a[i][1];
            dp[i][2][1] = max(dp[i-1][1][0], dp[i-1][0][0]) + a[i][2];
        }
        for(int i = 0; i < j; i++)
            ans = max(ans, dp[n][i][0]);
        for(int i = 2; i > j; i--)
            ans = max(ans, dp[n][i][1]);
    }
    printf("%d\n", ans);
    return 0;
}