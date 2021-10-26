#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define N 257
#define M 62577

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

struct{
    int girl, boy;
}a[M];
bool flags[N][N];
int n, m, k, f, nums[N];
int main(){
    //freopen("test.txt", "r", stdin);
    cin >> n >> m >> k >> f;
    UF uf = UF(n);
    for(int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        a[i].girl = x - 1; 
        a[i].boy = y - 1;
    }
    while(f--){
        int x, y;
        cin >> x >> y;
        uf.unionF(x-1, y-1);
    }
    for(int i = 1; i <= m; i++){
        if(!flags[uf.find(a[i].girl)][a[i].boy]){
            flags[uf.find(a[i].girl)][a[i].boy] = true;
            nums[uf.find(a[i].girl)]++;
        }
    }
    int ans = 7777777;
    for(int i = 1; i <= n; i ++){
        if(nums[i])
            ans = min(ans, nums[i]);
    }
    ans = min(ans + k, n);
    cout << ans << endl;
    return 0;
}