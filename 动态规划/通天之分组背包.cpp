#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1010, N = 1010;
int n, m;
int f[M], a[N], b[N], c[1010][200], cc[1010], cn;

int main() 
{
    scanf("%d %d",&m,&n);
	for(int i = 1; i <= n; i++){
		int ccc;
		cin >> a[i] >> b[i] >> ccc;
		cn = max(cn, ccc); // cn记录有几组
		cc[ccc]++; // cc[ccc]存储第ccc组存的数据个数
		c[ccc][cc[ccc]] = i; // 第ccc组中的第几个数据是i对应数据。
	}
	for(int i = 1; i <= cn; i ++){ // 遍历cn组
		for(int j = m; j >= 0; j --){ // 枚举重量
			for(int k = 1; k <= cc[i]; k ++){ // 枚举组内所有数据
				int tmp = c[i][k];
				if(j >= a[tmp])
					f[j] = max(f[j], f[j - a[tmp]] + b[tmp]);
			}
		}
	}

	int res = f[m];

	cout << res << endl;
	return 0;
}