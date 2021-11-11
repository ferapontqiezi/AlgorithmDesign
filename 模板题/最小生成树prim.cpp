#include<bits/stdc++.h>
using namespace std;

#define inf 123456789
#define maxn 5005
#define maxm 200005

inline int read(){
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c<= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x*f;
}

struct edge{
	int v, w, next;
    bool operator <(const edge &e1, const edge &e2){
        // 大顶堆，top需要返回最小元素
        return e1.w > e2.w;
    }
}e[maxm << 1];
//注意是无向图，开两倍数组
int head[maxn], dis[maxn], cnt, n, m, tot, now=1, ans;
bool vis[maxn];
proiority_queue<edge> pq; 

void add(int u,int v,int w){
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void init(){
    n = read(), m = read();
    for(int i = 1,u,v,w; i <= m; ++i){
        u = read(), v = read(), w = read();
        add(u,v,w), add(v,u,w);
    }
    for(int i = 2; i <= n; ++i){
		dis[i] = inf;
	}
	for(int i = head[1]; i; i = e[i].next){
		dis[e[i].v] = min(dis[e[i].v], e[i].w);
	}
}

void prim(){
    pq.push();
    while(tot < n && !pq.empty()){
        int minn = inf;
        vis[now] = 1;
        tot++;

        for(int i = 1; i <= n; ++i){
            if(!vis[i] && minn > dis[i]){
                minn = dis[i];
				now = i;
            }
        }
        ans += minn;
        //枚举now的所有连边，更新dis数组
        for(int i = head[now]; i; i = e[i].next){
        	int v = e[i].v;
        	if(!vis[v] && dis[v] > e[i].w){
        		dis[v] = e[i].w;
        	}
		}
    }
    printf("%d", ans);
}

int main(){
    init();
    prim();
    return 0;
}
