#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define N 105
typedef long long ll;
using namespace std;

inline ll read() {  //快读
    char c = getchar();
    ll x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

struct edge{
    ll to;    //第i条边通向的节点
    ll apple; //第i条边的苹果数
    ll next;  //第i条边的下一条边
};
edge e[N<<1];
ll dp[N][N];
ll head[N], tot = 1;
ll n, q;

inline void add(ll u, ll v, ll w) {
    //邻接表存数
    e[tot].to = v;
    e[tot].apple = w;
    e[tot].next = head[u];
    head[u] = tot;
    tot++;
}

void dfs(ll u, ll father){
    // 深搜遍历树
    // f[i][j]=max(f[i][j],f[left][j−1]+e[left].apple+f[right][k−j−1]+e[right].apple
    ll son[N] = {0}, cnt = 0; //son[1]表示u的左儿子在第几条边,son[2]表示u的右儿子在第几条边
    bool flag = false;
    for(ll v = head[u]; v; v = e[v].next){
        if(e[v].to != father){
            flag = true; // 非叶子节点
            son[++cnt] = v;
            dfs(e[v].to, u);
        }
    }
    if(!flag) return ;
    for(ll i = 1; i <= q; i++){
        for(ll j = 0; j <= i; j++){
            ll t = 0;
            if(j - 1 >= 0) t += e[son[1]].apple;  //j-1>=0表示分配给了左儿子与i节点的一条相连的树枝
        	if(i - j - 1 >= 0) t += e[son[2]].apple;//i-j-1>=0表示分配给了右儿子与i节点的一条相连的树枝
        	if(j != 0)
         		dp[u][i]=max(dp[u][i], dp[e[son[1]].to][j-1] + t + dp[e[son[2]].to][i-j-1]);  //j!=0，表示两个儿子都分配了
         	else //j==0，表示只分配给了右儿子树枝
         		dp[u][i]=max(dp[u][i], dp[e[son[2]].to][i-j-1] + t);
        }
    }
}

int main(){
    n = read(), q = read();
    for(ll i = 1; i < n; i++) {
        ll u = read(), v = read(), w = read();
        add(u,v,w), add(v,u,w);
    }
    dfs(1, 0);
    printf("%d", dp[1][q]); //因为最终我们要求的苹果数是以1为根节点的子树中保留q根树枝的最大苹果数，所以最终的结果等于dp[1][q]
    return 0;
}