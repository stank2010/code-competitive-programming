#include "stdio.h"

unsigned long long int T=2;
int sum;

int main()
{
	int n,k,sum=0;
	scanf("%d %d",&k,&n);
	sum+=n;
	
	for(int i=1;i<=k;i++,T*=2)
	{
		sum+=n/T;
		//printf("%d ",n/i);
	}
	printf("%d",sum);
	return 0;
}
