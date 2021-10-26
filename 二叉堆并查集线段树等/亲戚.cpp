#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 5005

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

int n, m, p;
int main(){
    //freopen("test.txt", "r", stdin);
    cin >> n >> m >> p;
    UF uf = UF(n);
    while(m--){
        int x, y;
        cin >> x >> y;
        uf.unionF(x-1, y-1);
    }
    while(p--){
        int x, y;
        cin >> x >> y;
        bool ans = uf.connected(x-1, y-1);
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}