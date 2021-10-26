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
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++) {
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

int n, m, x, y, ans;
int main(){
    //freopen("test.txt", "r", stdin);
    while(1){
        scanf("%d%d", &n, &m);
        if(!n) return 0;
        ans = 0;
        UF uf = UF(n);
        while(m--){
            cin >> x >> y;
            uf.unionF(x, y);
        }
        ans = uf.countF() - 1;
        cout << ans << endl;
    }
    return 0;
}