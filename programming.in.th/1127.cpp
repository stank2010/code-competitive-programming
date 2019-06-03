#include "stdio.h"

int z[10000];

int main()
{
	int num[10],n,N,l=0,ls=1,min=10000001;
	
	
	scanf("%d",&n);
	N=n;	
	for(int i=1;i<=9;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]<min)
		{
			min=num[i];
			ls=i;
		}
	}
	l=n/min;
	for(int i=0;i<l;i++)
	{
		z[i]=ls;
		N-=num[ls];
	}
	
	for(int i=0;i<l;i++)
	{
		for(int j=9;j>0;j--)
		if(N+num[ls]-num[j]>=0&&j>ls)
		{
			z[i]=j;
			N=N+num[ls]-num[j];
			break;	
		}
	}
	
	for(int i=0;i<l;i++)printf("%d",z[i]);
	//for(int i=L;i<l;i++)printf("%d",ls);
	return 0;
}
