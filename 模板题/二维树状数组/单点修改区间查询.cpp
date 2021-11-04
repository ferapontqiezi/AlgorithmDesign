//while用for写也是一样的
void update(int x, int y, int z){
    int _y = y;
    while(x <= n){
        y = _y;
        while(y <= n)
            tree[x][y] += z, y += lowbit(y);
        x += lowbit(x);
    }
}
void query(int x, int y){
    int ans = 0, _y = y;
    while(x){
        y = _y;
        while(y)
            ans += tree[x][y], y -= lowbit(y);
        x -= lowbit(x);
    }
}
