#include<cstdio>
#include<algorithm>
using namespace std;

int nx, ny, ex, ey, n, f[1010];
int a[10005], b[10005], c[10005];
int cnt = 0, co[1000005], v[1000005];//尽可能开大，不要把空间开爆了

int main() {
	scanf("%d:%d %d:%d%d", &nx, &ny, &ex, &ey, &n);
	int t = (ex * 60 + ey) - (nx * 60 + ny);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		if(!c[i]) c[i] = 999999;
        int at = a[i], bt = b[i], ct = c[i];
        for(int j = 1; j <= ct; j <<= 1) {
            co[++cnt] = j*at, v[cnt] = j*bt;
            ct -= j;
        }
        if(c) co[++cnt] = at*ct, v[cnt] = bt*ct;
        //二进制优化,拆分 
	}
	for(int i = 1; i <= cnt; ++ i) {//考虑每个拆出来的物品
		for(int j = t; j >= co[i]; -- j)//01背包板子
			f[j] = max(f[j], f[j - co[i]] + v[i]);
	}

	printf("%d", f[t]);
	return 0;
} 