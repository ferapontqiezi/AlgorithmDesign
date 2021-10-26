#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define N 30007
typedef long long ll;

inline int read(){
    int res = 0, flag = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') flag = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        res = res * 10 + c -'0';
        c = getchar();
    }
    return res * flag;
}

class UF {
private:
    // 连通分量个数
    int count;
    // 存储一棵树
    vector<int> parent;
    // dist[]维护编号为i的战舰到parent[i]之间的距离
    vector<int> dist;
    // nums[]维护编号为i的战舰所在的那一列有多少战舰
    vector<int> nums;

public:
    UF(int n) {
        this->count = n;
        parent.resize(n + 1);
        dist.resize(n + 1);
        nums.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            dist[i] = 0;
            nums[i] = 1;
        }
    }

    int find(int x) {
        if(x != parent[x]){
            int k = parent[x];
            parent[x] = find(parent[x]);
            dist[x] += dist[k];
            nums[x] = nums[parent[x]];
        }
        return parent[x];
    }

    void merge(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return ;
        
        parent[rootP] = rootQ;
        dist[rootP] = dist[rootQ] + nums[rootQ];
        nums[rootQ] += nums[rootP];
        nums[rootP] = nums[rootQ];

        count--;
    }

    int query(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP != rootQ){
            return -1;
        } else {
            return abs(dist[p] - dist[q]) - 1;
        }
    }

    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int countF() {
        return count;
    }
};

int t, x, y;
int main(){
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> t;
    UF uf = UF(N);
    while(t--){
        char f;
        cin >> f;
        x = read(), y = read();
        if(f == 'M') uf.merge(x, y);
        else cout << uf.query(x, y) <<endl;
    }
    return 0;
}