// 扫描线法
#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 4000007

inline int read() {  //快读
    char c = getchar();
    int x = 0, f = 1;
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

class Answer{ //答案
public:
    int x, y;
    bool operator < (const Answer& a) const{
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
}ans[MAXN];
int acnt = 0;

class Node{ //定义线段树的结点
public:
    int l, r; //节点所维护的区间
    int cnt; //这个区间被完全覆盖的次数
    int len; //这个区间被覆盖的长度
};

class Sugment{ //定义一条线段
public: 
    int r; //线段的高度
    int x; //横坐标
    int k; //线段权值
    bool operator < (const Sugment& a) const{
        return x < a.x;
    }
}sug[MAXN];
int scnt = 0;

int pos[MAXN], pcnt = 0;

class SugmentTree{ //线段树
public:
    Node d[MAXN<<2];
    int getLen(int l, int r, int k){ //更新得到线段的长度
        if(d[k].cnt) return pos[r+1] - pos[l];
        if(l == r) return 0;
        return d[k<<1].len + d[k<<1|1].len;
    }
    void modify(int l ,int r, int k, int s, int t, int x){
        if(s <= l && r <= t){
            d[k].cnt += x;
            d[k].len = getLen(l, r, k);
            return ;
        }
        int m = (l + r) >> 1;
        if(s <= m) modify(l, m, k<<1, s, t, x);
        if(m < t) modify(m+1, r, k<<1|1, s, t, x);
        d[k].len = getLen(l, r, k);
    }
}sgt;

void SugmentCover(int i){ //线段覆盖
    int l = 1;
    int r = lower_bound(pos + 1, pos + pcnt + 1, sug[i].r) - pos - 1; //查找离散化之后的值
    sgt.modify(1, pcnt, 1, l, r, sug[i].k);
}

int main() {
    //freopen("test.txt", "r", stdin);

    int n = 0;
    int x, y, z;
    while(~scanf("%d%d%d", &x, &y, &z)){
        n++;
        sug[scnt+1].r = y; sug[scnt+1].x = x; sug[scnt+1].k = 1; //保存成两条线段
        sug[scnt+2].r = y; sug[scnt+2].x = z; sug[scnt+2].k = -1;
        scnt += 2;
        pos[n] = y;
    }
    pos[++n] = 0;

    sort(sug+1, sug+scnt+1);
    sort(pos+1, pos+n+1);
    pcnt = 1;
    for(int i = 2; i <= n; i++) {
        if(pos[i] != pos[i-1]){
            pos[++pcnt] = pos[i];
        }
    }

    int prvh = 0;
    for(int i = 1; i <= scnt; i++){
        while(sug[i].x == sug[i+1].x && i < scnt) //把横坐标相同的全部覆盖
            SugmentCover(i), i++;
        SugmentCover(i);
        if(sgt.d[1].len != prvh){ //出现了拐点
            ans[++acnt].x = sug[i].x; //记录答案,其实可以直接输出
            ans[acnt].y = prvh;
            prvh = sgt.d[1].len;
            ans[++acnt].x = sug[i].x;
            ans[acnt].y = prvh;
        }
    }

    for(int i = 1; i <= acnt; i++){
        if(i & 1) printf("%d ", ans[i].x);
        else printf("%d ", ans[i].y);
    }

    return 0;
}

/*in
1 11 5
2 6 7
3 13 9
12 7 16
14 3 25
19 18 22
23 13 29
24 4 28
*/
/*out
1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0
*/