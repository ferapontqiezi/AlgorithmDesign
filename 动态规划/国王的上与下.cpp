#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;

ll dp[24][2];

ll comb(int a, int b){
    if(a == 0 || a == b) return 1;
    return comb(a-1, b-1) + comb(a, b-1);
}

void init(){
    dp[0][0] = 1, dp[0][1] = 1;
    dp[1][0] = 1, dp[1][1] = 1;
    for(int k = 2; k <= 20; k ++){
        ll tmp = 0;
        for(int i = 0; i < k; i ++){
            int j = k - i - 1;
            tmp += dp[i][0] * dp[j][1] * comb(i, k-1);
        }
        dp[k][0] = dp[k][1] = tmp >> 1;
    }
}

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        int p, n;
        cin >> p >> n;
        ll res = 1;
        if(n != 1)
            res = (dp[n][0] + dp[n][1]);
        cout << p << " " << res << endl;
    }
    return 0;
}
/*
4
1 1
2 3
3 4
4 20
*/