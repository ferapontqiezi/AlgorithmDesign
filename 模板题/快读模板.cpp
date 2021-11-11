#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;

// long long 快读
inline ll read() { 
    char c = getchar();
    ll x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

// unsigned int 快读
inline int read() {
    int now=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')now=(now<<3)+(now<<1)+c-'0',c=getchar();
    return now;
}