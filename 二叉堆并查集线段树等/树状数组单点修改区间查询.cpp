#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x) (x&-x)
typedef long long ll;
const int N = 1e6 + 110;

ll tree[N], n, m;
void update(int x, int d) {
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
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
        update(i, x);
    }

    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x, d;
            scanf("%d %d", &x, &d);
            update(x, d);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", presum(r) - presum(l - 1));
        }
    }

    return 0;
}