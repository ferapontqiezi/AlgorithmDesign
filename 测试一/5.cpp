//80
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
using namespace std;
#define ll long long

const int N = 100007;
ll n, d;
ll h[N];
ll dp[N];
ll ans = 0;

int main() {
	scanf("%lld%lld", &n, &d);
	for(int i = 1; i <= n; i ++){
        scanf("%lld", &h[i]);
	}
    dp[1] = 1;
    for(int i = 2; i <= n; i ++){
        dp[i] = 1;
        for(int j = 1; j < i; j ++){
            int dis = abs(h[i] - h[j]);
            if(dis >= d)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for(int i = 1; i <= n; i ++){
        ans = max(ans, dp[i]);
    }
	printf("%lld", ans);
	return 0;
}
/*
5 2
1 3 6 7 4
*/