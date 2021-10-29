#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


const int MOD = 100000000, N = 13, M = 1 << N;
int m, n, res = 0;
int a[N][N], dp[N][M], col[M], map[M];

inline int judge1(int x){ // 返回是否有相邻的1
    return x & (x << 1);
}

inline int judge2(int i, int j){ // 返回第i行是否
    return map[i] & col[j];
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
            if(a[i][j] == 0)
                map[i] += (1 << (j - 1));
        }
    }
    int k = 0;
    for(int i = 0; i < (1 << m); i ++){
        if(!judge1(i))
            col[k++] = i;
    }
    for(int j = 0; j < k; j ++){
        if(!judge2(1, j))
            dp[1][j] = 1;
    }
    for(int i = 2; i <= n; i ++){
        for(int j = 0; j < k; j ++){
            if(judge2(i, j))
                continue;
            for(int t = 0; t < k; t ++){
                if(judge2(i-1, t))
                    continue;
                if(!(col[j] & col[t]))
                    dp[i][j] += dp[i-1][t];
            }
        }
    }

    for(int i = 0; i < k; i ++) 
        res = (res + dp[n][i]) % MOD;
    cout << res << endl;
    return 0;
}
/*
2 3
1 1 1
0 1 0
*/