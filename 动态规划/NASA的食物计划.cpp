#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    int vtarget, mtarget;
    cin >> vtarget >> mtarget;
    vector<vector<int> > dp(vtarget + 1, vector<int> (mtarget + 1));
    int n;
    cin >> n;
    vector<int> v(n), m(n), c(n);
    for(int i = 0; i < n; ++ i){
        cin >> v[i] >> m[i] >> c[i];
    }

    for(int j = 0 ; j < n; j ++){
        int vl = v[j], ms = m[j], ka = c[j];
        for(int i = vtarget; i >= vl; i --){
            for(int k = mtarget; k >= ms; k --)
            dp[i][k] = max(dp[i][k], dp[i - vl][k - ms] + ka);
        }
    }
    int res = dp[vtarget][mtarget];
    cout << res << endl;
    return 0;
}