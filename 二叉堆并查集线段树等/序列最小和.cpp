#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
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

int a[MAXN], b[MAXN], ind[MAXN];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    for(int i = 1; i <= n; i++){
        b[i] = read();
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++){
        q.push(pair<int,int>(a[1] + b[i], i));
        ind[i] = 1;
    }

    while(n--){
        printf("%d ", q.top().first);
        int i = q.top().second;
        q.pop();
        q.push(pair<int,int>(a[++ind[i]] + b[i], i));
    }
    return 0;
}
/*
5
50 -52 81 42 -60
-31 5 26 44 12
*/
/*
-91 -83 -55 -48 -47
*/