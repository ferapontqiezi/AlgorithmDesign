#include<iostream>
#include <algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];//用四个dp数组存放最大值	
int n, m;
int a[1010][1010];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    memset(dp3, 0, sizeof(dp3));
    memset(dp4, 0, sizeof(dp4));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp4[i][j] = a[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
        }
    }
    int x = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++)
        {
            x = max(x, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
            x = max(x, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
        }
    }
    printf("%d\n", x);
    return 0;
}