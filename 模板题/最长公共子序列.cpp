#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAXN 3000007
int a[MAXN],b[MAXN],map[MAXN],f[MAXN];
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
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        map[a[i]] = i;
    }
	for(int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        f[i] = 0x7fffffff;
    }
	int len = 0;
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		int l = 0, r = len;
		if(map[b[i]] > f[len])
            f[++len] = map[b[i]];
		else {
            while(l < r){	
                int mid = (l + r) / 2;
                if(f[mid] > map[b[i]])
                    r = mid;
                else 
                    l = mid + 1; 
            }
            f[l] = min(map[b[i]], f[l]);
     	}
    }
    cout << len << endl;
    return 0;
}

/*
5 
3 2 1 4 5
1 2 3 4 5
*/