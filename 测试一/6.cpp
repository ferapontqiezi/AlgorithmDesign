//AC
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;
int f[2][N][N];
int t[50][5];
int n;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &t[i][1], &t[i][2], &t[i][3], &t[i][4]);
    memset(f, 0x3f, sizeof f);
    f[0][0][0] = 0;
    for (int i = 1; i <= n; ++i){
        int u = i % 2;
        int v = (i + 1) % 2;
        for(int j = 0; j <= i * 10; ++ j)
            for (int k = 0; k <= i * 10; ++k){
                f[u][j][k] = INF;
                if (j - t[i][1] >= 0) f[u][j][k] = min(f[u][j][k], f[v][j - t[i][1]][k]);
                if (k - t[i][1] >= 0) f[u][j][k] = min(f[u][j][k], f[v][j][k - t[i][1]]);
                if (j - t[i][2] >= 0 && k - t[i][2] >= 0) f[u][j][k] = min(f[u][j][k], f[v][j - t[i][2]][k - t[i][2]]);
                if (j - t[i][3] >= 0) f[u][j][k] = min(f[u][j][k], f[v][j - t[i][3]][k] + t[i][3]);
                if (k - t[i][3] >= 0) f[u][j][k] = min(f[u][j][k], f[v][j][k - t[i][3]] + t[i][3]);
                if (j - t[i][4] >= 0 && k - t[i][4] >= 0) f[u][j][k] = min(f[u][j][k], f[v][j - t[i][4]][k - t[i][4]] + t[i][4]);
            }
    }
    int ans = INF;
    for (int i = 0; i <= n * 10; ++i)
        for (int j = 0; j <= n * 10; ++j)
            ans = min(ans, max(f[n % 2][i][j], max(i, j)));
    printf("%d", ans);
    return 0;
}