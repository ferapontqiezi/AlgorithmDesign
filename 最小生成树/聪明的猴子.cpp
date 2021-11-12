// kruskal算法，适合稀疏图
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 1007
#define maxm 1000007
using namespace std;

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

struct Edge {
    int u, v; // from, to
    double w; // wieght
}edge[maxm];
inline bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
int root[maxn], n, m, cnt;
int monkey[maxn], x[maxn], y[maxn], num;
double ans;

inline int find(int x) {
    while (x != root[x]) x = root[x] = root[root[x]];
    return x;
}

void init() {
    n = read();
    for (int i = 1; i <= n; i++) {
        monkey[i] = read();
    }
    m = read();
    for (int i = 0; i < m; i++) {
        root[i] = i;
        x[i] = read(), y[i] = read();
    }
    for (int u = 0; u < m - 1; u++) {
        for (int v = u + 1; v < m; v++) {
            edge[num].u = u, edge[num].v = v;
            edge[num].w = sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
            num++;
        }
    }
}

int kruskal() {
    int result = 0;
    sort(edge, edge + num, cmp);
    for (int i = 0; i < num; i++) {
        int root_u = find(edge[i].u);
        int root_v = find(edge[i].v);
        if (root_u == root_v)
            continue;
        ans = edge[i].w;
        root[root_v] = root_u;
        cnt++;
        if (cnt == m - 1)
            break;
    }
    for (int i = 1; i <= n; i++) {
        if (monkey[i] >= ans) result++;
    }
    return result;
}

int main() {
    init();
    int res = kruskal();
    printf("%d", res);
    return 0;
}
/*
4
1 2 3 4
6
0 0
1 0
1 2
-1 -1
-2 0
2 2
*/