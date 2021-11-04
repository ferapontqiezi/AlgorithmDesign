void update(int x, int y, int val) {
	for (int X = x; X <= n; X += lowbit(X))
		for (int Y = y; Y <= m; Y += lowbit(Y)) {
			t1[X][Y] += val;
			t2[X][Y] += val *x;
			t3[X][Y] += val * y;
			t4[X][Y] += val * x * y;
		}
}
void range_update(int xa, int ya, int xb, int yb, int val) { 
	update(xa, ya, val);
	update(xa, yb + 1, -val);
	update(xb + 1, ya, -val);
	update(xb + 1, yb + 1, val);
}
int query(int x, int y) {
	int res = 0;
	for (int i = x; i; i -= i & -i)
		for (int j = y; j; j -= j & -j)
			res += (x + 1) * (y + 1) * t1[i][j]
			- (y + 1) * t2[i][j]
			- (x + 1) * t3[i][j]
			+ t4[i][j];
	return res;
}
int range_query(int xa, int ya, int xb, int yb) {
	return query(xb, yb) - query(xb, ya - 1) - query(xa - 1, yb) + query(xa - 1, ya - 1);
}