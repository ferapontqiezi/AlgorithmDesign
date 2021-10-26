#include <iostream>
using namespace std;
//滚动数组优化
int a[10005], b[10005], c[10005], d[10005], e[10005], ans[10005], f[10005];

int main() {
    int N;
    cin >> N;
    
    a[1] = 0, b[1] = 1, c[1] = 0, d[1] = 0, e[1] = 0, f[1] = 0, ans[1] = 1;
    a[2] = 1, b[2] = 1, c[2] = 1, d[2] = 1, e[2] = 0, f[2] = 0, ans[2] = 5;
    a[3] = 1, b[3] = 5, c[3] = 1, d[3] = 1, e[3] = 1, f[3] = 1, ans[3] = 11;

    for (int i = 4; i <= N; i++) {
        a[i] = ans[i - 2] % 997;
        b[i] = ans[i - 1] % 997;
        c[i] = (ans[i - 2] + e[i - 1]) % 997;
        d[i] = ans[i - 2] % 997;
        e[i] = (e[i - 2] + ans[i - 3]) % 997;
        f[i] = (ans[i - 3] + f[i - 1]) % 997;
        ans[i] = (a[i] + b[i] + c[i] + 2 * d[i] + f[i] * 2) % 997;
    }
    cout << ans[N] % 997;
    return 0;
}