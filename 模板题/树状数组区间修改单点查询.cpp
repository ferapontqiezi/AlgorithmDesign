#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x) (x & -x)
typedef long long ll;
const int N = 1e6 + 110;

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
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int l, r, d;
            scanf("%d %d %d", &l, &r, &d);
            add(l, r, d);
        } else {
            int x;
            scanf("%d", &x);
            printf("%lld\n", a[x] + presum(x));
        }
    }

    return 0;
}