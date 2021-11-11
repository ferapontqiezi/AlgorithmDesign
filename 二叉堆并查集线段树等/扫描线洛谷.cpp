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

inline ll read() { 
    char c = getchar();
    ll x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void write(db x) {
    printf("%.2f\n", x);
}
const ll MOD = 998244353;
ll mod(ll x){
    return (x % MOD + MOD) % MOD;
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
	ll l, r, len;
	ll sum;
//  sum: 被完全覆盖的次数；
//  len: 区间内被截的长度。
} tree[N << 2];

void build(ll x, ll l, ll r) {
//  我觉得最不容易写错的一种建树方法
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
	if(tree[x].sum /* 也就是说被覆盖过 */ )
		tree[x].len = X[r + 1] - X[l];
//      更新长度        
	else
		tree[x].len = tree[lson].len + tree[rson].len;
//      合并儿子信息
}
void update(ll x, ll L, ll R, ll c){
	ll l = tree[x].l, r = tree[x].r;
//  注意，l、r和L、R的意义完全不同
//  l、r表示这个节点管辖的下标范围
//  而L、R则表示需要修改的真实区间
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
    // freopen("../1.in", "r", stdin);
    scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
        // db a1, b1, a2, b2;
		// scanf("%f %f %f %f", &a1, &b1, &a2, &b2);
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		X[2 * i - 1] = x1, X[2 * i] = x2;
		line[2 * i - 1] = (ScanLine) {x1, x2, y1, 1};
		line[2 * i] = (ScanLine) {x1, x2, y2, -1};
	}
	n <<= 1;
//  直接把 n <<= 1 方便操作
	sort(line + 1, line + n + 1);
	sort(X + 1, X + n + 1);
	ll tot = unique(X + 1, X + n + 1) - X - 1;
//  去重最简单的方法：使用unique！（在<algorithm>库中）
	build(1, 1, tot - 1);
//  为什么是 tot - 1 ：
//  因为右端点的对应关系已经被篡改了嘛…
//  [1, tot - 1]描述的就是[X[1], X[tot]]
    ll ans = 0;
	// db ans = 0.0;
	for(ll i = 1; i < n; i++) {
		update(1, line[i].l, line[i].r, line[i].mark);
//      先把扫描线信息导入线段树
		ans += tree[1].len * (line[i + 1].h - line[i].h);
//      然后统计面积
	}
    printf("%lld", ans);
	// write(ans);
    return 0;
}
/*
2
100 100 200 200
150 150 250 255
*/