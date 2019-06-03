#include "stdio.h"

int z[1000001];

unsigned long long int sum,dp[1000000];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&z[i]);
	dp[1]=z[1];
	for(int i=1;i<n-1;i++)
	{
		if(dp[i+1]==0||dp[i]+z[i]+z[1]<dp[i+1]) //go (z[i],z[1])
		{	
			dp[i+1]=dp[i]+z[i+1]+z[0];
		}
		
		if(dp[i+2]==0||dp[i]+2*z[2]+z[1]+z[i+1]<dp[i+2]) // go (z[i+1],z[i]) back z[2] go (z[1],z[2])
		{
			dp[i+2]=dp[i]+2*z[2]+z[1]+z[i+1];
		}
	}
	
	printf("%llu",dp[n-1]);
	return 0;
}
