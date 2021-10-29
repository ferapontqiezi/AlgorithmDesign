#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long sum;
		scanf("%d",&n);
		sum=n*n*2-n+1;
		printf("%lld\n",sum);
	}
}