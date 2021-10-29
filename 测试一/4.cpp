//AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int n;
ll dp[1007][7];
const int MOD = 999999997;

int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++){
        dp[i][0] = 1;
		dp[i][1] = (dp[i-1][1] * 2 + 1) % MOD;
		dp[i][2] = (dp[i-1][2] + 1) % MOD;
		dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][3] * 2) % MOD;
		dp[i][4] = (dp[i-1][1] + dp[i-1][4] * 2) % MOD;
		dp[i][5] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5] * 2) % MOD;
	}
	printf("%lld", dp[n][5]);
	return 0;
}
