#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAXN 100000


// C++ Version
int t1[MAXN], t2[MAXN], n;

inline int lowbit(int x) { return x & (-x); }

void add(int k, int v) {
  int v1 = k * v;
  while (k <= n) {
    t1[k] += v, t2[k] += v1;
    k += lowbit(k);
  }
}

int getsum(int *t, int k) {
  int ret = 0;
  while (k) {
    ret += t[k];
    k -= lowbit(k);
  }
  return ret;
}

void add1(int l, int r, int v) {
  add(l, v), add(r + 1, -v);  // 将区间加差分为两个前缀加
}

long long getsum1(int l, int r) {
  return (r + 1ll) * getsum(t1, r) - 1ll * l * getsum(t1, l - 1) - (getsum(t2, r) - getsum(t2, l - 1));
}

// C++ Version
// O(n)建树
void init() {
    for (int i = 1; i <= n; ++i) {
        tree[i] += a[i];
        int j = i + lowbit(i);
        if (j <= n) tree[j] += tree[i];
    }
}