#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAXN 100000

void up(int x) {
    while (x > 1 && h[x] > h[x / 2]) {
        swap(h[x], h[x / 2]);
        x /= 2;
    }
}
void down(int x) {
    while (x * 2 <= n) {
        t = x * 2;
        if (t + 1 <= n && h[t + 1] > h[t]) t++;
        if (h[t] <= h[x]) break;
        swap(h[x], h[t]);
        x = t;
    }
}



int main(){

    return 0;
}