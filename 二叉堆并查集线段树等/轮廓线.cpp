// 优先队列法
#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define MAXN 1000007

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

class Buildings { //定义一个建筑
public:
    int h; //线段的高度
    int r; //右端横坐标
    Buildings(int h, int r) { //构造器
        this->h = h;
        this->r = r;
    }
    bool operator < (const Buildings& a) const { //重载运算符，方便sort()
        return h < a.h;
    }
};

class Node { //定义一个端点
public:
    int i; //端点序号
    int x; //横坐标
    bool f; //f=0表示左端点，f=1表示右端点
    Node() {}
    Node(int i, int x, bool f) { //构造器
        this->i = i;
        this->x = x;
        this->f = f;
    }
}b[MAXN * 2];

inline bool cmp(Node& p, Node& q) {
    return p.x < q.x;
}

int n, a[MAXN][3];
priority_queue<Buildings> q;

int main() {
    //freopen("test.txt", "r", stdin);

    int l, h, r;
    while (~scanf("%d%d%d", &l, &h, &r)) {
        n++;
        a[n][0] = l, a[n][1] = h, a[n][2] = r;
        b[2 * n - 1] = Node(n, l, 0);
        b[2 * n] = Node(n, r, 1);
    }

    sort(b + 1, b + 2 * n + 1, cmp);

    int last = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (!q.empty()) { //这一段时判断堆顶是否过时
            r = (q.top()).r;
            while (!q.empty() && b[i].x >= r) {
                q.pop();
                if (q.empty()) break;
                r = (q.top()).r;
            }
        }
        if (!b[i].f) {
            Buildings bt = Buildings(a[b[i].i][1], a[b[i].i][2]);
            q.push(bt);
        }
        if (i < 2 * n && b[i].x == b[i + 1].x) {
            continue;
        }
        if (q.size()) h = (q.top()).h;
        else h = 0; //堆空高度为0
        if (h != last) { //高度变化则输出
            printf("%d %d ", b[i].x, h);
            last = h;
        }
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
// 61815 99040 78976 683907 137584 729590 185508 939788 432307 853096 497952 912972 820621 0 