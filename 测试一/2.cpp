//AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define maxn 400000 + 10
#define ll long long

ll L[maxn], R[maxn];
ll pos[maxn];
ll a[maxn];
int n;
 
void get_left() {
    int head = 1, tail = 0;
    for(int i = 1; i <= n; i++) {
        while(head <= tail && a[pos[tail]] >= a[i])
            tail--;
        L[i] = i - pos[tail] - 1;
        pos[++tail] = i;
    }
}
 
void get_right() {
    int head = 1, tail = 0;
    pos[0] = n + 1;
    for(int i = n; i >= 1; i--) {
        while(head <= tail && a[pos[tail]] >= a[i])
            tail--;
        R[i] = pos[tail] - i - 1;
        pos[++tail] = i;
    }
}
 
int main() {

    scanf("%d", &n);
    memset(L, 0, sizeof L), memset(R, 0, sizeof R);
    for(int i = 1; i <= n; ++ i)
        scanf("%lld", a + i);
    get_left(), get_right();

    long long ans = -1;
    for(int i = 1; i <= n; ++ i)
        ans = max(ans, (L[i] + R[i] + 1) * a[i]);
    printf("%lld\n", ans);
    return 0;
}
 
/*
6
5 8 4 4 8 4
*/