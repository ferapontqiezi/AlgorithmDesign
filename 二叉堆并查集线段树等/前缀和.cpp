#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;
#define lowbit(x) (x & -x)
typedef long long ll;
const int N = 1e5 + 777;

ll n, m;
//区间修改，区间查询
ll a[N];
//维护a[i]的前缀和
ll b[N];
//维护a[i]*i的前缀和
ll c[N];

void update_1(ll x, ll d) {
    while (x <= n) {
        b[x] += d;
        x += lowbit(x);
    }
}
ll getsum_1(ll x){
    ll ans = 0;
    while (x > 0) {
        ans += b[x];
        x -= lowbit(x);
    }
    return ans;
}

void update_2(ll x, ll d) {
    while (x <= n) {
        c[x] += d;
        x += lowbit(x);
    }
}
ll getsum_2(ll x){
    ll ans = 0;
    while (x > 0) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    //freopen("../test/10.in", "r", stdin);
    //freopen("../test/10out.out", "w", stdout);
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        update_1(i, a[i]);
        update_2(i, a[i] * i);
    }
    while (m--) {
        string op;
        cin >> op;
        
        if (op == "Modify") {
            ll l, d;
            scanf("%lld %lld", &l, &d);
            update_1(l, d - a[l]);
            update_2(l, l * d - l * a[l]);
            a[l] = d;
        } else {
            ll x;
            scanf("%lld", &x);
            ll ans = getsum_1(x) * (x + 1) - getsum_2(x);
            printf("%lld\n", ans);
        }
    }

    return 0;
}