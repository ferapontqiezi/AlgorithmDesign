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
    ll sum = 0;
    for(int i=1;i<=n;i++){cin>>X[i];sum+=X[i]*i;}
    cout<<sum<<endl;
    write((db)sum/10);
    db ans = sum/10;
    write(ans);
    return 0;
}
/*
4
1 2 3 4
*/