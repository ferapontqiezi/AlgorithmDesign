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
    int u, v; //from, to
    double w; //weight
}edge[maxm];
inline bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int root[maxn], n, m, cnt;
int all, num;
bool in[maxn][maxn];
double x[maxn], y[maxn], ans;

inline int find(int x) {
    while (x != root[x]) x = root[x] = root[root[x]];
    return x;
}

double kruskal() {
    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; i++) {
        int root_u = find(edge[i].u);
        int root_v = find(edge[i].v);
        if (root_u == root_v)
            continue;
        // ans += edge[i].w;
        root[root_v] = root_u;
        cnt++;
        if (cnt == n - 1)
            break;
    }

    sort(edge + m, edge + num, cmp);
    for (int i = m; i < num; i++) {
        int root_u = find(edge[i].u);
        int root_v = find(edge[i].v);
        if (root_u == root_v)
            continue;
        ans += edge[i].w;
        root[root_v] = root_u;
        cnt++;
        if (cnt == n - 1)
            break;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    all = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        edge[num].u = u, edge[num].v = v;
        edge[num].w = sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
        in[u][v] = true, in[v][u] = true;
        num++;
    }
    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (in[u][v] == true)
                continue;
            edge[num].u = u, edge[num].v = v;
            edge[num].w = sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
            in[u][v] = true, in[v][u] = true;
            num++;
        }
    }
    double res = kruskal();
    printf("%.2f\n", res);
    return 0;
}
/*
4 1
1 1
3 1
2 3
4 3
1 4
*/