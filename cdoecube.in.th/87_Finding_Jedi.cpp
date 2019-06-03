#include "stdio.h"

unsigned long long int z[2000001];

unsigned long long int i,k=0,n,m,a;

int main()
{
	scanf("%llu %llu",&n,&m);
	
	for(i=0;i<n;i++)
	{
	scanf("%llu",&a);
	z[a]++;	
	}
	
	for(i=0;i<=m/2;i++)
	{
		if(i==m-i)
		{
			k+=(z[i]*(z[i]-1))/2;
		}
		else 
			k+=z[i]*z[m-i];	
	}
	printf("%llu",k);
	return 0;
}
