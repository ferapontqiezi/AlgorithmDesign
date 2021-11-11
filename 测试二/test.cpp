#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#define N 377777
#define M 100000007
typedef unsigned int us;
using namespace std;

inline us read() { 
    char c = getchar();
    us x = 0;
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x;
}
inline void write(us x) {
    printf("%d\n", x);
}
const us MOD = 2021;
us mod(us x){
    return (x % MOD + MOD) % MOD;
}

us a[N];
us u1 = 0xaf128e66, u2 = 0x3365b701;

int main(){
    us n = read(), m = read();
    for(us i = 1; i <= n; i ++){
        a[i] = i;
    }
    while(m--){
        us l = read(), r = read(), ans = 0;
        for(us i = l; i <= r; i++){
            ans += mod(a[i]);
        }
        write(ans);
        for(us i = l; i <= r; i++){
            a[i] ^= u2;
        }
    }

    return 0;
}