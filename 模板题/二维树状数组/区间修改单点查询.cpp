//类似于一维的处理，可以设差分数组 d[i]=a[i][j]-a[i-1][j]+a[i][j-1]-a[i-1][j-1]

//变量名“y1”在<cmath>库里头有定义，会冲突，所以不开bits库就好。
//用万能头的选手不要使用x1,y1
void update(int x, int y, int z){ 
    int _y = y;
    while(x <= n){
        y = _y;
        while(y <= n)
            tree[x][y] += z, y += y & -y;
        x += x & -x;
    }
}
void range_update(int x1, int y1, int x2, int y2, int val){
    update(x1, y1, val);
    update(x1, y2 + 1, -val);
    update(x2 + 1, y1, -val);
    update(x2 + 1, y2 + 1, val);
}
void ask(int x, int y){
    int ans = 0, _y = y;
    while(x){
        y = _y;
        while(y)
            ans += tree[x][y], y -= lowbit(y);
        x -= lowbit(x);
    }
}