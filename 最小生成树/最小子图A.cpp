// kruskal算法，适合稀疏图
#include<bits/stdc++.h>
#define maxn 10007
#define maxm 1000007
using namespace std;

inline int read(){
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c<= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x*f;
}

struct Edge{
	int u, v, w; //from, to, weight
}edge[maxm];
inline bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int root[maxn], n, m, ans, cnt;

inline int find(int x){
    while(x != root[x]) x = root[x] = root[root[x]];
    return x;
}

void init(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        root[i] = i;
    }
    for(int i = 0; i < m; i++){
        edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
    }
}

int kruskal(){
    sort(edge, edge + m, cmp);
    for(int i = 0; i < m; i++){
        int root_u = find(edge[i].u);
        int root_v = find(edge[i].v);
        if(root_u == root_v)
            continue;
        ans += edge[i].w;
        root[root_v] = root_u;
        cnt++;
        if(cnt == n - 1)
            break;
    }
    return ans;
}

int main(){
    //freopen("../1.in", "r", stdin);
    init();
    int res = kruskal();
    printf("%d", res);
    return 0;
}
