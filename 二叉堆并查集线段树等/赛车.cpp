#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&-x)
typedef long long ll;
const int N = 1e7 + 110;

typedef struct array{
    ll start;
    ll end;
    ll rank;
}arr;
arr a[N];
bool cmp1(arr a, arr b){
    if(a.end == b.end) return a.start > b.start;
    return a.end < b.end;
    //return a.end > b.end;
};
bool cmp2(arr a, arr b){
    return a.start < b.start;
};

ll b[N], n, t;
void update(ll x, ll d) {
    while (x <= n) {
        b[x] += d;
        x += lowbit(x);
    }
}

ll getsum(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans += b[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%lld %lld", &n, &t);

    for (int i = 1; i <= n; i++) {
        ll v = 0;
        scanf("%lld %lld", &a[i].start, &v);
        a[i].end = a[i].start + v * t;
    }
    sort(a+1, a+n+1, cmp1);
    for (int i = 1; i <= n; i++) {
        a[i].rank = i;
    }
    sort(a+1, a+n+1, cmp2);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        update(a[i].rank, 1);   
        ans += getsum(n) - getsum(a[i].rank);
        //ans += getsum(a[i].rank - 1);
    }
    printf("%lld", ans);

    return 0;
}

/*
5 2
1 5
3 4
5 3
7 5
9 1
*/