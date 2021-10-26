#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int dp[5005], a[5005];
long long cnt[5005];

int main() {
    int n, dpexp = 0;
    long long count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[i] < a[j] && dp[i] <= dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        dpexp = max(dpexp, dp[i]);
        if (dp[i] == 1) {
            cnt[i] = 1;
            continue;
        }
        for (int j = 1; j < i; ++j) {
            if (a[i] < a[j] && dp[i] == dp[j] + 1) {
                cnt[i] += cnt[j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == dpexp) {
            count += cnt[i];
        }
    }

    printf("%d %lld\n", dpexp, count);

    return 0;
}