#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 4002, MAXN = 0xfffff, MINN = 0;
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

//状态转移方程：fmax[i][j] = max(fmax[i][j], fmax[i][k] + fmax[k][j] + t(i, j)) i <= k <= j-1;
//改进后的状态转移方程：fmax[i][j] = max(fmax[i+1][j], fmax[i][j-1]) + t(i, j)
int stones[N], fmin[N][N], fmax[N][N], sum[N];
int main(){
    int n = read();
    for(int i = 1; i <= n; ++ i) stones[i] = read(), stones[i+n] = stones[i];
    for(int i = 1; i <= 2*n; ++ i) sum[i] = sum[i-1] + stones[i];
    for(int r = 2; r <= n; ++ r){
        for(int i = 1; i <= 2*n-r+1; ++ i){
            int j = i + r - 1;
            fmin[i][j] = MAXN, fmax[i][j] = MINN;
/*             for(int k = i; k < j; ++ k){
                fmin[i][j] = min(fmin[i][k] + fmin[k+1][j] + sum[j] - sum[i-1], fmin[i][j]);
                fmax[i][j] = max(fmax[i][k] + fmax[k+1][j] + sum[j] - sum[i-1], fmax[i][j]);
            } */
            fmax[i][j] = max(fmax[i+1][j], fmax[i][j-1]) + sum[j] - sum[i-1];
        }
    }
    int ansmin = MAXN, ansmax = MINN;
    for(int i = 1; i <= n; ++ i){
        //ansmin = min(ansmin, fmin[i][i+n-1]);
        ansmax = max(ansmax, fmax[i][i+n-1]);
    }
    //printf("%d\n%d", ansmin, ansmax);
    printf("%d", ansmax);
    return 0;
}
/*
4
4 4 5 9
*/