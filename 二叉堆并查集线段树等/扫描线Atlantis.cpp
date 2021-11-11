#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#define N 1000007
#define M 100007
#define lson (x << 1)
#define rson (x << 1 | 1)
typedef long long ll;
typedef double db;
using namespace std;

inline void write(db x) {
    printf("%.2f\n", x);
}

ll n, cnt = 0;
ll x1, y1, x2, y2, X[N << 1];

struct ScanLine {
	ll l, r, h;
	ll mark;    //  mark用于保存权值 (1 / -1)
	bool operator < (const ScanLine &a) const {
		return h < a.h;
	}
} line[N << 1];

struct SegTree {
	ll l, r, len, sum;
//  sum: 被完全覆盖的次数；
//  len: 区间内被截的长度。
} tree[N << 2];

void build(ll x, ll l, ll r) {
	tree[x].l = l, tree[x].r = r;
	tree[x].len = 0;
	tree[x].sum = 0;
	if(l == r) return ;
	ll mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
void pushup(ll x) {
	ll l = tree[x].l, r = tree[x].r;
	if(tree[x].sum)
		tree[x].len = X[r + 1] - X[l];     
	else
		tree[x].len = tree[lson].len + tree[rson].len;
}
void update(ll x, ll L, ll R, ll c){
	ll l = tree[x].l, r = tree[x].r;
    if(L >= X[r + 1] || X[l] >= R) return ;
    if(L <= X[l] && X[r + 1] <= R) {
		tree[x].sum += c;
		pushup(x);
		return ;
	}
    ll mid = (l + r) >> 1;
    update(lson, L, R, c);
    update(rson, L, R, c);
    pushup(x);
}

int main(){
    scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
        db a1, b1, a2, b2;
		scanf("%f %f %f %f", &a1, &b1, &a2, &b2);
        x1 = ll(a1 * 100), y1 = ll(b1 * 100), x2 = ll(a2 * 100), y2 = ll(b2 * 100);
		X[2 * i - 1] = x1, X[2 * i] = x2;
		line[2 * i - 1] = (ScanLine) {x1, x2, y1, 1};
		line[2 * i] = (ScanLine) {x1, x2, y2, -1};
	}
	n <<= 1;
	sort(line + 1, line + n + 1);
	sort(X + 1, X + n + 1);
	ll tot = unique(X + 1, X + n + 1) - X - 1;
	build(1, 1, tot - 1);
	ll ans = 0;
	for(ll i = 1; i < n; i++) {
		update(1, line[i].l, line[i].r, line[i].mark);
		ans += tree[1].len * (line[i + 1].h - line[i].h);
	}
    db res = ans / 10000;
	write(res);
    return 0;
}
/*
2
10 10 20 20
15 15 25 25.5
*/