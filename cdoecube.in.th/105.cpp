#include "stdio.h"

int z[2000001];

int main()
{
	z[1]=1;
	for(int i=2;i<2000001;i++)z[i]=(z[i-1]+z[i-2])%1000000007;
	
	int q,n,k,b,N;
	long long sum;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		sum=0;
		scanf("%d %d",&n,&k);	
		for(int j=0;j<k;j++)
		{
			scanf("%d %d",&N,&b);
			sum=(sum+(((long long)b)*((long long)z[n-N+1]))%1000000007)%1000000007;
		}
		sum=(sum+z[n])%1000000007;
		printf("%lld\n",sum);
	}
	return 0;
}
