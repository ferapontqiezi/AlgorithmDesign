#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    int target;
    cin >> target;
    vector<int> dp(target + 1);
    int n;
    cin >> n;
    vector<int> coins(n), w(n);
    for(int i = 0; i < n; ++ i){
        cin >> coins[i] >> w[i];
    }

    for(int j = 0 ; j < n; j ++){
        int coin = coins[j], wt = w[j];
        for(int i = target; i >= coin; i --){
            dp[i] = max(dp[i], dp[i - coin] + coin * wt);
        }
    }
    int res = dp[target];
    cout << res << endl;
    return 0;
}