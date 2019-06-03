#include "stdio.h"

int z[500001],dp[500001],n,k,min,r;

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&z[i]);
	dp[n-1]=z[n-1];
	for(int i=n-1;i>0;i--)
	{
		min=1000000000;
		for(int j=(i-k<0)?0:i-k;j<i;j++)
		{
			if( dp[i]+z[j]<dp[j] || dp[j]==0 )
				dp[j] = dp[i]+z[j];
			
			if(dp[j]<min)
			{
				min=dp[j];
				r=j;
			}
		}
		i=r+1;
	}
	/*puts("");
	for(int i=0;i<n;i++)printf("%d ",dp[i]);
	*/printf("%d",dp[0]);
	return 0;
}
