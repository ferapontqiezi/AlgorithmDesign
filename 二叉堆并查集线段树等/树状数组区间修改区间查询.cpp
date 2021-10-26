#include <bits/stdc++.h>
using namespace std;
const int _ = 1000003;
typedef long long ll;
int a[_], n, m;
ll t1[_], t2[_];
void add(int x, int k) {
    for (int i = x; i <= n; i += (i & -i))
        t1[i] += k;

    for (int i = x; i <= n; i += (i & -i))
        t2[i] += 1ll * x * k;
}
ll qry(int x) {
    ll res = 0;

    for (int i = x; i; i -= (i & -i))
        res += t1[i] * (x + 1);

    for (int i = x; i; i -= (i & -i))
        res -= t2[i];

    return res;
}
int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (int i = 1; i <= n; i++)
        t1[i] = a[i] - a[i - (i & -i)];

    for (int i = n; i; i--)
        a[i] -= a[i - 1];

    for (int i = 1; i <= n; i++)
        t2[i] = 1ll * i * a[i] + t2[i - 1];

    for (int i = n; i; i--)
        t2[i] -= t2[i - (i & -i)];

    while (m--) {
        int opt, l, r;
        scanf("%d%d%d", &opt, &l, &r);

        if (opt == 1) {
            int k;
            scanf("%d", &k);
            add(l, k);
            add(r + 1, -k);
        } else
            printf("%lld\n", qry(r) - qry(l - 1));
    }

    return 0;
}