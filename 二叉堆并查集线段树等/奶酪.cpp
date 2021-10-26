#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define N 1007
#define M 62577
typedef long long ll;

class UF {
private:
    // 连通分量个数
    int count;
    // 存储一棵树
    vector<int> parent;
    // 记录树的“重量”
    vector<int> size;

public:
    UF(int n) {
        this->count = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    void unionF(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        
        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int countF() {
        return count;
    }
};

ll dist(ll x, ll y, ll z, ll x1, ll y1, ll z1){
    return (x-x1) * (x-x1) + (y-y1) * (y-y1) + (z-z1) * (z-z1);
}

ll n, h, r, x[N], y[N], z[N], ans;
int f1[N], f2[N];
int main(){
    //freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> h >> r;
        int cnt1 = 0, cnt2 = 0;
        UF uf = UF(n);
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> z[i];
            if(z[i] <= r){
                f1[cnt1] = i;
                cnt1++;
            }
            if(z[i] + r >= h){
                f2[cnt2] = i;
                cnt2++;
            }
            for(int j = 0; j < i; j ++){
                ll tmp = dist(x[j], y[j], z[j], x[i], y[i], z[i]);
                if(tmp <= 4*r*r){
                    uf.unionF(i, j);
                }
            }
        }
        ans = 0;
        for(int i = 0; i < cnt1; i++){
            for(int j = 0; j < cnt2; j ++){
                if(uf.connected(f1[i], f2[j])){
                    ans = 1;
                    break;
                }
            }
            if(ans == 1) break;
        }
        if(ans == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}