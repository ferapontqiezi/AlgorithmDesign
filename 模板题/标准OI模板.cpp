#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#define N 77777777
#define M 100000007
typedef long long ll;
using namespace std;

inline int read() { 
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void write(int x) {
    printf("%d", x);
}
const int MOD = 998244353;
int mod(int x){
    return (x % MOD + MOD) % MOD;
}

int a[N];

int main(){
    for(int i = 1; i <= n; i ++){
        a[i] = read();
    }
    return 0;
}