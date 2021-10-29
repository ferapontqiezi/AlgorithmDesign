#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int target;
    cin >> target;
    vector<int> dp(target + 1);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i){
        int coin;
        cin >> coin;
        for(int i = target; i >= coin; -- i){
            dp[i] = max(dp[i], dp[i - coin] + coin);
        }
    }
    int res = target - dp[target];
    cout << res << endl;
    return 0;
}