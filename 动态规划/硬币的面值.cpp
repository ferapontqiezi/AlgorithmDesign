#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, a[2000005], x = 0, ans = 0, pos = 0;

inline ll read(){
    ll x = 0, f = 1; char ch = ' ';
    while(ch < '0' || ch > '9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch >= '0' && ch <= '9') {x=x*10+(ch^48); ch=getchar();}
    return f == 1 ? x : -x;
}

int main() {
    n = read(), m = read();
    for(ll i = 1; i <= n; ++ i){
        a[i] = read();
    }
    a[n + 1] = m;
    sort(a + 1, a + n + 2);
    if(a[1] != 1) {
        printf("No answer!!!\n"); 
        return 0;
    }
    for(ll i = 1; i <= n; ++ i) {
		if(x < a[i + 1] - 1){
			ll k = (a[i + 1] - 2 - x) / a[i] + 1;
			x += a[i] * k;
			ans += k;
			if(x >= m){
				printf("%lld\n",ans);
				return 0;
			}
		}  
    }
    printf("%lld\n", ans + 1);      
    return 0;
}