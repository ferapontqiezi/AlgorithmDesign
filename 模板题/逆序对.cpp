#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&-x)
typedef long long ll;
const int N = 1e6 + 110;

typedef struct array{
    ll val;
    ll pos;
    ll rank;
}arr;
arr a[N];
bool cmp1(arr a, arr b){
    if(a.val == b.val) return a.pos < b.pos;
    return a.val < b.val;
};
bool cmp2(arr a, arr b){
    return a.pos < b.pos;
};

ll b[N], n, m;
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
    scanf("%lld", &n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].val);
        a[i].pos = i;
    }
    sort(a+1, a+n+1, cmp1);
    for (int i = 1; i <= n; i++) {
        a[i].rank = i;
    }
    sort(a+1, a+n+1, cmp2);

    for (int i = 1; i <= n; i++) {
        update(a[i].rank, 1);   
        ans += getsum(n) - getsum(a[i].rank);
    }
    printf("%lld", ans);

    return 0;
}

/*
6
5 4 2 6 3 1
*/