#include<cstdio>  
#include<iostream>
#include<queue>   
using namespace std;

#define MAXN 1000007

inline int read() {  //快读
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int a[MAXN], b[MAXN], dp[MAXN], n;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;

class Solution{
public:
    int nthUglyNumber(int n) { // 包含1
        int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            int num2 = 2 * dp[p2], num3 = 3 * dp[p3], num5 = 5 * dp[p5], num7 = 7 * dp[p7];
            dp[i] = min(min(num2, min(num3, num5)), num7);
            if(dp[i] == num2) p2++;
            if(dp[i] == num3) p3++;
            if(dp[i] == num5) p5++;
            if(dp[i] == num7) p7++;
        } 
        return dp[n];
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.nthUglyNumber(n);
    return 0;
}