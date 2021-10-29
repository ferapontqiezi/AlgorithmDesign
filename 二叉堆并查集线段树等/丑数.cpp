#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <vector>
using namespace std;

#define M 100007
#define N 1000007
#define PRIME_MAX 1299709
#define MAX 1299800

bool isPrime[MAX];
//isPrime[i] == 1表示：i是素数
long long Prime[M], cnt = 0;
//Prime存质数

void GetPrime(int n)/*筛到n*/{
	memset(isPrime, 1, sizeof(isPrime));
	//以“每个数都是素数”为初始状态，逐个删去
	isPrime[1] = 0;//1不是素数
	
	for(int i = 2; i <= n; i++){
		if(isPrime[i])//没筛掉 
			Prime[++cnt] = i; //i成为下一个素数
			
		for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++) {
        	//从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
			isPrime[i*Prime[j]] = 0;
            
			if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
				break; //重要步骤。见原理
		}
	}
}

class Element{
public:
    int k; // 第k个素数
    long long v; // value值
    Element(){}
    Element(int _k, long long _v){
        k = _k;
        v = _v;
    }
    bool operator < (const Element& any) const{
        return v > any.v;
    }
};

long long ans[N];
priority_queue<Element> q;
int main() {
    //freopen("../test.txt", "w", stdout);
	int m, n;
	scanf("%d %d", &m, &n);
	GetPrime(MAX);

/*     if(Prime[m] > n){
        for (int i = 2; i <= n + 1; i++) {
            printf("%d ",i);
        }
        return 0;
    } */

    q.push(Element(1, Prime[1]));
    while(n--) {
        int kth = q.top().k;
        long long value = q.top().v;
        printf("%lld ", value);
        q.push(Element(kth, value * Prime[kth]));
        if(kth < m) {          
            long long nextVal = value / Prime[kth] * Prime[kth + 1];
            q.push(Element(kth + 1, nextVal));
        }
        q.pop();
    }
	return 0;
}