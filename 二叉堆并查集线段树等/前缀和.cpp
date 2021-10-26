#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;
#define lowbit(x) (x & -x)
typedef long long ll;
const int N = 1e5 + 777;

ll tree[N], a[N], n, m;

void update(int x, int d) {
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}
void add(int l, int r, int v){
    update(l, v);
    update(r + 1, -v);
}

ll presum(int x) {
    ll ans = 0;

    while (x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }

    return ans;
}

int main() {
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        a[i] = x;
    }
    while (m--) {
        string op;
        cin >> op;
        
        if (op == "Modify") {
            int x, d;
            scanf("%d %d", &x, &d);
            update(x, d);
        } else {
            int x;
            scanf("%d", &x);
            printf("%lld\n", a[x] + presum(x));
        }
    }

    return 0;
}