#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

inline ll read() {
    int res = 0, flag = 1;
    char c = getchar();
    if (c == '-') {
        flag = -1;
        c = getchar();
    }
    while (c != ' ' && c != '\n') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * flag;
}

template<typename T, class Lz>
struct SegTree {
    /**
     * 线段树模板
     * Author: fy
     * C++ Standard: C++11  如果你是C98，则需要修改构造函数
     * 使用：
     *  1. 定义合并逻辑
     *      1.1 线段树内的区间合并 add
     *      1.2 线段树与懒标记的合并 addt
     *      1.3 懒标记与懒标记的合并 addtt
     *      1.4 懒标记的零状态 ZERO
     *  2. 定义
     *      2.1 第一个类型 T 是线段树内的类型, 第二个类型 Lz 是懒标记的类型，两者都可以自定义struct
     *          第一个参数是传入要维护的数组， 第二个，第三参数是要维护的区间范围 [left, right]
     *          第四，第五个，第六个参数分别是 add, addt, addtt函数，表示线段树内部聚合， 线段树与懒标记聚合，懒标记与懒标记聚合
     *          第七个参数是懒标记的零状态
     *          Seg<T,Lz> seg(A, left, right, &add, &addt, &addtt, 0);
     *      2.2 默认是区间求和, A是要维护的数组, 后面几个函数均是区间求和的函数
     *          Seg<int ,int> seg(A);
     *  3. 操作
     *      3.1 区间修改  [x, y] 值以懒标记的方式传递
     *          update(x, y, tag);
     *      3.2 区间查询 [x, y] , 返回查询的结构，类型 T
     *          query(x, y) 
     *      3.3 单点修改 x
     *          insert(x, val)
     */ 
    #define M ((L+R)>>1)
    #define lson (o<<1)
    #define rson (o<<1|1)

    vector<T> sumv; // 维护的值
    vector<Lz> tag; // 懒标记
    int LEFT, RIGHT;  // 维护的区间范围

    // 四种操作
    T (*add)(T, T); // 线段树内部聚合
    T (*addt)(T, Lz, int, int); // 线段树与懒标记聚合
    Lz (*addtt) (Lz, Lz); // 懒标记与懒标记聚合
    Lz ZERO; // 懒标记的零状态

    SegTree(vector<T> &arr, int left=1, int right=-1, 
            T (*fadd)(T,T) = [](T a,T b) { return a + b; }, 
            T (*faddt)(T, Lz, int, int) = [](T a, Lz b, int l, int r) { return a + b*(r-l+1); },
            Lz (*faddtt)(Lz, Lz) = [](Lz a, Lz b) { return a + b; },
            Lz zero = 0) { 
        if (right == -1) RIGHT = arr.size()-1;
        else RIGHT = right; 
        LEFT = left;  
        sumv = vector<T>(RIGHT<<2);
        tag = vector<Lz>(RIGHT<<2);
        add = fadd;
        addt = faddt;
        addtt = faddtt;
        ZERO = zero;
        build(arr, 1, LEFT, RIGHT);
    }

    inline void build(vector<T> &A, int o=1, int L=1, int R=-1) {
        if (R == -1) {L = LEFT; R = RIGHT;}
        tag[o] = ZERO; // 初始化懒标记
        if (L == R) sumv[o] = A[L];
        else {
            build(A, lson, L, M);
            build(A, rson, M+1, R);
            sumv[o] = add(sumv[lson], sumv[rson]);
        }
    }
    
    inline void pushdown(int o, int L, int R) {
        if (L == R || tag[o] == ZERO) return;
        sumv[lson] = addt(sumv[lson], tag[o], L, M);
        sumv[rson] = addt(sumv[rson], tag[o], M+1, R);
        tag[lson] = addtt(tag[lson], tag[o]);
        tag[rson] = addtt(tag[rson], tag[o]);
        tag[o] = ZERO; 
    }

    inline void insert(int x, Lz val, int o=1, int L=1, int R=-1) {
        if (R == -1) {L = LEFT; R = RIGHT;}
        if (L == R) sumv[o] = addt(sumv[o], val, L, R);
        else {
            pushdown(o, L, R);
            if (x <= M) insert(x, val, lson, L, M);
            else insert(x, val, rson, M+1, R);
            sumv[o] = add(sumv[lson], sumv[rson]);
        }
    }

    inline void update(int x, int y, Lz val, int o=1, int L=1, int R=-1) {
        if (R == -1) {L = LEFT; R = RIGHT;}
        if (x <= L && R <= y) sumv[o] = addt(sumv[o], val, L, R), tag[o] = addtt(tag[o], val);
        else {
            pushdown(o, L, R);
            if (x <= M) update(x, y, val, lson, L, M);
            if (y > M) update(x, y, val, rson, M+1, R);
            sumv[o] = add(sumv[lson], sumv[rson]); 
        }
    }

    inline T query(int x, int y, int o=1, int L=1, int R=-1) {
        if (R == -1) {L = LEFT; R = RIGHT;}
        pushdown(o, L, R);
        if (x <= L && R <= y) return sumv[o];
        else if (x <= M && y > M) return add(query(x, M, lson, L, M), query(M+1, y, rson, M+1, R));
        else if (x <= M)  return query(x, y, lson, L, M);
        else return query(x, y, rson, M+1, R); 
    }
};

ll n, m, MOD;

inline int add(int a, int b) { // 定义线段树内聚合，同时也是定义加法取模函数
    return (((ll)a + b) % MOD + MOD) % MOD;
}
inline int mul(int a, int b) { // 定义乘法，方便取模
    return (((ll)a * b) % MOD + MOD) % MOD;
}

inline int addt(int a, pair<int,int> lz, int l, int r) { // 定义线段树与懒标记聚合
    return add(mul(a,lz.first), mul(lz.second,(r-l+1)));
}

pair<int,int> addtt(pair<int,int> a, pair<int,int> b) { // 定义懒标记与懒标记聚合
    return {mul(a.first,b.first), add(mul(a.second,b.first), b.second)};
}

int main() {
    //freopen("../1111/1.in","r",stdin);
    //freopen("../1111/1.txt","w",stdout);
    n = read(), m = read(), MOD = read();
    vector<int> A(n+1);
    for (int i = 1;i <= n; ++i) {
        A[i] = read();
    }
    SegTree<int,pair<int,int>> seg(A, 1, n, &add, &addt, &addtt, {1, 0});
    for (int i = 1; i <= m; ++i) {
        int op, x, y, z;
        op = read();
        if (op == 1) {
            x = read(), y = read(), z = read();
            seg.update(x, y, {z, 0});
        } else if (op == 2) {
            x = read(), y = read(), z = read();
            seg.update(x, y, {1, z});
        } else {
            x = read(), y = read();
            cout << seg.query(x, y) << endl;
        }
    }
    return 0;
}