#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;

#define MAXN 3000007

int a[MAXN], res[MAXN];
stack<int> s;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i >= 1; i--){
        while(!s.empty() && a[i] >= a[s.top()]) s.pop();
        res[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}