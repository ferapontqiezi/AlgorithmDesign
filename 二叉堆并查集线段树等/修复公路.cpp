#include<cstdio>  
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 1005
#define M 70085

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

class Input{
private:
    int x;
    int y;
    int t;

public:
    Input(){}

    Input(int _x, int _y, int _t){
        x = _x;
        y = _y;
        t = _t;
    }

    bool operator < (const Input& any) const{
        return t < any.t;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getTime(){
        return t;
    }
};

int n, m;
int main(){
    //freopen("test.txt", "r", stdin);
    cin >> n >> m;
    UF uf = UF(n);
    Input in[M];
    for(int i = 1; i <= m; i++){
        int x, y, t;
        cin >> x >> y >> t;
        in[i] = Input(x, y, t);
    }
    sort(in + 1, in + m + 1);
    for(int j = 1; j <= m; j++){
        int x = in[j].getX();
        int y = in[j].getY();
        int t = in[j].getTime();
        uf.unionF(x-1, y-1);
        int count = uf.countF();
        if(count == 1){
            cout << t << endl;
            break;
        }
    }
    return 0;
}

/*
27053
*/