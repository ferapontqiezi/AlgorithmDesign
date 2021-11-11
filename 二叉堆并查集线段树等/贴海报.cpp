#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#define N 10000007
#define M 100007
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

int n, m, ans, a[M], b[M];
bool flag, colored[N << 2];

inline int ls(int x){return x << 1;}
inline int rs(int x){return x << 1 | 1;}
void pushup(int rt){
    colored[rt] = colored[ls(rt)] && colored[rs(rt)];
}
void build(int l, int r, int rt){
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, ls(rt));
    build(mid + 1, r, rs(rt));
    pushup(rt);
}
void update(int l, int r, int L, int R, int rt){
    if(colored[rt]) return ;
    if(L <= l && r <= R){
        flag = 1, colored[rt] = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) update(l, mid, L, R, ls(rt));
    if(mid < R) update(mid+1, r, L, R, rs(rt));
    pushup(rt);
}

int main(){
    //freopen("../1.in", "r", stdin);
    n = read(), m = read();
    for(int i = 1; i <= m; i ++) {
        a[i] = read(), b[i] = read();
    }
    for(int i = m; i > 0; i --) {
        flag = 0;
        update(1, n, a[i], b[i], 1);
        if(flag) ans++;
    }
    write(ans);
    return 0;
}